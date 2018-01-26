#include<iostream>

using namespace std;

//예외 상황과 처리부가 다른 경우



double Divide(int num1, int num2){

	if(num2 == 0){
		throw num2;
		//이 함수내에 예외 처리문이 없으므로
		//이 경우 이 함수를 호출한 곳으로
		//돌아가 예외처리문에 의해 처리된다.
	}

	return num1/num2;
}




int main(){


	int num1, num2;
	double result;

	cout<<"숫자 입력 : ";
	cin>>num1;
	cout<<"나눌 숫자 : ";
	cin>>num2;

	try {
		result=Divide(num1, num2);
		//호출한 함수내에서 예외가 발생하는 경우
		//아래 문장은 실행되지 않고 catch문으로 넘어간다.
		cout<<"값 : "<<result<<endl;
	} catch (int ex){
		cout<<ex<<"로 나눌 수 없습니다.\n";
	}

	return 0;
}
