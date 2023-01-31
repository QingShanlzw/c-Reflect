#include<iostream>
#include "Factory.h"
using namespace Learn::reflect;
#include "test/A.h";
#include "test/B.h";

using namespace std;

#include<functional>

#define OFFSET(ClassName,field) \
	(size_t)&(ClassName*)0->field 


class test1 {
public:
	void f() { cout << "f" << endl; }
};

typedef std::function<void(test1*)> test_method;

int main() {
	ClassFactory* factory = Singleton<ClassFactory>::instance();

	Obj* a = factory->create_class("A");
	//a->show();

	Obj* b = factory->create_class("B");
	//b->show();




	return 0;
}


/*
c++ 反射器

1、获取类对象
思路：使用单例+ 工厂模式方法， 建立唯一一个创建类的的工厂。
工厂中会根据 className 和 创建类的Fun 唯一对应。
在自定义类时 ，如何实现类的Name和 一个类的创建方法 去注册？使用 宏的方法
A* a = (A*)factory->create_class("A");
进一步优化：现在创建一个A还是要根据A的的string名来建立，实际中往往是不知道这个A的市实际类型的的。
让所有的类都继承一个Obj；
Obj* a = factory->create_class("A");
2、获取类成员数据 反射
首先是一个类中属性的偏移如何获取？
auto offset =  (size_t)&((class *)0->value);
但是这种黑科技在某些编译环境下不会通过。
方式二：
class a;
auto offset = (size_t)&a.value - (size_t)&a;
通过这种类偏移的方式可以进行类成员filed的反射。
思考：这种方式的直接实现是通过宏定义，在类一开始的时候就将其变量加入，这也导致了Filed必须是
public属性的。这显然是不实用的。
一种思考方案：了解到虚幻引擎中也是有自己的反射系统，其中在初始构建一个类时，其每个类的开始都会有
一行 GENERATED_BODY()
这个宏定义时为每一个类声明了一个友元类，这样通过友元类的方式可以访问到每个属性。
3、成员函数的访问：

typedef std::function<decltype(this)> my_method;


*/