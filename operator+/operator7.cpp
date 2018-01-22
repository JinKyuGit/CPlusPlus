#include<iostream>

using namespace std;

class A {

	int x;

	public :
		A(int _x) : x(_x) {
			cout<<"기본 생성자 실행\n";
		}
		A(const A &copy) : x(copy.x) {
			cout<<"복사 생성자 실행\n";
		}
		A& operator=(const A & ref) {
			cout<<"대입 생성자 실행\n";
			this->x=ref.x;
			return *this;
		}
		
}; //A

int main(){

	A a1(1);
	A a2(a1);
	
	a1=a2;



	return 0;
}
