#include<iostream>

using namespace std;

int& Func1(int & num){
	
	num++;
	return num;
}

int Func2(int & num){

	num++;
	return num;
}


int main(){

	int num1=10;
	int &ref=Func1(num1); 
	//ref에는 num1의 주소값이 반환.
	//즉 ref는 num1의 레퍼런스가 됨.
	cout<<"num1 : "<<num1<<"\n";	
	cout<<"ref : "<<ref<<"\n";
	
	int num2=Func2(num1);
	//num2는 num1의 값은 받지만
	//별개의 변수임.
	cout<<"num2 : "<<num2<<"\n";
	num1++;
	
	cout<<"num2 : "<<num2<<"\n";
	

	return 0;
}
