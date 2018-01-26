#include<iostream>

using namespace std;

//여러 개의 catch문 구성.



int main(){
	
	
	int num;

	cout<<"숫자 입력(1~10) : ";
	cin>>num;

	try{
		//숫자가 5보다 큰 경우 int 예외
		if(num > 5){
			throw -1;
		//숫자가 5보다 작은 경우 char 예외
		}else if(num < 5) {
			throw 'a';
		//숫자가 5이거나 실수인경우 double 예외
		}else {
			throw -1.1;
		}
	}catch(int ex){
		cout<<ex<<"예외\n";
	}catch(char ex){
		cout<<ex<<"예외\n";
	}catch(double ex){
		cout<<ex<<"예외\n";
	}




	return 0;
}
