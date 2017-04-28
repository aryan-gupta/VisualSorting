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

#include <cmath>

namespace SortAlg {
	template <typename ITER>
	void IntroSortHelper(ITER start, ITER end, unsigned max) {
		std::size_t size = std::distance(start, end);
		
		if(size <= 1)
			return;
		
		if(max == 0) {
			SortAlg::HeapSort(start, end);
		} else {
			std::size_t half = size / 2;
			IntroSortHelper(start, end - half);
			IntroSortHelper(start + half, end);
		}
	}
	
	template <typename ITERC>
	void IntroSort(ITER start, ITER end) {
		unsigned max = log(std::distance(start, end)) * 2;
		IntroSortHelper(start, end, max);
	}
}