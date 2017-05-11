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

// compile with g++ -std=c++17 -fno-elide-constructors .\MoveSemantics.cpp -o MS.exe
// or g++ -std=c++17 .\MoveSemantics.cpp -o MS.exe

typedef long long LL; 
 
const LL MAX = 10000;
int BIGCLASSID = 0;

class BigClass {
public:
	BigClass()  {
		id = BIGCLASSID++;
		cout << "Default Constructor Called by " << id << endl;
		mBigData = new LL[MAX];
		for(LL i = 0; i < MAX; ++i) {
			mBigData[i] = i;
		}
	}
	
	BigClass(const BigClass& lvalue) {
		id = BIGCLASSID++;
		cout << "Copy Constructor Called by " << id << endl;
		mBigData = new LL[MAX];
		for(LL i = 0; i < MAX; ++i) {
			mBigData[i] = lvalue.mBigData[i];
		}
	}
	
	BigClass(BigClass&& prvalue) {
		id = BIGCLASSID++;
		cout << "Move Constructor Called by " << id << endl;
		
		std::swap(mBigData, prvalue.mBigData);
	}
	
	~BigClass() {
		cout << "Destructor Called by " << id << endl;
		delete[] mBigData;
	}
	
	BigClass& operator=(BigClass&& prvalue) {
		cout << "Move Assignment Operator called" << endl;
		std::swap(mBigData, prvalue.mBigData);
		return *this;
	}
	
	BigClass& operator=(BigClass& prvalue) {
		cout << "Assignment Operator Called" << endl;
		std::swap(mBigData, prvalue.mBigData);
		return *this;
	}
	
	BigClass operator+(const BigClass& b) {
		BigClass op1;
		op1.doubleIt();
		
		// BigClass op2;
		// op2.doubleIt();
		
		//return std::move(op1);
		return op1;
	}
	
	void doubleIt() {
		for(LL i = 0; i < MAX; ++i) {
			mBigData[i] *= 2;
		}
	}
private:
	LL* mBigData;
	int id;
};



BigClass makeClass(int tmp) {
	BigClass func1, func2; // ID: 1, 2
	if(tmp > 2)
		return func1;
	else {
		return func2;
	}
}

BigClass makeClass() {
	BigClass func1; // ID: 5
	func1.doubleIt();
	return func1;
}

int main() {
	cout << "var a" << endl; // default constructor 
	BigClass a; // ID: 0
	
	cout << endl << "var b" << endl;  // No RVO, Move constructor 
	BigClass b( // ID: 4, 
		makeClass(1) // ID: 3
	);

	cout << endl << "var c" << endl;  // RVO/Copy Elison, NO Move constructor
	BigClass c( // ID: 7
		makeClass() // ID: 6
	);
	
	cout << endl << "var d" << endl;  // Copy Constructor
	BigClass d(a); // ID: 8
	
	cout << endl << "var e" << endl;  // Copy Elison
	BigClass e( // ID: 11
		a + c // ID: 10 (ID: 9 is in + operator)
	);

	cout << endl << "var f" << endl;
	BigClass f = a + c; // Copy Elison
	
	cout << endl << "var f assignment" << endl;
	f = (a + c); // Move assignment
	
	cout << endl << "end: " << BIGCLASSID << endl;
}
