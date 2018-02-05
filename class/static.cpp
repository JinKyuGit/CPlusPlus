#include<iostream>

using namespace std;


class A {

	public :
		static int count;

		A(){
			count++;
		}

		void Show(){
			cout<<this->count<<endl;
		}

		~A(){}
}; //A

int A::count=0;
//반드시 필요
//자료형 클래스명:: 변수명=초기값

int main(){

	A * ptr1=new A;
	A * ptr2=new A;


	ptr1->Show();
	ptr2->Show();
	

	delete ptr1;

	ptr2->Show();
	//ptr1이 가리키던 객체를 반환했음에도 불구하고
	//출력이되는 이유 : static 변수는
	//클래스의 멤버가 아니다.
	cout<<A::count<<endl;
	//static 변수는 클래스명:: 으로 접근 가능.`
    
	return 0;
}
