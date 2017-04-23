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
	template <typename ITER>
	void RadixSortHelper(ITER start, ITER end, int digit) {
		std::stable_sort(start, end, [&](int a, int b) { return a/digit < b/digit; });
	}
	
	template <typename ITER, typename FUNC>
	void RadixSort(ITER start, ITER end, FUNC cmp) {
		ITER max = std::max_element(start, end, cmp);
		
		for(int exp = 1; (*max) / exp > 0.1; exp *= 10) {
			RadixSortHelper(start, end, exp);
		}
	}
}

namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	ITER max_element(ITER start, ITER end, FUNC cmp) {
		ITER max = start;
		for(; start < end; start++) {
			::gWindow->render({start, max}, 5);
			if(!cmp(*start, *max)) {
				::gWindow->render({start, max}, 5);
				max = start;
				::gWindow->render({start, max}, 5);
			}
		}
		return max;
	}
}