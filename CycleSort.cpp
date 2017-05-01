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
	void CycleSort(ITER start, ITER end) {
		const std::size_t size = std::distance(start, end);
		unsigned writes = 0;
		
		for(int i = 0; i < size - 1; ++i) {
			typename ITER::value_type item = *(start + i);
			
			std::size_t pos = i;
			
			for(int j = i + 1; j < size; ++j) {
				if(*(start + j) < item)
					++pos;
			}
			
			if(pos == i)
				continue;
			
			while(item == *(start + pos))
				++pos;
			
			std::swap(*(start + pos), item);
			++writes;
			
			while(pos != i) {
				pos = i;
				for(int j = i + 1; j < size; ++j) {
					if(*(start + j) < item)
						++pos;
				}
				
				while(item == *(start + pos))
					++pos;
			
				std::swap(*(start + pos), item);
				++writes;
			}
		}
	}
}


namespace SortAlgVis {
	template <typename ITER>
	void CycleSort(ITER start, ITER end) {
		const std::size_t size = std::distance(start, end);
		unsigned writes = 0;
		
		for(int i = 0; i < size - 1; ++i) {
			::gWindow->render({start + i});
			typename ITER::value_type item = *(start + i);
			
			std::size_t pos = i;
			
			for(int j = i + 1; j < size; ++j) {
				::gWindow->render({start + i, start + j, start + pos});
				if(*(start + j) < item)
					++pos;
			}
			
			if(pos == i)
				continue;
			
			while(item == *(start + pos)) {
				++pos;
				::gWindow->render({start + i, start + pos});
			}
			
			std::swap(*(start + pos), item);
			::gWindow->render({start + i, start + pos});
			++writes;
			
			while(pos != i) {
				pos = i;
				for(int j = i + 1; j < size; ++j) {
					::gWindow->render({start + i, start + j, start + pos});
					if(*(start + j) < item)
						++pos;
				}
				
				while(item == *(start + pos)) {
					::gWindow->render({start + i, start + pos});
					++pos;
				}
			
				std::swap(*(start + pos), item);
				::gWindow->render({start + i, start + pos});
				++writes;
			}
		}
	}
}