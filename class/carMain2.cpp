#include<iostream>
#include"car2.h"

using namespace std;


int main(){

	Car c(0, 100);
	int fuel=10;
	int choice;

	while(1){
		cout<<"\n == 메뉴 ==\n";
		cout<<"1. 시동 켜기/끄기\n";
		cout<<"2. 현재 상태\n";
		cout<<"3. 가속\n";
		cout<<"4. 감속\n";
		cout<<"5. 충전\n";
		
		cout<<"메뉴 선택 : ";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:	
				c.StartUp();
				break;
			case 2:
				c.Show();
				break;
			case 3:
				c.Accel();
				break;
			case 4:
				c.Break();
				break;
			case 5:
				c.Charge(fuel);
				break;
		} 
	}

	return 0;
}	
