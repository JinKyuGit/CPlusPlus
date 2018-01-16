#include<iostream>
#include"car2.h"

using namespace std;

//차의 상태
void Car:: Show(){

	if(this->flag == false){
		cout<<"시동이 꺼져있습니다.\n";
		cout<<"연료 : "<<this->fuel<<endl;
	} else {
		cout<<"속도 : "<<this->speed<<endl;
		cout<<"연료 : "<<this->fuel<<endl;
	}
}

//시동 켜거나 끄기
void Car:: StartUp(){

	if(this->flag == false){
		this->flag=true;
		cout<<"시동이 켜졌습니다.\n";
	}else {
		if(this->speed != 0){
			cout<<"주행 중에는 시동을 끌 수 없습니다.\n";
			return;
		}
		this->flag=false;
		cout<<"시동이 꺼졌습니다.\n";
	}
}

//가속
void Car:: Accel(){

	if(this->flag == false){
		cout<<"시동을 먼저 켜 주십시요.\n";
		return;
	}else if(this->fuel == 0){
		cout<<"연료가 부족합니다.\n";
		Stop();
		return;
	}else {
		this->speed+=10;
		this->fuel-=5;
		cout<<"현재 속도 : "<<this->speed<<endl;
		cout<<"현재 연료 : "<<this->fuel<<endl;
	}
}

//감속
void Car:: Break(){

	if(this->speed < 10){
		this->speed=0;
	}else {
		this->speed-=10;
	}
	cout<<"현재 속도 : "<<this->speed<<endl;
	cout<<"현재 연료 : "<<this->fuel<<endl;
}

//정지
void Car::Stop(){

	this->speed=0;
	cout<<"차가 멈췄습니다.\n";
	cout<<"연료 상태 : "<<this->fuel<<endl;
}

//충전
void Car:: Charge(int charge){
	if(this->flag == true){
		cout<<"시동을 꺼 주십시오.\n";
		return;
	}

	this->fuel+=charge;
	
	if(fuel > 100){
		this->fuel=100;
	}

	cout<<"연료가 충전되었습니다.\n";
	cout<<"연료 : "<<this->fuel<<endl;
}


