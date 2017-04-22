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
	for(ITER pntr = start + 1; pntr != end; pntr++) {
		ITER mvr = pntr;
		while(mvr > start && cmp(*(mvr), *(mvr - 1))) {
			std::iter_swap(mvr, mvr - 1);
			mvr--;
		}
	}
}