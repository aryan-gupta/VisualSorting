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

#include "main.h"
#include "Window.h"

const int SCRN_W = 1044;
const int SCRN_H = 620;
const int PAD    = 10;

const int DELAY = 0;

Window::Window() {
	if( NULL ==
		(window = SDL_CreateWindow(  // Create our Window
			R_PRGMNAME,  // Window name
			SDL_WINDOWPOS_UNDEFINED,  // Window position (x)
			SDL_WINDOWPOS_UNDEFINED,  // Window position (y)
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
}


Window::~Window() {
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
		} else if(colors.size() > 1 && i == colors[1]) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
			SDL_RenderFillRect(renderer, &box);
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
		 << "7.  Radix MSD Sort <- Not Working" << endl
		 << "8.  Bitonic Sort" << endl
		 << "9.  CockTail Sort" << endl
		 << "10. Shell Sort" << endl
		 << "11. Heap Sort" << endl
		 << "12. Merge Sort" << endl
		 << "13. Bogo Sort" << endl
		 << endl;
		 
	int c;
	std::cin >> c;
	return c;
}