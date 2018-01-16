#include<iostream>
#include"car.h"

using namespace std;


void Car::Show(){

	cout<<"\n == 현재상태 ==\n";
	cout<<"속도 : "<<this->speed<<endl;
	cout<<"연료 : "<<this->fuel<<endl;
	cout<<" ========= \n";
	cout<<"1. 가속\n";
	cout<<"2. 감속\n";
}


void Car::Accel(){

	this->speed+=10;
	this->fuel-=5;
}

void Car::Break(){
	
	if(this->speed < 10){
		this->speed=0;
		cout<<" stop\n";
		return;
	}
	
	this->speed-=10;
}


