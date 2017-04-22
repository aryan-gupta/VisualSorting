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

template <typename ITER, typename FUNC>
void InsertionSort(ITER start, ITER end, FUNC cmp) {
	start++;
	while(start != end) {
		ITER pntr = start + 1;
		while(pntr >= start && cmp(pntr - 1, pntr)) {
			swap(pntr - 1, pntr);
			pntr--;
		}
	}
}