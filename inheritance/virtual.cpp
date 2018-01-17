#include<iostream>

using namespace std;


//가상함수와 아닌 경우 비교.
//A 를 B가 상속 (가상함수x)
//C 를 D가 상속 (가상함수o)

class A {

	public :
		void Show(){
			cout<<"A\n";
		}
		~A(){
			cout<<"A 소멸\n";
		}

}; //A

class B :public A {

	public :
		 void Show(){
			cout<<"B\n";
		}
		 ~B(){
			cout<<"B 소멸\n";
		 }

}; //B


class C {

	public :
		//A 와의 차이점.
		//순수 가상함수 : virtual void Show() const = 0;
		//이 경우 C는 객체 생성 제한됨.
		virtual void Show(){
			cout<<"C\n";
		}
		virtual ~C(){
			cout<<"C 소멸\n";
		}

}; //C

class D : public C {

	public :
		//기초 클래스인 C에서
		//가상 함수로 선언하였으므로
		//별도로 virtual 을 명시하지 않아도
		//가상함수가 된다.
		void Show(){
			cout<<"D\n";
		}

		~D(){
			cout<<"D 소멸\n";
		}

}; //D

int main(){

//  A * ptr1=new A;
//	B * ptr2=ptr1; 컴파일 에러
//	ptr1의 포인터 형이 A  이므로. 에러

	A * ptr1=new A;
	A * ptr2=new B;

	ptr1->Show(); //A 출력.
	ptr2->Show(); //A 출력.
	//이유 : 포인터 자료형에 따라 함수가 결정
	//정적 바인딩.

	C * ptr3=new C;
	C * ptr4=new D;

	ptr3->Show(); // C 출력
	ptr4->Show(); // D 출력
	//이유 : 가상함수로 선언되어
	//포인터 형이 아니라 실제 가리키는 객체에 따라 함수 결정.
	//동적 바인딩.
	
	delete ptr2;
	//B -> A순으로 소멸되어아 하나
	//가상 소멸자가 없어 A의 소멸자만 실행됨.
	delete ptr4;
	//D -> C 순으로 소멸자 실행.
	return 0;
}
