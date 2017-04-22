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

template <typename ITER, typename FUNC>
ITER part(ITER start, ITER end, FUNC cmp) {
	ITER piv = end;       // Our piviot point
	ITER prt = start - 1; // our parted pointer
	
	for(ITER pntr = start; pntr < end; ++pntr) { // go through the array except the piv point
		if(cmp(*pntr, *piv)) {         // if out pointer is less than our pivot
			prt++;                     // increment partition (to make space for our value)
			std::iter_swap(prt, pntr); // swap them two so the les than value is before our partition
		}
	}
	
	std::iter_swap(prt + 1, end); // swap our pivot with the first one more than piv
	return prt + 1;
}

template <typename ITER, typename FUNC>
void QuickSort(ITER start, ITER end, FUNC cmp) {
	if(start < end) { // make sure we have some values to sort
		ITER p = part(start, end, cmp); // partition at the last value (pivot)
		QuickSort(start, p - 1, cmp);   // sort all before our pivot point
		QuickSort(p + 1, end, cmp);     // sort everything after our pivot
	}
}