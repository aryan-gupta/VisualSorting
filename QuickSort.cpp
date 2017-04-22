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
	ITER piv = end;
	ITER i = start - 1;
	
	for(ITER j = start; j < end - 1; ++j) {
		if(cmp(*j, *piv)) {
			i++;
			std::iter_swap(i, j);
		}
	}
	
	std::iter_swap(i + 1, end);
	return i + 1;
}

template <typename ITER, typename FUNC>
void QuickSort(ITER start, ITER end, FUNC cmp) {
	end--;
	if(start < end) {
		ITER p = part(start, end, cmp);
		QuickSort(start, p - 1, cmp);
		QuickSort(p + 1, end, cmp);
	}
}