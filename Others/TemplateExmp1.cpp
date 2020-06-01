/*
 * TemplateExmp1.cpp
 *
 *  Created on: Mar 8, 2018
 *      Author: chandra.shekhar
 */
#include<stdio.h>
#include<iostream>

using namespace std;

template<typename T1, typename T2>
class A{
	class B{
	public :
		T1 b;
		B(T1 x):b(x){}
		void print(){
			cout << " A is " << b << endl;
		}
		void SetB(int x){
			b = x;
		}

	};

public:
	T1 a;
	T2 c;
	B b1;
	A(T1 x, T2 y):b1(x),c(y){}
	void print(){
		b1.print();
		cout << "C is " << c << endl;
	}
};
int main(){
	A <int, int>a(10,20);
	a.print();
	return 0;
}



