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
	void StoogleSort(ITER start, ITER end, FUNC cmp) {
		end--;
		
		if(!cmp(*start, *end)) {
			std::iter_swap(start, end);
		}
		
		if(end - start + 1 > 2) {
			int prt = (end - start + 1)/3;
			
			StoogleSort(start, end - prt + 1, cmp);
			StoogleSort(start + prt, end + 1, cmp);
			StoogleSort(start, end - prt + 1, cmp);
		}
	}
}