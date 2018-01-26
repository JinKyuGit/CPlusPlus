#include<iostream>

using namespace std;


int main(){

	int num1, num2;
	double result;

	cout<<"숫자 입력 : ";
	cin>>num1;

	cout<<"나눌 숫자 : ";
	cin>>num2;

	try {
		if(num2 == 0){
			throw num2; //catch문의 ex에 num2가 대입됨.	
		}
		//예외 상황이 발생하면 아래의 두 문장은 실행되지 않음.
		//catch로 넘어감.
		result=(double)num1/num2;
		cout<<"값 :"<<result<<endl;
	} catch(int ex) {
		cout<<ex<<" 으로 나눌 수 없습니다.\n";
	}
	
	return 0;
}
