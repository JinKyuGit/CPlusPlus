#include<iostream>

using namespace std;

//class 에서의 this : 객체 자기 자신을 가리키는 포인터
//컴파일러는 컴파일시 매개변수에
//자신을 this라는 이름의 매개변수로 삽입.


class A {

	int num;

	public :
		A(){
			cout<<"생성자1 실행\n";
			this->num=0;
		}
		A(int _num) : num(_num) { 
			cout<<"생성자2 실행\n";
		}
		~A(){
			cout<<"소멸자 실행\n";
		}
		A& ReturnA(int num){
			this->num+=num;
			return *this;
			//return *this; 이 문장은
			//객체의 자기 자신을 참조할 정보를 반환.
		}

		void SetNum(int num){
			this->num=num;
		}

		void ShowNum(){
			cout<<num<<endl;
		}

		A(const A& a) : num(a.num) {
	
			cout<<"복사 생성자 실행\n";
		}


}; //A

int main(){

	A a1;
	A a2=a1.ReturnA(3); 
	//A a2(a1.ReturnA(3)); //동일
	A * ptr=&(a1.ReturnA(4));
	
	/*
	 * ReturnA는 객체 자기자신을 참조할 정보를 반환하나
	 * 받는 자료형이 객체인 경우
	 * 복사 생성자를 통해 복사됨.
	 */

	cout<<&a1<<endl;
	cout<<&a2<<endl;
	cout<<ptr<<endl;
	
	a1.ShowNum();
	a2.ShowNum();
	ptr->ShowNum();

	return 0;
}
