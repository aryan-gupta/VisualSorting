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
		template <typename ITER>
	void Heapify(ITER start, ITER end) {
	
	}
	
	template <typename ITER, typename FUNC>
	void Heapify(ITER first, ITER start, ITER end) {
		ITER j = (start - first) * 2;
		typename ITER::value_type tmp = *start;
		
		while(j < end) {
			if(j < end && *(j + 1) > *(j)) {
				j++;
			}
			
			if(tmp > *(j)) {
				break;
			} //else
			
			if(tmp <= *(j)) {
				*(j / 2) = *(j);
				j = 2 * j;
			}
		}
		*(j / 2) = tmp;
	}
	
	template <typename ITERC>
	void HeapBuild(ITER start, ITER end) {
		int mid = (end - start)/2;
		for(; mid >= 1; --mid) {
			Heapify(start, start + mid, end);
		}
	}
	
	template <typename ITER>
	void HeapSort(ITER start, ITER end) {
		HeapBuild(start, end);
		Heapify();
		
		end--;
		
		while(end > start)
	}
}
