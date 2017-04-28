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
	template<typename ITER>
	std::vector<typename ITER::value_type> MergeSortMerge(ITER lbegin, const ITER mid, const ITER end) {
		std::vector<typename ITER::value_type> v; // create tmp storage
		ITER rbegin = mid;
		
		// Go through the two halves of the array and merge them.
		// if the left half iterator is smaller then insert that in to the vector
		// if the right side vector is smaller then enter that. lastly increment 
		// the iterator to the next point
		while (lbegin != mid && rbegin != end)
			v.push_back((*lbegin <= *rbegin)? *lbegin++ : *rbegin++);

		v.insert(v.end(), lbegin, mid); // Add the remaining elements
		v.insert(v.end(), rbegin, end);

		return std::move(v); // return the sorted array
	}

	template <typename ITER>
	void MergeSort(ITER begin, ITER end) {
		auto size = std::distance(begin, end); // get the size of the section we need to sort
		if (size < 2) // if its just one then consider it sorted
			return;

		auto mid = std::next(begin, size / 2); // find the mid point
		MergeSort(begin, mid); // sort the first half
		MergeSort(mid, end);   // then the second half

		auto &&v = MergeSortMerge(begin, mid, end);      // merge them together into one
		std::move(v.begin(), v.end(), begin); // apply merge to the orginal array
	}
}

namespace SortAlgVis {	
	template<typename ITER>
	std::vector<typename ITER::value_type> MergeSortMerge(ITER lbegin, const ITER mid, const ITER end) {
		std::vector<typename ITER::value_type> v;
		ITER rbegin = mid;
		::gWindow->render({lbegin, rbegin, end});
		while (lbegin != mid && rbegin != end) {
			v.push_back((*lbegin <= *rbegin)? *lbegin++ : *rbegin++);
			::gWindow->render({lbegin, rbegin, end});
		}
		
		v.insert(v.end(), lbegin, mid);
		v.insert(v.end(), rbegin, end);

		return std::move(v);
	}

	template <typename ITER>
	void MergeSort(ITER begin, ITER end) {
		auto size = std::distance(begin, end);
		if (size < 2)
			return;

		auto mid = std::next(begin, size / 2);
		::gWindow->render({begin, end});
		MergeSort(begin, mid);
		MergeSort(mid, end);

		auto &&v = MergeSortMerge(begin, mid, end);
		::gWindow->render({begin, end, mid});
		std::move(v.begin(), v.end(), begin);
		::gWindow->render({begin, end, mid});
	}
}