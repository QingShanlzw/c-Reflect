#pragma once 

#include<iostream>
#include<string>

using namespace std;

#include"../ClassRegister.h"
using namespace Learn::ClassRegister;

class B :public Obj{

public:
	B() {}
	~B() {}
	void show() { cout << "B" << endl; }
private:
	string name;
};
REGISTER_CLASS(B);