#include<iostream>

using namespace std;



namespace A{
	namespace B{
		namespace C{
			void Func(){
				cout<<"A::B::C의 Func() 실행\n";
			}
		}
	}
}

int main(){

	A::B::C::Func();
	
	namespace ABC=A::B::C;

	ABC::Func();


	return 0;
}
