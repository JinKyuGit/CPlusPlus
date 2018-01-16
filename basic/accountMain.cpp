#include<iostream>
#include"account2.h"


using namespace std;



int main(){

	Account acc;
	int choice;
	int money;

	while(1){
		acc.ShowMenu();
		cout<<"선택(종료는 0) : ";
		cin>>choice;
		
		if(choice == 0){
			cout<<"프로그램을 종료합니다.\n";
			break;
		}
		switch(choice){
			case 1:
				acc.AccountInit();
				break;
			case 2:
				acc.ShowAccount();
				break;
			case 3:
				cout<<"입금하실 금액 : ";
				cin>>money;
				acc.Deposit(money);
				break;
			case 4:
				cout<<"출금하실 금액 : ";
				cin>>money;
				acc.Withdraw(money);
				break;
		} //switch
	} //while

	return 0;
}
