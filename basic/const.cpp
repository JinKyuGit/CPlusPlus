#include<iostream>


using namespace std;


int main(){

	const char * name="이진규";
	

	name="변경";
	//* name="변경2"; - error
	//포인터를 const 선언했으므로
	//해당 포인터의 변경은 불가능.
	//다만 값의 변경은 가능.
	cout<<"name : "<<name<<endl;	

	return 0;
}
