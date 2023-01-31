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
c++ ������

1����ȡ�����
˼·��ʹ�õ���+ ����ģʽ������ ����Ψһһ��������ĵĹ�����
�����л���� className �� �������Fun Ψһ��Ӧ��
���Զ�����ʱ �����ʵ�����Name�� һ����Ĵ������� ȥע�᣿ʹ�� ��ķ���
A* a = (A*)factory->create_class("A");
��һ���Ż������ڴ���һ��A����Ҫ����A�ĵ�string����������ʵ���������ǲ�֪�����A����ʵ�����͵ĵġ�
�����е��඼�̳�һ��Obj��
Obj* a = factory->create_class("A");
2����ȡ���Ա���� ����
������һ���������Ե�ƫ����λ�ȡ��
auto offset =  (size_t)&((class *)0->value);
�������ֺڿƼ���ĳЩ���뻷���²���ͨ����
��ʽ����
class a;
auto offset = (size_t)&a.value - (size_t)&a;
ͨ��������ƫ�Ƶķ�ʽ���Խ������Աfiled�ķ��䡣
˼�������ַ�ʽ��ֱ��ʵ����ͨ���궨�壬����һ��ʼ��ʱ��ͽ���������룬��Ҳ������Filed������
public���Եġ�����Ȼ�ǲ�ʵ�õġ�
һ��˼���������˽⵽���������Ҳ�����Լ��ķ���ϵͳ�������ڳ�ʼ����һ����ʱ����ÿ����Ŀ�ʼ������
һ�� GENERATED_BODY()
����궨��ʱΪÿһ����������һ����Ԫ�࣬����ͨ����Ԫ��ķ�ʽ���Է��ʵ�ÿ�����ԡ�
3����Ա�����ķ��ʣ�

typedef std::function<decltype(this)> my_method;


*/