#include<iostream>


inline int Add(int a, int b){

	return a+b;
}

//inline 키워드를 삽입하면
//컴파일러에 의해
//함수 호출문에 함수 코드를 작성한다.
//따라서 일반 함수에 비해 호출이 빠르다.
//다만, 컴파일러가 거절할 수 있음.

int main(){

	Add(3,5);

	
	return 0;
};
