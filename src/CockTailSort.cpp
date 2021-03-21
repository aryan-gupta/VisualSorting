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

#include ".\inc\main.h"

namespace SortAlg {
	template <typename ITER, typename FUNC>
	void CockTailSort(ITER start, ITER end, FUNC cmp) {
		bool sorted; // is the list sorted
		do {
			sorted = true; // assume that array is sorted
			for(ITER idx = start; idx < end - 2; ++idx) { // go through the array except last
				if(!cmp(*(idx), *(idx + 1))) {    // if the value and the next value is out of order
					std::iter_swap(idx, idx + 1); // swap them 
					sorted = false; // and set sorted to false;
				}
			}
			if(sorted)
				break;
			sorted = true; // assume that array is sorted
			for(ITER idx = end - 2; idx >= start; --idx) { // go through the array except last
				if(!cmp(*(idx), *(idx + 1))) {    // if the value and the next value is out of order
					std::iter_swap(idx, idx + 1); // swap them 
					sorted = false; // and set sorted to false;
				}
			}
		} while(!sorted); // repeat until the list is sorted
	}
}


namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	void CockTailSort(ITER start, ITER end, FUNC cmp) {
		bool sorted; // is the list sorted
		do {
			sorted = true; // assume that array is sorted
			for(ITER idx = start; idx < end - 2; ++idx) { // go through the array except last
				::gWindow->render({idx, idx + 1});
				if(!cmp(*(idx), *(idx + 1))) {    // if the value and the next value is out of order
					std::iter_swap(idx, idx + 1); // swap them 
					::gWindow->render({idx, idx + 1});
					sorted = false; // and set sorted to false;
				}
				::gWindow->render({idx, idx + 1});
			}
			if(sorted)
				break;
			sorted = true; // assume that array is sorted
			for(ITER idx = end - 2; idx >= start; --idx) { // go through the array except last
				::gWindow->render({idx, idx + 1});
				if(!cmp(*(idx), *(idx + 1))) {    // if the value and the next value is out of order
					std::iter_swap(idx, idx + 1); // swap them 
					::gWindow->render({idx, idx + 1});
					sorted = false; // and set sorted to false;
				}
				::gWindow->render({idx, idx + 1});
			}
		} while(!sorted); // repeat until the list is sorted
	}
}