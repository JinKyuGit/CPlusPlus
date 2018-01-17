#include<iostream>
#include<cstring>

using namespace std;

//Account 클래스와 AccountHandler 클래스 따로 생성.


class Account {

	int id;
	char name[30];
	int balance;

	public :
		Account(){}
		Account(int _id, const char * _name, int _balance)
			: id(_id), balance(_balance)
		{
			strcpy(this->name, _name);
		}

		void ShowInfo(){
			cout<<" == 계좌 정보 ==\n";
			cout<<"ID : "<<this->id<<endl;
			cout<<"name : "<<this->name<<endl;
			cout<<"balance : "<<this->balance<<endl;
		}

		void Deposit(int money){
	
			this->balance+=money;

		}

		int Withdraw(int money){
			
			if(this->balance - money < 0){
				//잔액 부족
				return 0;
			}

			this->balance-=money;
		}

		~Account(){}


}; //Account;

class AccountHandler {

	Account * acc[10];
	int count;
	//배열 index = 계좌 id

	public : 
		AccountHandler(){
			
			int i;
			for(i=0; i<10; i++){
				this->acc[i]=NULL;
			}

			this->count=0;
		}

		void ShowMenu(){
	
			cout<<"\n == MENU ==\n";
			cout<<"1. 계좌 개설\n";
			cout<<"2. 계좌 정보 확인\n";
			cout<<"3. 입 금\n";
			cout<<"4. 출 금\n";
		}


		void MakeAccount(){
			
			
			if(this->count == 9){
				cout<<"더이상 계좌 생성이 불가능합니다.\n";
				return;
			}

			char name[30];
			cout<<"\n == 계좌 생성 ==\n";
			cout<<"이름 입력 : ";
			cin>>name;
			
			acc[count]=new Account(count, name, 0);

			if(NULL == acc[count]){
				cout<<"계좌 생성에 실패하였습니다.";
				cout<<" 관리자에게 문의하세요.\n";
			}else {
				cout<<"계좌를 생성하였습니다.\n";
				cout<<"생성된 계좌의 ID는 "<<count<<" 입니다.\n";
				(this->count)++;
			}

		}
		
		void ShowAccount(){
			int id;
			cout<<"계좌 id 입력 :";
			cin>>id;

			if(NULL == acc[id]){
				cout<<"일치하는 계좌가 없습니다.\n";
				return;
			}
				acc[id]->ShowInfo();
		}

		void Deposit(){
			int id;
			cout<<"입금하실 계좌의 id 입력 : ";
			cin>>id;
			
			if(NULL == acc[id]){
				cout<<"일치하는 id가 없습니다.\n";
				return;
			}
			
			int money;
			cout<<"입금하실 금액 : ";
			cin>>money;
			
			acc[id]->Deposit(money);
			cout<<"입금이 완료되었습니다.\n";

		}

		void Withdraw(){

			int id;
			cout<<"출금하실 계좌의 id 입력 : ";
			cin>>id;
			
			if(NULL == acc[id]){
				cout<<"일치하는 id가 없습니다.\n";
				return;
			}
	
			int money;
			cout<<"출금하실 금액 : ";
			cin>>money;
			
			int result=acc[id]->Withdraw(money);

			if(result == 0){
				cout<<"잔액이 부족합니다.\n";
			}else {
				cout<<"출금이 완료되었습니다.\n";
			}



		}

		~AccountHandler(){
			int i;
			for(i=0; i<=this->count; i++){
				delete acc[count];
			}
		}

}; //AccountHandler;

int main(){

	AccountHandler manager;
	
	int choice;

	while(1){
		manager.ShowMenu();

		cout<<"선택(종료는 0) : ";
		cin>>choice;

		if(choice == 0){
			cout<<"프로그램을 종료합니다.\n";
			break;
		}

		switch(choice){
			case 1:
				manager.MakeAccount();
				break;
			case 2:
				manager.ShowAccount();
				break;
			case 3:
				manager.Deposit();
				break;
			case 4:
				manager.Withdraw();
				break;
			default : 
				cout<<"잘못 입력하셨습니다.";
				break;
		}
	}


	return 0;
}

