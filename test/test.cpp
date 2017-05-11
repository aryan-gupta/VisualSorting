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
#include <vector>

template<class TYPE> void printPretty(std::vector<TYPE>& vec);

namespace test {
	
	// =================== NON COMPARE FUNC ====================================
	

}

std::vector<int> testVec;

int main() {
	using namespace std; 

	for(int i = 0; i < 35; ++i)
		testVec.push_back(i);
	
	std::random_shuffle(testVec.begin(), testVec.end());
	printPretty(testVec);

	test::SomeSort(testVec.begin(), testVec.end());
	// test::InsertionSort(testVec.begin(), testVec.end(), [](int a, int b){ return a < b; });
	
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