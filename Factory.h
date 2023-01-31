#pragma once

#include<map>
#include<string>
#include<vector>
#include"Singleton.h"
#include<functional>

using namespace std;
using namespace Learn::utility;

#include"ClassFiled.h"
using namespace Learn::Filed;
#include "ClassMethod.h"
using namespace Learn::ClassMethod;

namespace Learn {
	namespace reflect {

		class Obj {
		public:
			Obj(){}
			virtual ~Obj(){}
			virtual void show(){}
			void call(string MehodName);
			
			string m_name;
		};
		typedef Obj* (*create_object)(void);

		class ClassFactory {
			friend class Singleton<ClassFactory>;
		public:

			void register_class(const string & ClassName, create_object method);
			Obj* create_class(const string& ClassName);
			void RegisterClassFiled(const string& ClassName, const string& FiledName, const string& Type, size_t Offset);
			int GetFiledCount(const string& ClassName);
			ClassFiled* GetFiled(const string& ClassName, int pos);
			ClassFiled* GetFiled(const string& ClassName, string & FiledName);

			void RegisterClassMethod(const string& ClassName, const string& ClassMethodName, uintptr_t MethodPtr);
			int GetClassMethodCount(const string & ClassName);
			Method* GetClassMethod(const string& ClassName, int pos);
			Method* GetClassMethod(const string& ClassName, const string & MethodName);
		private:
			ClassFactory() {}
			~ClassFactory() {}
			map<string, create_object>ClassMap;
			map<string, vector<ClassFiled* >> _ClassFiled;
			map<string, vector<Method*>> _ClassMethod;
		};
	}

}