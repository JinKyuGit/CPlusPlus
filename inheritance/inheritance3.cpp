#include<iostream>
#include<cstring>

using namespace std;

class A {

	int num;

	public :
	 A(int _num) : num(_num){
		 cout<<"A 생성자 실행.\n";
	 }

	 ~A(){
		cout<<"A 소멸자 실행.\n";
	 }

	 int GetNum(){
		 cout<<"A의 GetNum 실행.\n";
		return this->num;
	 }

	 void ShowNum(){
		cout<<GetNum()<<endl;
		cout<<"A의 ShowNum 실행.\n";
	 }

}; //A

class B : public A {
	
	public :
		B(int _num) : A(_num) {
			cout<<"B 생성자 실행.\n";
		}

		~B(){
			cout<<"B 소멸자 실행.\n";
		}

		void Temp(){
			ShowNum();
			//어느 함수가 실행되는지 확인
		}

		void ShowNum(){
			cout<<GetNum()<<endl;
			cout<<"B의 ShowNum 실행.\n";
		}

		int GetNum(){
			cout<<"B의 GetNum() 실행.\n";
			return A::GetNum();
		}

}; //B

int main(){
	
	B b(1);
	b.Temp();


	return 0;
}
