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
		end--; // decrement end because ALG sorts [start, end]
		
		if(!cmp(*start, *end)) 
			std::iter_swap(start, end); // swap if they are our of order
		
		if(end - start + 1 > 2) { // make sure there is somthing to sort
			std::size_t prt = (end - start + 1)/3; // get 2/3 partition
			
			// we are adding 1 to the end because ALG sorts [start, end]
			StoogleSort(start, end - prt + 1, cmp); // sort first 2/3
			StoogleSort(start + prt, end + 1, cmp); // sort second 2/3
			StoogleSort(start, end - prt + 1, cmp); // resort first 2/3
		}
	}
	
	// =================== NON COMPARE FUNC ====================================
	
	template <typename ITER>
	void StoogleSort(ITER start, ITER end) {
		end--; // decrement end because ALG sorts [start, end]
		
		if(*start > *end)
			std::iter_swap(start, end); // swap if they are our of order
		
		if(end - start + 1 > 2) { // make sure there is somthing to sort
			std::size_t prt = (end - start + 1)/3; // get 2/3 partition
			
			// we are adding 1 to the end because ALG sorts [start, end]
			StoogleSort(start, end - prt + 1); // sort first 2/3
			StoogleSort(start + prt, end + 1); // sort second 2/3
			StoogleSort(start, end - prt + 1); // resort first 2/3
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
			std::size_t prt = (end - start + 1)/3;
			
			StoogleSort(start, end - prt + 1, cmp);
			StoogleSort(start + prt, end + 1, cmp);
			StoogleSort(start, end - prt + 1, cmp);
		}
		
		::gWindow->render({start, end}, 0);
	}
}