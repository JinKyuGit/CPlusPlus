#include<iostream>

using namespace std;


class A {

	public :
		
		void Show(char * name){
			cout<<"name : "<<name<<endl;
		}

}; //A


int main(){


	const char * name="홍길동";
	
	A a;

//	a.Show(name); 컴파일에러
//	매개변수로 char * 을 선언했으나
//	const char * 을 보냈기 때문.

	a.Show(const_cast<char*>(name));
	//const 속성을 없애는 형변환.


	return 0;
};
