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

#include <iostream>
#include <algorithm>

template<class TYPE> void printPretty(std::vector<TYPE>& vec);

namespace test {
	template <typename ITER, typename FUNC>
	void InsertionSort(ITER start, ITER end, FUNC cmp) {
		for(ITER srt = start + 1; srt != end; srt++) { // go through the entire array
			ITER pntr = srt; // pick the first element
			while(pntr > start && cmp(*(pntr), *(pntr - 1))) { // Until the element is in the right place or we are at the beginning
				std::iter_swap(pntr, pntr - 1); // keep moving the element back
				pntr--; // after we swap we want to update the pointer
			}
		}
	}
}

int main() {
	using namespace std; 

	for(int i = 0; i < 35; ++i)
		testVec.push_back(i);
	
	std::random_shuffle(testVec.begin(), testVec.end());
	printPretty(testVec);

	test::OddEvenSort(testVec.begin(), testVec.end());
	
	printPretty(testVec);
	system("pause");
	
}


template<class TYPE>
void printPretty(std::vector<TYPE>& vec) {
	using std::cout; using std::endl;
	
	cout << endl;
	for(TYPE& t : vec) {
		cout << t << " ";
	}
	cout << endl;
}