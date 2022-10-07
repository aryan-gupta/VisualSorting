/* 
 * Copyright (c) 2017 The Gupta Empire - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Aryan Gupta <me@theguptaempire.net>
 * 
 * =============================================================================
 * @author 			Aryan Gupta
 * @project 		
 * @title 			
 * @date			(YYYY-MM-DD)
 * @fversion		1.0.0
 * @description 	
 * =============================================================================
 */
#include "info.h"

#include <vector>
#include <iostream>
#include <SDL.h>
#include <SDL_audio.h>

#include "main.h"
#include "Window.h"

const int SCRN_W = 1920;
const int SCRN_H = 1080;
const int PAD    = 10;

const int DELAY = 0100;

const int AMPLITUDE = 28000;
const int SAMPLE_RATE = 44100;
volatile float freq = 440.0f;

void audio_callback(void *user_data, Uint8 *raw_buffer, int bytes)
{
    static float current_freq = 440.0f;
	static int wait_for_fin = 0;

	Sint16 *buffer = (Sint16*)raw_buffer;
    int length = bytes / 2; // 2 bytes per sample for AUDIO_S16SYS
    int &sample_nr(*(int*)user_data);

    for(int i = 0; i < length; i++, sample_nr++)
    {
        double time = (double)sample_nr / (double)SAMPLE_RATE;
		Sint16 cur = (Sint16)(AMPLITUDE * sin(2.0f * M_PI * current_freq * time));

		if (wait_for_fin == 0 and current_freq != freq) {
			if (cur > 0)
				wait_for_fin = 1;
			else
				wait_for_fin = 2;
		}

		if (
			(wait_for_fin == 1 and cur < 0) or
			(wait_for_fin == 2 and cur > 0)
		) {
			current_freq = freq;
			wait_for_fin = 0;
			sample_nr = 1;

			// add some silence
			for (int j = 0; j < 512 and i < length; ++i, ++j) {
				buffer[i] = 0;
			}
		} else {
        	buffer[i] = cur; // render 441 HZ sine wave
		}

    }
}

Window::Window() {
	if( NULL ==
		(window = SDL_CreateWindow(  // Create our Window
			R_PRGMNAME,  // Window name
			50,  // Window position (x)
			50,  // Window position (y)
			SCRN_W, SCRN_H,  // Screen size
			SDL_WINDOW_SHOWN //| SDL_WINDOW_INPUT_GRABBED // | SDL_WINDOW_FULLSCREEN // Window flags
		))
	) EXIT("SDL Create Window Failed! " << SDL_GetError(), -0x102);
	
	if( NULL ==
		(renderer = SDL_CreateRenderer( // Create our main renderer
			window, -1,
			SDL_RENDERER_ACCELERATED // Renderer flags
		))
	) EXIT("SDL Create Renderer Failed! " << SDL_GetError(), -0x102);
	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	// if(SDL_Init(SDL_INIT_AUDIO) != 0) SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
	// beeper = new Beeper();

	if(SDL_Init(SDL_INIT_AUDIO) != 0) SDL_Log("Failed to initialize SDL: %s", SDL_GetError());

    int sample_nr = 0;

    SDL_AudioSpec want;
    want.freq = SAMPLE_RATE; // number of samples per second
    want.format = AUDIO_S16SYS; // sample type (here: signed short i.e. 16 bit)
    want.channels = 1; // only one channel
    want.samples = 4096; // buffer-size
    want.callback = audio_callback; // function SDL calls periodically to refill the buffer
    want.userdata = &sample_nr; // counter, keeping track of current sample number

    SDL_AudioSpec have;
    if(SDL_OpenAudio(&want, &have) != 0) SDL_LogError(SDL_LOG_CATEGORY_AUDIO, "Failed to open audio: %s", SDL_GetError());
    if(want.format != have.format) SDL_LogError(SDL_LOG_CATEGORY_AUDIO, "Failed to get the desired AudioSpec");

    SDL_PauseAudio(0); // start playing sound
}


Window::~Window() {
	SDL_PauseAudio(1); // stop playing sound

    SDL_CloseAudio();

	SDL_DestroyRenderer(renderer); // Destroy our main renderer
	SDL_DestroyWindow(window);     // Destroy our main window
}

void Window::render(const std::vector<std::vector<int>::iterator>& colors, int delay) {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				exit(0);
			break;
		}
	}
	
	clear();
	
	SDL_Rect box{
		PAD, 
		0,
		SCRN_W / (int)testVec.size(), 
		0
	};
	
	for(auto i = testVec.begin(); i < testVec.end(); ++i) {
		int size = SCRN_H * (*i)/MAX_ELEM;
		box.y = SCRN_H - size;
		box.h = size;
		
		if       (colors.size() > 0 && i == colors[0]) {
			SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
			SDL_RenderFillRect(renderer, &box);
			SDL_LockAudio();
			freq = 1000.0f + size;
			SDL_UnlockAudio();
		} else if(colors.size() > 1 && i == colors[1]) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
			SDL_RenderFillRect(renderer, &box);
			// beeper->beep(1000.0f, 1);
		} else if(colors.size() > 2 && i == colors[2]) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
			SDL_RenderFillRect(renderer, &box);
		} else {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderFillRect(renderer, &box);
		}
		
		box.x += box.w;
	}
	
	SDL_RenderPresent(renderer);
	
	SDL_Delay(delay);
}

void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black
	SDL_RenderClear(renderer);
}


int Window::askSort() {
	using std::endl; using std::cout;
	cout << "Please Pick a Sort: " << endl
		 << "0.  Insertion Sort" << endl
		 << "1.  QuickSort Sort" << endl
		 << "2.  Selection Sort" << endl
		 << "3.  Bubble Sort" << endl
		 << "4.  Gnome Sort" << endl
		 << "5.  Stoogle Sort" << endl
		 << "6.  Radix LSD Sort" << endl
		 << "7.  Radix MSD Sort" << endl
		 << "8.  Bitonic Sort" << endl
		 << "9.  CockTail Sort" << endl
		 << "10. Shell Sort" << endl
		 << endl;
		 
	int c;
	std::cin >> c;
	return c;
}