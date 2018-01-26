#include<iostream>


using namespace std;

//예외처리 부모클래스.
class AccountException {

	public :
		//순수 가상함수 처리.
		virtual void ShowMessage()=0;

}; //AccountException

//예외처리 1 - 입금 오류
class DepositException : public AccountException {

	int money;

	public :
		DepositException(int _money) : money(_money){ }
		void ShowMessage(){
			cout<<"0 이하의 숫자는 입력이 불가능 합니다.\n";
			cout<<"입력하신 금액 : "<<money<<endl;
		}
}; //DepositException

//예외처리 2 - 출금 오류
class WithdrawException : public AccountException {
	
	int balance;

	public :
		WithdrawException(int _balance) : balance(_balance) { }
		void ShowMessage(){
			cout<<"잔액이 부족합니다.\n";
			cout<<"잔액 : "<<balance<<endl;
		}
}; //WithdrawException


//계좌 클래스
class Account {

	int balance;

	public :
		Account() {}
		void Deposit(int money){
			
			//0 이하의 숫자 입력시 예외처리.
			if(money <= 0){
				throw DepositException(money);	
			}
			balance+=money;
		}
		
		void Withdraw(int money){
			
			//잔액 부족시 예외처리.
			if( (balance - money) < 0){
				throw WithdrawException(balance);
			}

			balance-=money;
		}


}; // Account


int main(){

	Account acc;
	int money;

	cout<<"입금하실 금액 : ";
	cin>>money;

	try{
		acc.Deposit(money);
	}catch(AccountException& ae){
		ae.ShowMessage();
	}
	
	cout<<"출금하실 금액 : ";
	cin>>money;

	try{
		acc.Withdraw(money);
	}catch(AccountException& ae){
		ae.ShowMessage();
	}


	return 0;
}
