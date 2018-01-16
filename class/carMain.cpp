#include<iostream>
#include"car.h"

using namespace std;


int main(){

	Car c;
	int choice;

	while(1){
		c.Show();
		cout<<"선택 : ";
		cin>>choice;
		
		switch(choice){
			case 1:
				c.Accel();
				break;
			case 2:
				c.Break();
				break;
			default :
				break;
		}
	}
	return 0;
}
