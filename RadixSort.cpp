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
#include <deque>
#include <cmath>

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
			::gWindow->render({start, max});
			if(*start > *max) {
				::gWindow->render({start, max});
				max = start;
				::gWindow->render({start, max});
			}
		}
		return max;
	}
	
	template <typename ITER>
	void RadixSortGroup_LSD(ITER start, ITER end, int radix) {
		std::array<std::vector<typename ITER::value_type>, 10> bins;
		// split into bins
		for(ITER idx = start; idx < end; ++idx) {
			bins[(*(idx) / radix) % 10].push_back(*idx); 
			::gWindow->render({idx});
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
		
		int size = std::to_string(*max).size();
		
		for(int exp = 0; exp < 100; ++exp) {
			::gWindow->render({start});
			RadixSortGroup_LSD(start, end, pow(10, exp));
		}
		::gWindow->render({start});
	}
	
	template <typename ITER>
	void RadixSortGroup_MSD(ITER start, ITER end, int radix) {
		
		// std::stable_sort(start, end, [&](int a, int b) { return (a % radix) < (b % radix); });
		
		std::array<std::deque<typename ITER::value_type>, 10> bins;
		//split into bins
		for(ITER idx = start; idx != end; ++idx) {
			bins[(*(idx) % radix)].push_back(*idx); 
		}
		//compile them together again
		for(auto& bin : bins) {	
			start = std::copy(bin.begin(), bin.end(), start);
			::gWindow->render({start});
		}
	}
	
	template <typename ITER>
	void RadixSort_MSD(ITER start, ITER end) {
		ITER max = SortAlgVis::max_element(start, end);
		
		int size = std::to_string(*max).size();
		
		for(int exp = 1000; exp > -1; --exp) {
			::gWindow->render({start});
			RadixSortGroup_MSD(start, end, pow(10, exp));
		}
	}
}