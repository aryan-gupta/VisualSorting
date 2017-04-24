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

#include <array>

namespace SortAlg {
	template <typename ITER, typename FUNC>
	void ShellSort(ITER start, ITER end, FUNC cmp) {
		std::array<int,8> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
		
		for(int gap : gaps) {
			for(int i = gap; i < (end - start); ++i) {
				typename ITER::value_type temp = *(start + i);
				
				int j;
				for(j = i; j >= gap && *(start + j - gap) > temp; j -= gap) {
					*(start + j) = *(start + j - gap);
				}
				*(start + j) = temp;
			} 
		}
	}
}