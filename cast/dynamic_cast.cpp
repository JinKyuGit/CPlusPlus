#include<iostream>

using namespace std;


class A {

	int num;

	public :
		A(int _num) : num(_num) { }

		void ShowNum(){
			cout<<"A ShowNum() : "<<num<<endl;
		}

		void SetNum(int _num){
			num=_num;
		}

}; //A

class B : public A {

	int num2;

	public :
		B(int _num, int _num2) : A(_num), num2(_num2) { }

		void ShowNum(){
			A:: ShowNum();
			cout<<"B ShowNum() : "<<num2<<endl;
		}

}; // B




int main(){

	B * b= new B(1, 3);
	b->ShowNum();

	//유도 클래스의 객체를 기초 클래스의 객체로 형변환
	A * a=dynamic_cast<A*>(b);
//	A * a=(A*)b; 와 동일
	
	b->SetNum(2);

	a->ShowNum();
	b->ShowNum();
	
	
	delete b;

	return 0;
}
