#pragma once

#include<string>
using namespace std;
#include "Factory.h"
using namespace Learn::reflect;
namespace Learn {
	namespace ClassRegister {
		class Register {
		public:
			Register(const string& ClassName, create_object method) {
				ClassFactory* factory = Singleton<ClassFactory>::instance();
				if (factory) {
					factory->register_class(ClassName, method);
				}
			}
			Register(const string& ClassName, const string& FiledName, const string& FiledType, size_t pos) {
				ClassFactory* factory = Singleton<ClassFactory>::instance();
				if (factory) {
					cout << ClassName << ' ' << FiledName << ' ' << FiledType << ' ' << pos << endl;
					factory->RegisterClassFiled(ClassName, FiledName, FiledType, pos);
				}
			}
			Register(const string& ClassName, const string& ClassMethodName, uintptr_t MethodPtr) {
				ClassFactory* factory = Singleton<ClassFactory>::instance();
				if (factory) {
					cout << ClassName << ' ' << ClassMethodName << ' ' << MethodPtr << endl;
					factory->RegisterClassMethod(ClassName, ClassMethodName, MethodPtr);
				}
			}
		};
		#define REGISTER_CLASS(ClassName)		\
			Obj* createObj##ClassName (){		\
				Obj * obj = new ClassName();	\
				obj->m_name  = #ClassName;								\
				return obj;						\
				}								\
			Register register##ClassName (#ClassName,createObj##ClassName)

		#define REGISTER_CLASS_FILED(ClassName, FiledName,FiledType)	\
				ClassName ClassName##FiledName;								\
					Register register##ClassName##FiledName(#ClassName,#FiledName,#FiledType,(size_t)(&ClassName##FiledName.FiledName) - (size_t)(& ClassName##FiledName))
		#define REGISTER_CLASS_METHOD(ClassName,MethodName)	\
				std::function<void(ClassName*)> ClassName##MethodName##method = &ClassName::MethodName;\
				Register register##ClassName##MethodName(#ClassName,#MethodName,(uintptr_t)&ClassName##MethodName##method)

	}
}