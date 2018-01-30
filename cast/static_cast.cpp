#include<iostream>

using namespace std;


class Parent {

	public :
		void Intro(){
			cout<<"I'm parent\n";	
		}




}; // parent


class Child : public Parent {

	public :
		void Intro(){
			cout<<"I'm child\n";
		}



}; // child




int main(){

	Parent * p1=new Child();

	p1->Intro();

	//기초 클래스 형으로 선언한 유도 클래스 객체를
	//유도 클래스 형으로 변환
	Child * p2=static_cast<Child*>(p1);

	p2->Intro();


	int num1=10;
	int num2=20;

	//기본 자료형의 형변환에도 사용.
	double num3=static_cast<double>(num1)/num2;
	cout<<num3<<endl;


	return 0;
}
