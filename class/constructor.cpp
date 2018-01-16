#include<iostream>
using namespace std;

//생성자에 대한 이해.

class Temp {
	
	int num;

	public :
		Temp(){
			this->num=0;
			cout<<"디폴트 생성자 실행.\n";
		}
		Temp(int n) : num(n) {
			cout<<"매개변수 있는 생성자 실행.\n";
		}
		
		Temp(const Temp & copy) : num(copy.num){
			cout<<"디폴트 복사생성자 실행.\n";
		}
		~Temp(){
			cout<<"소멸자 실행.\n";
		}

}; // Temp


Temp TempFunc(Temp temp){
	
	cout<<"TempFunc 실행\n";
	return temp;
}


int main(){

	Temp t1;
	Temp t2(10);
	Temp t3(t2);
	TempFunc(t3);
	//복사 생성자를 통해 매개변수 temp에 t3이 복사됨.
	//함수 내부 실행됨
	//return문 :  복사생성자를 통해 임시객체에 temp가 복사됨.
	return 0;
}
