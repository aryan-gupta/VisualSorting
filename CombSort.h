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

namespace SortAlg { /// @todo Add cmp Func template
	template <typename ITER>
	void CombSort(ITER start, ITER end) {
		std::size_t gap = std::distance(start, end);
		bool swapped = true;
		
		while( gap != 1 || swapped == true) { /// @todo remove == true
			
			gap = (gap * 10) / 13;
			if(gap < 1)
				gap = 1;
			
			swapped = false;
			
			for(std::size_t i = 0; i < std::distance(start, end) - gap; ++i) {
				if(*(start + i) > *(start + i + gap)) {
					std::iter_swap(start + i, start + i + gap);
					swapped = true;
				}
			}
		}
	}
}


namespace SortAlgVis {
	template <typename ITER>
	void CombSort(ITER start, ITER end) {
		std::size_t gap = std::distance(start, end);
		bool swapped = true;
		
		while(gap != 1 || swapped == true) {
			::gWindow->render({start});
			gap = (gap * 10) / 13;
			if(gap < 1)
				gap = 1;
			
			swapped = false;
			
			for(std::size_t i = 0; i < std::distance(start, end) - gap; ++i) {
				::gWindow->render({start});
				if(*(start + i) > *(start + i + gap)) {
					std::iter_swap(start + i, start + i + gap);
					::gWindow->render({start + i, start + i + gap});
					swapped = true;
				}
			}
		}
	}
}