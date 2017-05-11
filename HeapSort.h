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

namespace SortAlg { /// @todo add compare functor
	template<typename ITER>
	void MaxHeapify (ITER begin, std::size_t& heap_size, std::size_t i) {
		std::size_t lchild  = 2*(i + 1) - 1; // the left child
		std::size_t rchild  = 2*(i + 1);     // the right child
		std::size_t largest = i;        // the largest (should be parent node)

		if (lchild < heap_size && *(begin + lchild) > *(begin + largest)) // if the left child is bigger
			largest = lchild;
		
		if (rchild < heap_size && *(begin + rchild) > *(begin + largest)) // if the right child is bigger
			largest = rchild;
		
		if (largest != i) { // if the parent node is not the biggest after previous checks
			std::iter_swap(begin + i, begin + largest); // swap them
			MaxHeapify (begin, heap_size, largest); // go down to sub tree and fix it (because we swapped)
		}
	}
	
	template<typename ITER>
	void HeapSort (ITER begin, ITER end) {
		std::size_t heap_size = std::distance (begin, end);
		
		if (heap_size <= 1) return; // if we have a tree less than two (== 1), its sorted
		
		for (std::size_t i = heap_size / 2 - 1;; i--) { // create max heap from data
			MaxHeapify (begin, heap_size, i);
			if (i == 0) break; // exit if we have reached the root of the tree 
		}
		
		for (std::size_t i = heap_size - 1; i > 0; i--) { // start sorting
			std::iter_swap(begin, begin + i); // swap the root of the tree and the sorted section
			heap_size -= 1; // reduce the heap size
			MaxHeapify (begin, heap_size, 0); // correct heap for next run
		}
	}
}

namespace SortAlgVis {
	template<typename ITER, typename FUNC>
	void MaxHeapify (ITER begin, std::size_t& heap_size, std::size_t i, FUNC cmp) {
		std::size_t lchild  = 2*(i + 1) - 1;
		std::size_t rchild  = 2*(i + 1);
		std::size_t largest = i;

		if (lchild < heap_size && !cmp(*(begin + lchild), *(begin + largest)))
			largest = lchild;
		::gWindow->render({begin + largest, begin + lchild, begin + rchild});
		if (rchild < heap_size && !cmp(*(begin + rchild), *(begin + largest)))
			largest = rchild;
		::gWindow->render({begin + largest, begin + lchild, begin + rchild});
		if (largest != i) {
			std::iter_swap(begin + i, begin + largest);
			::gWindow->render({begin + largest, begin + lchild, begin + rchild});
			MaxHeapify (begin, heap_size, largest, cmp);
		}
	}
	
	template<typename ITER, typename FUNC>
	void HeapSort (ITER begin, ITER end, FUNC cmp) {
		std::size_t heap_size = std::distance (begin, end);
		
		if (heap_size <= 1) return;
		
		for (std::size_t i = heap_size / 2 - 1;; i--) {
			MaxHeapify (begin, heap_size, i, cmp);
			::gWindow->render();
			if (i == 0) break;
		}
		
		for (std::size_t i = heap_size - 1; i > 0; i--) {
			std::iter_swap(begin, begin + i);
			::gWindow->render();
			heap_size -= 1;
			MaxHeapify (begin, heap_size, 0, cmp);
			::gWindow->render();
		}
	}
}