#include "Factory.h"
using namespace Learn::reflect;

void ClassFactory::register_class(const string& ClassName, create_object method) {
	ClassMap[ClassName] = method;
}
Obj* ClassFactory::create_class(const string& ClassName) {
	auto it = ClassMap.find(ClassName);
	if (it == ClassMap.end())return nullptr;
	return it->second();
}

void Learn::reflect::ClassFactory::RegisterClassFiled(const string& ClassName, const string& FiledName, const string& Type, size_t Offset)
{
	_ClassFiled[ClassName].push_back(new ClassFiled(FiledName, Type, Offset));
}

int Learn::reflect::ClassFactory::GetFiledCount(const string& ClassName)
{
	return _ClassFiled[ClassName].size();
}

ClassFiled* Learn::reflect::ClassFactory::GetFiled(const string& ClassName, int pos)
{
	int s = _ClassFiled[ClassName].size();
	if (s <= 0 || pos >= s)return nullptr;
	return _ClassFiled[ClassName][pos];
}

ClassFiled* Learn::reflect::ClassFactory::GetFiled(const string& ClassName, string& FiledName)
{
	for (auto i : _ClassFiled[ClassName]) {
		if (i->GetName() == FiledName)
			return i;
	}
	return nullptr;
}

void Learn::reflect::ClassFactory::RegisterClassMethod(const string& ClassName, const string& ClassMethodName, uintptr_t MethodPtr)
{
	_ClassMethod[ClassName].push_back(new Method(ClassMethodName, MethodPtr));
}

int Learn::reflect::ClassFactory::GetClassMethodCount(const string& ClassName)
{
	return _ClassMethod[ClassName].size();
}

Method* Learn::reflect::ClassFactory::GetClassMethod(const string& ClassName, int pos)
{
	auto m = _ClassMethod[ClassName];
	if (pos<0 || pos>m.size())return nullptr;
	return m[pos];
}

Method* Learn::reflect::ClassFactory::GetClassMethod(const string& ClassName, const string& MethodName)
{
	auto m = _ClassMethod[ClassName];
	for (auto i : m) {
		if (i->GetMethodName() == MethodName)return i;
	}
	return nullptr;
}

void Learn::reflect::Obj::call(string MehodName)
{
	ClassFactory* factory = Singleton<ClassFactory>::instance();
	if (factory) {
		Method* method =factory->GetClassMethod(m_name, MehodName);
		typedef function<void(decltype(this))> class_method;
		(*(class_method*)method->GetMethodPtr())(this);
	}
}
