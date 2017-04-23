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
	void GnomeSort(ITER start, ITER end, FUNC cmp) {
		ITER idx = start;
		while(idx < end) {
			if(idx == start || cmp(*(idx), *(idx - 1))) {
				idx++;
			} else {
				std::iter_swap(idx, idx - 1);
				idx--;
			}
		}
	}
}