#include<iostream>

//양의 정수 입력시
//이진수로 변환하여 출력.

using namespace std;


//이진수로 몇자리 수인지 계산.
int Count(int num){

	int	count=0;

	while(num >= 1){
		num/=2;
		count++;
	}

	return count;
}


int main(){

	int num;
	cout<<"양의 정수 입력 : ";
	cin>>num;

	int i;
	int count=Count(num);
	int result;

	cout<<"2진수 변환 : ";
	for(i=count-1; i>=0; i--){
		result=(num>>i)&1;
		cout<<result;
	}
	cout<<endl;


	return 0;
}
