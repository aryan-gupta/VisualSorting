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
#include "Window.h"

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

namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	void StoogleSort(ITER start, ITER end, FUNC cmp) {
		end--;
		::gWindow->render({start, end}, 0);
		if(!cmp(*start, *end)) {
			std::iter_swap(start, end);
			::gWindow->render({start, end}, 0);
		}
		
		if(end - start + 1 > 2) {
			int prt = (end - start + 1)/3;
			
			StoogleSort(start, end - prt + 1, cmp);
			StoogleSort(start + prt, end + 1, cmp);
			StoogleSort(start, end - prt + 1, cmp);
		}
		
		::gWindow->render({start, end}, 0);
	}
}