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

using namespace std; 

int main() {
		
	for(int i = 0; i < 35; ++i)
		testVec.push_back(i);
	
	std::random_shuffle(testVec.begin(), testVec.end());
	printPretty(testVec);

	SortAlg::OddEvenSort(testVec.begin(), testVec.end());
	
	printPretty(testVec);
	system("pause");
	
}