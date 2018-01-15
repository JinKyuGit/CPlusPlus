#include<iostream>



namespace A{
	void Func(int a){
		std::cout<<"nameSpace A의 Func(int a) 실행\n";
	}
}

namespace B{
	void Func(int a){
		std::cout<<"namespace B의 Func(int a) 실행\n";
	}
}

int main(){

	A::Func(1);
	B::Func(1);


	return 0;
}
