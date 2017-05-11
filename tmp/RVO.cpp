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
 
// https://en.wikipedia.org/wiki/Return_value_optimization

#include <iostream>
using namespace std;

// struct C {
  // C() {}
  // C(const C&) { std::cout << "A copy was made.\n"; }
// };

// C f() {
  // return C();
// }

// int main() {
  // std::cout << "Hello World!\n";
  // C obj = f();
// }


int n = 0;
struct C {
  explicit C(int) {}
  C(const C&) { ++n; } // the copy constructor has a visible side effect
};                     // it modifies an object with static storage duration

int main() {
  C c1(42); // direct-initialization, calls C::C(42)
  C c2 = C(42); // copy-initialization, calls C::C( C(42) )
  
  std::cout << n << std::endl; // prints 0 if the copy was elided, 1 otherwise
  return 0;
}