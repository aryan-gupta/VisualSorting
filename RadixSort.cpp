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

#include <array>

namespace SortAlg {
	template <typename ITER, typename FUNC>
	void RadixSort(ITER start, ITER end, FUNC cmp) {
		ITER max = std::max_element(start, end);
		
		for(int exp = 1; (*max) / exp > 0.1; exp *= 10) {
			std::stable_sort(start, end, [&](int a, int b) { return a/exp < b/exp; });
		}
	}
}

namespace SortAlgVis {
	template <typename ITER>
	ITER max_element(ITER start, ITER end) {
		ITER max = start;
		for(; start < end; start++) {
			::gWindow->render({start, max}, 1);
			if(*start > *max) {
				::gWindow->render({start, max}, 1);
				max = start;
				::gWindow->render({start, max}, 1);
			}
		}
		return max;
	}
	
	template <typename ITER>
	void RadixSortGroup(ITER start, ITER end, int radix) {
		std::array<std::vector<typename ITER::value_type>, 10> bins;
		// split into bins
		for(ITER idx = start; idx < end; ++idx) {
			bins[(*(idx) / radix) % 10].push_back(*idx);
		}
		// compile them together again
		for(auto bin : bins) {
			for(auto val : bin) {
				*start = val;
				start++;				
				::gWindow->render({start});
			}
		}
	}
	
	template <typename ITER>
	void RadixSort_LSD(ITER start, ITER end) {
		ITER max = SortAlgVis::max_element(start, end);
		
		for(int exp = 1; exp <= *max * 10; exp *= 10) {
			::gWindow->render({start});
			RadixSortGroup(start, end, exp);
		}
		::gWindow->render({start});
	}
	
	template <typename ITER>
	void RadixSort_MSD(ITER start, ITER end) {
		ITER max = SortAlgVis::max_element(start, end);
		
		for(int exp = *max; exp > 0; exp /= 10) {
			::gWindow->render({start});
			RadixSortGroup(start, end, exp);
		}
	}
}