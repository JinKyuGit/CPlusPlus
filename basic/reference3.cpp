#include<iostream>

using namespace std;




int main(){

	int num1=10;
	int num2=20;


	cout<<"num1 : "<<num1<<endl;
	cout<<"num2 : "<<num2<<endl;


	int & ref1=num1;

	cout<<"ref1 = num1로 초기화\n";
	cout<<"ref1 : "<<ref1<<endl;

	ref1=num2;
	//레퍼런스는 한번 설정된 이후
	//변경될 수 없다.
	//즉 이 경우 ref1이 num2를 가리키는 것이 아니라
	//ref1이 가리키는 num1의 값이 num2의 값으로 변경된다.
	//const int & ref로 할 경우 ref를 통한
	//값 변경이 불가능해진다.
	cout<<"ref1 = num2 후\n";

	cout<<"ref1 : "<<ref1<<endl;

	cout<<"num1 : "<<num1<<endl;
	cout<<"num2 : "<<num2<<endl;



	return 0;
}
