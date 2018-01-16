#include<iostream>
#include<cstring>
#include"account2.h"

using namespace std;

//메뉴 보여주기.
void Account::ShowMenu(){
	
	cout<<"\n == MENU ==\n";
	cout<<"1. 계좌 생성\n";
	cout<<"2. 계좌 확인\n";
	cout<<"3. 입금\n";
	cout<<"4. 출금\n";
}

//계좌 생성
void Account::AccountInit(){
	
	char temp[30];

	cout<<"id 입력(숫자) : ";
	cin>>id;
	cout<<"이름 입력 : ";
	cin>>temp;
	strcpy(name, temp);
	
	balance=0;
	cout<<"계좌가 생성되었습니다.\n\n";
}


//계좌 정보 확인
void Account::ShowAccount(){

	if(id == 0){
		cout<<"계좌가 없습니다.\n";
		return;
	}

	cout<<"id : "<<id<<endl;
	cout<<"이름 : "<<name<<endl;
	cout<<"잔액 : "<<balance<<endl;

}

//입금
void Account::Deposit(int money){
	balance+=money;
	cout<<"입금이 완료되었습니다.\n";
	cout<<"현재 잔액 : "<<balance;
}

//출금
void Account::Withdraw(int money){
	
	if(balance - money < 0){
		cout<<"잔액이 부족합니다.\n";
		return;
	}
	balance-=money;
	cout<<"출금이 완료되었습니다.\n";
	cout<<"현재 잔액 : "<<balance;
}
