#pragma once 
#include <string>
using namespace std;

namespace Learn {
	namespace ClassMethod {
		class Method {
		public:
			Method():MethodName(""),MethodPtr(0) {}
			Method(const string & name,uintptr_t method):MethodName(name),MethodPtr(method){}
			~Method(){}
			const string& GetMethodName() { return this->MethodName; }
			uintptr_t GetMethodPtr() { return this->MethodPtr; }
		private:
			string MethodName;
			uintptr_t MethodPtr;
		};
	}
}