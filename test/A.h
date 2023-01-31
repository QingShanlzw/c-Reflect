#pragma once 

#include<iostream>
#include<string>
using namespace std;
#include"../ClassRegister.h"
using namespace Learn::ClassRegister;
#include<functional>

class A:public Obj {
	
public:
	friend class tt;
	A(){}
	~A(){}
	void show() { cout << "A" << endl; }
public:
	string name;
};
class tt {
public:
	A a;
};

REGISTER_CLASS(A);
REGISTER_CLASS_FILED(A, name, string);
REGISTER_CLASS_METHOD(A, show);