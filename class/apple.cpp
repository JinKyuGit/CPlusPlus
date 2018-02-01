#include<iostream>

using namespace std;

class Seller {

	int numOfApple;
	int price;
	int money;

	public :
		Seller(int _numOfApple, int _price)
		: numOfApple(_numOfApple), price(_price), money(0)
		{}
			
		int GetNumOfApple(){
			return numOfApple;
		}

		void SetNumOfApple(int num){
			numOfApple=num;
		}

		int GetPrice(){
			return price;
		}

		void SetPrice(int p){
			price=p;
		}

		int GetMoney(){
			return money;
		}

		void SetMoney(int m){
			money=m;
		}
			
		void ShowInfo(){
			cout<<"\n == 판매자 정보 ==\n";
			cout<<"사과 가격 : "<<price<<endl;
			cout<<"사과 수량 : "<<numOfApple<<endl;
			cout<<"소지금 : "<<money<<endl;
			
		}

}; //Seller

class Buyer {

	int money;
	int numOfApple;

	public :
		Buyer(int _money) : money(_money), numOfApple(0) {
		}
		
		int GetMoney(){
			return money;
		}

		void SetMoney(int m){
			money=m;
		}

		int GetNumOfApple(){
			return numOfApple;
		}
		
		void SetNumOfApple(int num){
			numOfApple=num;
		}

		void ShowInfo(){
			cout<<"\n == 구매자 정보 ==\n";
			cout<<"소지 금액 : "<<money<<endl;
			cout<<"소지 사과 : "<<numOfApple<<endl;
		}

}; //Buyer


class Controller {
	
	public :
		void Purchase(Seller &s, Buyer &b, int num){
			
			//필요 가격..
			int money=s.GetPrice()*num;
			
			if(s.GetNumOfApple() < num){
				cout<<"수량이 부족합니다.\n";
				cout<<"재고 : "<<s.GetNumOfApple()<<endl;
				return;
			}
			if(b.GetMoney() < money){
				cout<<"구매자의 잔액이 부족합니다.\n";
				cout<<"필요 금액 : "<<money<<endl;
				cout<<"잔액 : "<<b.GetMoney()<<endl;
				return;
			}
			
			//소지금액, 사과 갯수 처리
			s.SetMoney(s.GetMoney()+money);
			b.SetMoney(b.GetMoney()-money);

			s.SetNumOfApple(s.GetNumOfApple() - num);
			b.SetNumOfApple(b.GetNumOfApple() + num);
		}

}; //Controller

int main(){

	Seller s(20, 1000);
	Buyer b(15000);
	Controller cont;
	int num;

	while(1){
		s.ShowInfo();
		b.ShowInfo();
		cout<<"\n구입할 갯수(종료 0) : ";
		cin>>num;
		
		if(num == 0){
			break;
		}

		cont.Purchase(s, b, num);

	}

	cout<<"프로그램 종료\n";



	return 0;
}

