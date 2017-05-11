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
	void BitonicSortCompare(bool up, ITER start, ITER end, FUNC cmp) {
		int half = (end - start) / 2;
		
		for(; start < end - half; start++) {
			if(cmp(*start, *(start + half)) == up)
				std::iter_swap(start, start + half);
		}
	}
	
	template <typename ITER, typename FUNC>
	void BitonicSortMerge(bool up, ITER start, ITER end, FUNC cmp) {
		if(end - start <= 1)
			return;
		
		BitonicSortCompare(up, start, end);
		
		int half = (end - start) / 2;
		BitonicSortMerge(up, start, end - half, cmp);
		BitonicSortMerge(up, start + half, end, cmp);
	}
	
	template <typename ITER, typename FUNC>
	void BitonicSortHelper(bool up, ITER start, ITER end, FUNC cmp) {
		if(end - start <= 1)
			return;
		
		int half = (end - start) / 2;
		BitonicSortHelper(true, start, end - half, cmp);
		BitonicSortHelper(false, start + half, end, cmp);
		BitonicSortMerge(up, start, end, cmp);
	}
	
	template <typename ITER, typename FUNC>
	void BitonicSort(ITER start, ITER end, FUNC cmp) {
		BitonicSortHelper(true, start, end, cmp);
	}
	
	// ==================== NO COMPARE FUNC ====================================
	
		template <typename ITER>
	void BitonicSortCompare(bool up, ITER start, ITER end) {
		int half = (end - start) / 2;
		
		for(; start < end - half; start++) {
			if(*start > *(start + half) == up)
				std::iter_swap(start, start + half);
		}
	}
	
	template <typename ITER>
	void BitonicSortMerge(bool up, ITER start, ITER end) {
		if(end - start <= 1)
			return;
		
		BitonicSortCompare(up, start, end);
		
		int half = (end - start) / 2;
		BitonicSortMerge(up, start, end - half);
		BitonicSortMerge(up, start + half, end);
	}
	
	
	template <typename ITER>
	void BitonicSortHelper(bool up, ITER start, ITER end) {
		if(end - start <= 1)
			return;
		
		int half = (end - start) / 2;
		BitonicSortHelper(true, start, end - half);
		BitonicSortHelper(false, start + half, end);
		BitonicSortMerge(up, start, end);
	}
	
	template <typename ITER>
	void BitonicSort(ITER start, ITER end, bool up) {
		BitonicSortHelper(up, start, end);
	}
}

namespace SortAlgVis {	
	template <typename ITER, typename FUNC>
	void BitonicSortCompare(bool up, ITER start, ITER end, FUNC cmp) {
		int half = (end - start) / 2;
		
		for(; start < end - half; start++) {
			::gWindow->render({start});
			if(!cmp(*start, *(start + half)) == up) {
				std::iter_swap(start, start + half);
				::gWindow->render({start});
			}
		}
	}
	
	template <typename ITER, typename FUNC>
	void BitonicSortMerge(bool up, ITER start, ITER end, FUNC cmp) {
		if(end - start <= 1)
			return;
		
		BitonicSortCompare(up, start, end, cmp);
		
		int half = (end - start) / 2;
		BitonicSortMerge(up, start, end - half, cmp);
		BitonicSortMerge(up, start + half, end, cmp);
	}
	
	
	template <typename ITER, typename FUNC>
	void BitonicSortHelper(bool up, ITER start, ITER end, FUNC cmp) {
		if(end - start <= 1)
			return;
		
		int half = (end - start) / 2;
		BitonicSortHelper(true, start, end - half, cmp);
		BitonicSortHelper(false, start + half, end, cmp);
		BitonicSortMerge(up, start, end, cmp);
	}
	
	template <typename ITER, typename FUNC>
	void BitonicSort(ITER start, ITER end, FUNC cmp) {
		BitonicSortHelper(true, start, end, cmp);
	}
}