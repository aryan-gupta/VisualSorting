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


template <typename ITER, typename FUNC>
void InsertionSort(ITER start, ITER end, FUNC cmp) {
	for(ITER srt = start + 1; srt != end; srt++) {
		ITER pntr = srt;
		while(pntr > start && cmp(*(pntr), *(pntr - 1))) {
			std::iter_swap(pntr, pntr - 1);
			pntr--;
		}
	}
}