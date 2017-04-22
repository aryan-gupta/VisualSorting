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

#include <algorithm>

namespace SortAlg {
template <typename ITER, typename FUNC>
void InsertionSort(ITER start, ITER end, FUNC cmp) {
	for(ITER srt = start + 1; srt != end; srt++) { // go through the entire array
		ITER pntr = srt; // pick the first element
		while(pntr > start && cmp(*(pntr), *(pntr - 1))) { // Until the element is in the right place or we are at the beginning
			std::iter_swap(pntr, pntr - 1); // keep moving the element back
			pntr--; // after we swap we want to update the pointer
		}
	}
}
}

namespace SortAlgVis {
template <typename ITER, typename FUNC>
void InsertionSort(ITER start, ITER end, FUNC cmp) {
	::gWindow->render();
	for(ITER srt = start + 1; srt != end; srt++) { // go through the entire array
		::gWindow->render();
		ITER pntr = srt; // pick the first element
		while(pntr > start && cmp(*(pntr), *(pntr - 1))) { // Until the element is in the right place or we are at the beginning
			::gWindow->render();
			std::iter_swap(pntr, pntr - 1); // keep moving the element back
			::gWindow->render();
			pntr--; // after we swap we want to update the pointer
			::gWindow->render();
		}
		::gWindow->render();
	}
}

}