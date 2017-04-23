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
	template <typename ITER>
	void MergeSortMerge(ITER start, ITER end, ITER mid) {
		ITER i = start, j = mid;
		
		for(ITER k = start; k < end; ++k) {
			if(i < mid && (j >= end || *i <= *j)) {
				std::iter_swap(k, i);
				i++;
			} else {
				std::iter_swap(k, j);
				j++;
			}
		}
	}

	template <typename ITER>
	void MergeSort(ITER start, ITER end) {
		if(end - start < 2)
			return;
		
		ITER mid = start + (end - start) / 2;
		
		MergeSort(start, mid);
		MergeSort(mid, end);
		
		MergeSortMerge(start, end, mid);
	}
}