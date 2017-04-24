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
		for(; start < end; start++) {
			std::iter_swap(start, std::min_element(start, end, cmp));
		}
	}
}

namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	ITER min_element(ITER start, ITER end, FUNC cmp) {
		ITER min = start;
		for(; start < end; start++) {
			::gWindow->render({start, min});
			if(cmp(*start, *min)) {
				::gWindow->render({start, min});
				min = start;
				::gWindow->render({start, min});
			}
		}
		return min;
	}
	
	template <typename ITER, typename FUNC>
	void SelectionSort(ITER start, ITER end, FUNC cmp) {
		for(; start < end; start++) {
			::gWindow->render({start});
			std::iter_swap(start, SortAlgVis::min_element(start, end, cmp));
			::gWindow->render({start});
		}
	}
}