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
	
	// =================== NON COMPARE FUNC ====================================
	
	template <typename ITER>
	void InsertionSort(ITER start, ITER end) {
		for(ITER srt = start + 1; srt != end; srt++) { // go through the entire array
			ITER pntr = srt; // pick the first element
			while(pntr > start && *(pntr) < *(pntr - 1)) { // Until the element is in the right place or we are at the beginning
				std::iter_swap(pntr, pntr - 1); // keep moving the element back
				pntr--; // after we swap we want to update the pointer
			}
		}
	}
}

namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	void InsertionSort(ITER start, ITER end, FUNC cmp) {
		::gWindow->render({start, start});
		for(ITER srt = start + 1; srt != end; srt++) { // go through the entire array
			ITER pntr = srt; // pick the first element
			::gWindow->render({pntr, srt});
			while(pntr > start && cmp(*(pntr), *(pntr - 1))) { // Until the element is in the right place or we are at the beginning
				::gWindow->render({pntr, srt});
				std::iter_swap(pntr, pntr - 1); // keep moving the element back
				::gWindow->render({pntr, srt});
				pntr--; // after we swap we want to update the pointer
				::gWindow->render({pntr, srt});
			}
			::gWindow->render({pntr, srt});
		}
	}
}