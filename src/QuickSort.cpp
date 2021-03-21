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

namespace SortAlg {
	template <typename ITER, typename FUNC>
	ITER part(ITER start, ITER end, FUNC cmp) {
		ITER part = start; // our parted pointer so [start, part) is less than the pivot
		
		for(ITER ptr = start; ptr < end; ++ptr) { // go through the array except the pivot point
			if(cmp(*ptr, *end)) {         // if our pointer is less than our pivot
				std::iter_swap(part, ptr); // swap so its its before our partition
				part++;                     // increment partition
			}
		}
		
		std::iter_swap(part, end); // swap our pivot with the first val more than pivot
		return part; // return out pivot
	}
	
	template <typename ITER, typename FUNC>
	void QuickSort(ITER start, ITER end, FUNC cmp) {
		end--; // decrement because ALG sorts [start, end]
		
		if(start < end) { // make sure we have some values to sort
			ITER piv = part(start, end, cmp); // partition at the last value (pivot)
			QuickSort(start, piv, cmp);       // sort all before our pivot point
			QuickSort(piv + 1, end + 1, cmp); // sort everything after our pivot
		}
	}
}


namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	ITER part(ITER start, ITER end, FUNC cmp) {
		ITER prt = start; // our parted pointer so [start, prt) is less than the pivot
		
		for(ITER pntr = start; pntr < end; ++pntr) { // go through the array except the pivot point
			::gWindow->render({pntr, end, prt});
			if(cmp(*pntr, *end)) {         // if our pointer is less than our pivot
				::gWindow->render({pntr, end, prt});
				std::iter_swap(prt, pntr); // swap so its its before our partition
				::gWindow->render({pntr, end, prt});
				prt++;                     // increment partition
				::gWindow->render({pntr, end, prt});
			}
		}
		
		std::iter_swap(prt, end); // swap our pivot with the first val more than pivot
		return prt; // return out pivot
	}
	
	template <typename ITER, typename FUNC>
	void QuickSort(ITER start, ITER end, FUNC cmp) {
		end--; // decrement because ALG sorts [start, end]
		
		if(start < end) { // make sure we have some values to sort
			ITER piv = part(start, end, cmp); // partition at the last value (pivot)
			QuickSort(start, piv, cmp);       // sort all before our pivot point
			QuickSort(piv + 1, end + 1, cmp); // sort everything after our pivot
		}
		::gWindow->render();
	}
}
