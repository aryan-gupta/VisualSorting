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

#include ".\inc\main.h"
#include ".\inc\Window.h"

const int SCRN_W = 854;
const int SCRN_H = 480;
const int PAD    = 10;

const int DELAY = 50;

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

void Window::render() {
	clear();
	
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Rect box{
		PAD, 
		0,
		(SCRN_W - 2*PAD) / testVec.size(), 
		0
	}; // renders a solid green background
	
	for(auto i = testVec.begin(); i < testVec.end(); ++i) {
		int size = SCRN_H * (*i)/MAX_ELEM;
		box.y = SCRN_H - size;
		box.h = size;
		
		SDL_RenderFillRect(renderer, &box);
		
		box.x += box.w;
	}
	
	SDL_RenderPresent(renderer);
	
	SDL_Delay(DELAY);
}

void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black
	SDL_RenderClear(renderer);
}