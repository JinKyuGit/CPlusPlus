#include<iostream>
#include<cstring>
using namespace std;

typedef struct _account {

	char name[30];
	int balance;
	char id[30];

} Account;


int MakeAccount();
void Deposit(int id, int money);
void Withdraw(int id, int money);
void ShowAccount(int id);
void ShowMenu();

//계좌 10개.
Account acc[10];
int count=0;

int main(){

	int choice;
	int id;
	int money;
	while(1){
		ShowMenu();
		cout<<"선택(종료 0) : ";
		cin>>choice;

		if(choice == 0){
			break;
		}
		
		switch(choice){
			case 1:	
				id=MakeAccount();
				break;
			case 2:
				cout<<"입금하실 금액 : ";
				cin>>money;
				Deposit(id, money);
				break;
			case 3:
				cout<<"출금하실 금액 : ";
				cin>>money;
				Withdraw(id, money);
				break;
			case 4:
				ShowAccount(id);
				break;
		} //switch
	} // while


	return 0;
}

//메뉴 띄우기.
void ShowMenu(){
	cout<<"1. 계좌개설\n";
	cout<<"2. 입금\n";
	cout<<"3. 출금\n";
	cout<<"4  계좌정보 확인\n";
}

//계좌 개설
int MakeAccount(){
	
	int id=count;
	char name[30];
	int balance;
	cout<<"이름 : ";
	cin>>name;
	cout<<"잔액 : ";
	cin>>balance;

	strcpy(acc[id].id, name);
	acc[id].balance=balance;
	::count++;
	return id;
}

//계좌정보 확인
void ShowAccount(int id){
	
	cout<<"=== 계좌 정보 ===\n";
	cout<<"아이디 : "<<acc[id].id<<"\n";
	cout<<"이름 : "<<acc[id].name<<"\n";
	cout<<"잔액 : "<<acc[id].balance<<"\n";
}

//입금
void Deposit(int id, int money){
	acc[id].balance+=money;
	cout<<"입금 완료\n";
}
//출금
void Withdraw(int id, int money){
	acc[id].balance-=money;
	cout<<"출금 완료\n";
}
