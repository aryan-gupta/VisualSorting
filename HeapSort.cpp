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
	std::size_t heap_size;
	
	std::size_t heap_parent (std::size_t i) {
        return i / 2;
    }

    /* For left & right, note that arrays are 0-based */
    std::size_t heap_left (std::size_t i) {
        return 2*(i + 1) - 1;
    }

    std::size_t heap_right (std::size_t i) {
        return 2*(i + 1);
    }

    template<typename Iterator>
    void max_heapify (Iterator begin, std::size_t i) {
        std::size_t l  = heap_left (i);
        std::size_t r  = heap_right (i);
        std::size_t largest = i;

        if (l < heap_size && *(begin + l) > *(begin + i)) {
            largest = l;
        }
        if (r < heap_size && *(begin + r) > *(begin + largest)) {
            largest = r;
        }
        if (largest != i) {
            std::swap (*(begin + i), *(begin + largest));
            max_heapify (begin, largest);
        }
    }
	
	template<typename Iterator>
	binheap (Iterator begin, Iterator end) {
		heap_size = std::distance (begin, end);
		
        if (heap_size <= 1) {
            return;
        }
        
        /* build max heap */
        for (std::size_t i = heap_size / 2 - 1;; i--) {
            max_heapify (begin, i);
            if (i == 0) {
                break;
            }
        }
        /* heap sort itself */
        for (std::size_t i = heap_size - 1; i > 0; i--) {
            std::swap (*begin, *(begin + i));
            heap_size -= 1;
            max_heapify (begin, 0);
        }
    }
}
