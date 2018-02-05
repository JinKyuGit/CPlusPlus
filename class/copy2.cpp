#include<iostream>

using namespace std;


//복사 생성자의 호출시점 확인.

//호출 시점을 확인하기 위한 전역 변수.
int count=1;

class A {

	int num;

	public :
		A(){
			num=0;
			cout<<"기본 생성자 실행\n";
		}

		A(int _num) : num(_num){
			cout<<"매개변수있는 생성자 실행\n";
		}

		A(const A& copy) : num(copy.num) {
			cout<<"복사 생성자 실행 count : "<<count<<endl;
			count++;
		}
	
		A ReturnA(const A copy){
			//복사 생성자 실행1 - 매개변수로 객체를 받을때.
			cout<<"함수 진입\n";
			A a(copy); //복사 생성자 실행 2 - 직접 실행.
			cout<<"함수 탈출(리턴 전)\n";
			return copy;
			//복사생성자 실행3 - 객체의 리턴(임시객체)
		}

		void ShowNum(){
			cout<<num<<endl;
		}
}; //A

int main(){

	A a1;
	A a2(2);

	a2.ReturnA(a1); //대입이 이루어지지않아 바로 소멸.

	return 0;
}

