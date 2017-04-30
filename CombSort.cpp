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
	template <typename ITER, typename FUNC>
	void SelectionSort(ITER start, ITER end, FUNC cmp) {
		std::size_t gap = std::distance(end, start);
		shrink = 1.3;
		bool sorted = false;
		
		while(!sorted) {
			gap = gap / shrink;
			
			if(gap > 1) {
				sorted = false;
			} else {
				gap = 1;
				sorted = true;
			}
			
			std::size_t i = 0;
			while(i + gap < std::distance(end, start)) {
				if(*(start + i) > *(start + i + gap)) {
					std::iter_swap(start + i, start + i + gap);
					sorted = false;
				}
				++i;
			}
		}
	}
}