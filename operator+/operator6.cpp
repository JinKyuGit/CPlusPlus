#include<iostream>

using namespace std;


class A {

	int x;

	public :
		A(int _x=0) : x(_x) {
			cout<<"A의 생성자 실행\n";
		}
		A& operator=(const A& ref){
			
			cout<<"A의 대입연산자 실행\n";
			this->x=ref.x;
			return *this;
		}

		void ShowData(){
			cout<<"x : "<<x<<endl;
		}
}; // A

class B : public A {
	
	int y;

	public :
		B(int _x, int _y=0) : A(_x), y(_y) {
			cout<<"B의 생성자 실행\n";
		}
		
		B& operator=(const B& ref){
			
			cout<<"B의 대입연산자 실행\n";
			A::operator=(ref);
			//상속구조에서
			//자손 클래스의 대입연산자 오버로딩을 위해서는
			//부모 클래스 대입연산자의 호출이 필요.
			this->y=ref.y;
			return *this;
		}

		void ShowData(){
			A::ShowData();
			cout<<"y : "<<y<<endl;
		}

}; //B


int main(){

	B b1(1, 2);
	B b2(2, 3);

	b2=b1;
	b2.ShowData();


	return 0;
}
