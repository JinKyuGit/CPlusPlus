#include<iostream>



void Func(int a){

	std::cout<<"Func(int a) 실행.\n";

}
void Func(int a, int b){

	std::cout<<"Func(int a, int b) 실행.\n";
}



int main(){

	std::cout<<"함수 오버로딩 실험.\n";
	Func(1);
	Func(1, 2);


	return 0;
}


