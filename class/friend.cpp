#include<iostream>

using namespace std;

class B; //friend 선언을 위한 B클래스 선언

class A {
	int num;
	friend class B; //B클래스를 friend로 선언.

	public :
		A(){}
		A(int _num) : num(_num) { }
}; //A

class B {

	public :
		B b(){
			
		}

		void ShowA(A &a){
			cout<<a.num<<endl;
			//friend선언으로 인해
			//B클래스에서 A 클래스의 private 멤버에 접근가능.
		}



}; // B

int main(){


	A a(3);
	B b;

	b.ShowA(a);



	return 0;
}
