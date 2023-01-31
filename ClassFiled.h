#pragma once 

#include<string>
using namespace std;
namespace Learn {
	namespace Filed {
		class ClassFiled {
		public:
			ClassFiled(): name(""),type(""),offset(0){}
			ClassFiled(const string & Name,const string & Type, const size_t Offset):
				name(Name),type(Type),offset(Offset){}
			~ClassFiled(){}
			const string& GetName() { return this->name; }
			const string& GetType() { return this->type; }
			const size_t& GetOffset() { return this->offset; }
		private:
			string name;
			string type;
			size_t offset;
		};
	}
}