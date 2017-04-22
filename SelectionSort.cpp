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
void SelectionSort(ITER start, ITER end, FUNC cmp) {
	for(ITER idx = start; idx < end; idx++) {
		std::iter_swap(idx, std::min_element(idx, end, cmp));
	}
}