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

namespace SortAlg {
	template <typename ITER, typename FUNC>
	void BubbleSort(ITER start, ITER end, FUNC cmp) {
		bool sorted;
		do {
			sorted = true;
			for(ITER idx = start; idx < end - 1; ++idx) {
				if(!cmp(*(idx), *(idx + 1))) {
					std::iter_swap(idx, idx + 1);
					sorted = false;
				}
			}
		} while(!sorted);
	}
}