


class Account {

	private :
		int id;
		char name[30];
		int balance;
	public :
		void AccountInit();
		void ShowMenu();
		void ShowAccount();
		void Deposit(int money);
		void Withdraw(int money);
		
}; //class
