#include<iostream>

using namespace std;

void Swap(int & num1, int & num2){
	
	int temp=num1;
	num1=num2;
	num2=temp;
}

int main(){

	int num1=10;
	int num2=20;
	int &ref1=num1;
	int &ref2=num2;

	cout<<"num1 : "<<num1<<" num2 : "<<num2<<"\n";
	cout<<"ref1 : "<<ref1<<" ref2 : "<<ref2<<"\n";
	
	Swap(ref1, ref2); // Swap(num1, num2)와 동일.

	cout<<" == Swap ==\n";
	cout<<"num1 : "<<num1<<" num2 : "<<num2<<"\n";
	cout<<"ref1 : "<<ref1<<" ref2 : "<<ref2<<"\n";

	return 0;
}
