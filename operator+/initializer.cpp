#include<iostream>

using namespace std;


class A {

	int num;

	public :
		A(int _num=0) : num(_num) {
			cout<<"A 기본 생성자 실행\n";
		}

		A(const A & copy) : num(copy.num) {
			cout<<"A 복사 생성자 실행\n";
		}

		A& operator=(const A& ref){
			cout<<"A 대입 연산자 실행\n";
			this->num=num;
			return *this;
		}

}; //A

class B {
	
	A a;

	public :
		B(A & copy) {
			a=copy; //선언과 초기화가 각각 별도로 진행.
		}
}; // B


class C {
	
	A a;

	public :
		C(A& copy) : a(copy) {} //선언과 동시에 초기화됨.
}; // C


int main(){
	
	A a(1);
	cout<<" > A 생성\n";
	B b(a);
	cout<<" > B 생성 이니셜라이저x\n";
	C c(a);
	cout<<" > C 생성 이니셜라이저o\n";


	return 0;
}
