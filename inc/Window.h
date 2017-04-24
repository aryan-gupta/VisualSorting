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

#ifndef WINDOW_H_INC
#define WINDOW_H_INC

#include <SDL.h>

extern const int SCRN_H;
extern const int SCRN_W;
extern const int PAD;
extern const int DELAY;

class Window {
public:
	Window();
	~Window();
	
	void render(const std::vector<std::vector<int>::iterator>& colors = {}, int delay = DELAY);
	
	static int askSort();
	
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	void clear();
	
};


#endif // WINDOW_H_INC