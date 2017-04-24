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
	template<typename ITER>
	std::vector<typename ITER::value_type> merge(const ITER begin, const ITER mid, const ITER end) {
		std::vector<typename ITER::value_type> v;
		ITER it_l{ begin }, it_r{ mid };
		const ITER it_mid{ mid }, it_end{ end };

		while (it_l != it_mid && it_r != it_end) {
			v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
		}   

		v.insert(v.end(), it_l, it_mid);    
		v.insert(v.end(), it_r, it_end);

		return std::move(v);
	}

	template <typename ITER>
	void MergeSort(ITER begin, ITER end) {
		auto size = std::distance(begin, end);
		if (size < 2)
			return;

		auto mid = std::next(begin, size / 2);
		MergeSort(begin, mid);
		MergeSort(mid, end);

		auto &&v = merge(begin, mid, end);
		std::move(v.cbegin(), v.cend(), begin);
	}
}