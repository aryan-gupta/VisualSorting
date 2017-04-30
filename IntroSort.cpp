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
		if(size <= 1) {
			return;
		
		} else if(max == 0) {
			SortAlg::HeapSort(start, end);
			LOGL(max)
		} else {
			std::size_t half = size / 2;
			IntroSortHelper(start, end - half, max - 1);
			IntroSortHelper(start + half, end, max - 1);
		}
	}
	
	template <typename ITER>
	void IntroSort(ITER start, ITER end) {
		unsigned max = log(std::distance(start, end)) * 2;
		LOGL(max)
		IntroSortHelper(start, end, max);
	}
}

namespace SortAlgVis {
	template <typename ITER, typename FUNC>
	ITER PartMedOf3(ITER start, ITER end, FUNC cmp) {
		auto mid = std::next(start, std::distance(start, end) / 2);
		
		if(!cmp(*mid, *end))
			std::iter_swap(mid, end);
		if(!cmp(*start, *mid))
			std::iter_swap(start, mid);
		if(!cmp(*mid, *end))
			std::iter_swap(mid, end);
				
		std::iter_swap(mid, end);
		return part(start, end, cmp);
	}
	
	template <typename ITER>
	void IntroSortHelper(ITER start, ITER end, unsigned max) { 		
		if(std::distance(start, end) < 16)
			return;
		
		if(max == 0) {
			SortAlgVis::HeapSort(start, end);
			::gWindow->render();
			return;
		}
		
		auto prt = PartMedOf3(start, end, [](int a, int b){ return a < b; });
		IntroSortHelper(start, prt, max - 1);
		IntroSortHelper(prt, end, max - 1);
		::gWindow->render();
	}
	
	template <typename ITER>
	void IntroSort(ITER start, ITER end) {
		unsigned max = log(std::distance(start, end));
		IntroSortHelper(start, end, max);
		SortAlgVis::InsertionSort(start, end, [](int a, int b){ return a < b; });
	}
}