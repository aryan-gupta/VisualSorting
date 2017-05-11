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
#define PRINT_LEGAL_TERR std::cout << '\n' << R_PROJNAME << " v" << R_PVERSION \
		<< " by " << R_AUTHOR << '\n' << R_COPYRIGHT << '\n' << R_COMMENTS \
		<< "\n\n\n" // Legal and Informational


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

#include "main.h"
#include "Window.h"

#include ".\InsertionSort.h"
#include ".\QuickSort.h"
#include ".\SelectionSort.h"
#include ".\BubbleSort.h"
#include ".\GnomeSort.h"
#include ".\StoogleSort.h"
#include ".\RadixSort.h"
#include ".\BitonicSort.h"
#include ".\CockTailSort.h"
#include ".\ShellSort.h"
#include ".\HeapSort.h"
#include ".\MergeSort.h"
#include ".\BogoSort.h"
#include ".\IntroSort.h"
#include ".\CombSort.h"
#include ".\CycleSort.h"
#include ".\OddEvenSort.h"

int MAX_ELEM = 1024;// 1024, 512, 341. 256, 204, 128, 

std::vector<int> testVec;

Window* gWindow;

int main(int argc, char* argv[]) {
	PRINT_LEGAL_TERR;
	srand(time(0));

	while(true) {
		int choice = Window::askSort();
		
		gWindow = new Window();
		switch(choice) {
			case 0: MAX_ELEM = 128;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::InsertionSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 1: MAX_ELEM = 1024;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::QuickSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 2: MAX_ELEM = 128;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::SelectionSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 3: MAX_ELEM = 128;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::BubbleSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 4: MAX_ELEM = 128;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::GnomeSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 5: MAX_ELEM = 114;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::StoogleSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 6: MAX_ELEM = 1024;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::RadixSort_LSD(testVec.begin(), testVec.end());
			break;
			
			case 7: MAX_ELEM = 256;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::RadixSort_MSD(testVec.begin(), testVec.end());
			break;

			case 8: MAX_ELEM = 512;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::BitonicSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 9: MAX_ELEM = 64;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::CockTailSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 10: MAX_ELEM = 512;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::ShellSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 11: MAX_ELEM = 1024;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::HeapSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 12: MAX_ELEM = 1024;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::MergeSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;

			case 13: MAX_ELEM = 6;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::BogoSort(testVec.begin(), testVec.end());
			break;
			
			case 14: MAX_ELEM = 1024;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::IntroSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
			break;
			
			case 15: MAX_ELEM = 512;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::CombSort(testVec.begin(), testVec.end());
			break;
			
			case 16: MAX_ELEM = 128;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::CycleSort(testVec.begin(), testVec.end());
			break;
			
			case 17: MAX_ELEM = 128;
				for(int i = 0; i < MAX_ELEM; ++i)
					testVec.push_back(i);
				std::random_shuffle(testVec.begin(), testVec.end());
				SortAlgVis::OddEvenSort(testVec.begin(), testVec.end());
			break;
			
			default:
				std::cout << "Sorry, That is a Wrong Choice" << std::endl;
			break;
		}
		
		SDL_Event event;
		bool quit = false;
		while(!quit) {
			while(SDL_PollEvent(&event)) {
				switch(event.type) {
					case SDL_QUIT:
						testVec.clear();
						delete gWindow;
						quit = true;
					break;
				}
			}
		}
	}
	
	return 0;
}