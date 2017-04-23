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

#include ".\inc\main.h"
#include ".\inc\Window.h"

#include ".\InsertionSort.cpp"
#include ".\QuickSort.cpp"
#include ".\SelectionSort.cpp"
#include ".\BubbleSort.cpp"

int MAX_ELEM = 80;// 400, 267, 200, 160, 133, 114, 100, 89, 80;

std::vector<int> testVec;

Window* gWindow;

int main(int argc, char* argv[]) {
	PRINT_LEGAL_TERR;
	srand(time(0));
	
	//gWindow = new Window();
	
	for(int i = 0; i < MAX_ELEM; ++i)
		testVec.push_back(i);
	
	// std::random_shuffle(testVec.begin(), testVec.end());
	// printPretty(testVec);
	
	// SortAlg::BubbleSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
	
	// printPretty(testVec);
	
	//std::random_shuffle(testVec.begin(), testVec.end());
	//SortAlgVis::InsertionSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
	
	//std::random_shuffle(testVec.begin(), testVec.end());
	//SortAlgVis::QuickSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
	
	//std::random_shuffle(testVec.begin(), testVec.end());
	//SortAlgVis::SelectionSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
	
	std::random_shuffle(testVec.begin(), testVec.end());
	SortAlgVis::BubbleSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
	
	
	
	SDL_Event event;
	while(true) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					exit(0);
				break;
			}
		}
	}
	
	return 0;
}

template<class TYPE>
void printPretty(std::vector<TYPE>& vec) {
	using std::cout; using std::endl;
	
	cout << endl;
	for(TYPE& t : vec) {
		cout << t << " ";
	}
	cout << endl;
}