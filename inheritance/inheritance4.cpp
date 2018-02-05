#include<iostream>

using namespace std;

class A {

	int num1;

	public :
		A(){
			cout<<"A 생성자 실행\n";
		}

		A(int _num1) : num1(_num1) {
			cout<<"A 생성자 실행\n";
		}

		virtual ~A(){
			cout<<"A 소멸자 실행\n";
		}

		virtual void ShowInfo(){
			cout<<"A의 ShowInfo()\n";
		}

}; //A

class B : public A {

	int num2;

	public :	
		B(){
			cout<<"B 생성자 실행\n";
		}

		B(int _num2) : num2(_num2) {
			cout<<"B 생성자 실행\n";
		}

		~B(){
			cout<<"B 소멸자 실행\n";
		}

		void ShowInfo(){
			cout<<"B의 ShowInfo()\n";
		}

}; // B


class Controller {

	public : 
		A * ptr[10];

}; //Controller

int main(){

	Controller c;

	c.ptr[0]=new A();
	c.ptr[1]=new B();

	c.ptr[0]->ShowInfo();
	c.ptr[1]->ShowInfo();
	//virtual 선언으로 인해
	//ptr[1]의 ShowInfo는 B클래스의 함수가 바인딩 됨.(정적 바인딩)

	//본래 컴파일러는 포인터 형에 따라 함수를 결정하지만
	//virtual 선언이 되어있는 경우(가상함수)
	//실제 가리키는 객체에 해당하는 함수를 실행한다.(동적 바인딩)

	//B클래스의 v-table에는 A클래스의 ShowInfo가 없음.


	//오버라이딩 하려는 함수와
	//소멸자에 대해 virtual선언을 해야함.
	delete c.ptr[0];
	delete c.ptr[1];


	return 0;
}
