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
#define PRINT_LEGAL_TERR std::cout << '\n' << R_PROJNAME << " v" << R_PVERSION \
		<< " by " << R_AUTHOR << '\n' << R_COPYRIGHT << '\n' << R_COMMENTS \
		<< "\n\n\n" // Legal and Informational


#include <iostream>
#include <cstdlib>

#include ".\inc\main.h"

const int MAX_SIZE = 10;

int main(int argc, char* argv[]) {
	PRINT_LEGAL_TERR;
	
	srand(time(0));
	
	std::vector<int> testVec;
	for(int i = 0; i < MAX_SIZE; ++i)
		testVec.push_back(rand() % 10 + 1);
	
	
	// sort here
	
	
	return 0;
}
}