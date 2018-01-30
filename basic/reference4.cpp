#include<iostream>

using namespace std;


void Func(int num){

	cout<<num<<endl;
}

//반환형이 참조형이나 int형 변수로 받을 수도 있다.
int& ReturnRef(int &ref){

	return ref;
}


int main(){

	int arr[3]={1, 2, 3};

	int *ptr=arr;

	int &ref=arr[0]; 
	//int &ref=arr; 은 에러. arr은 주소값이기 때문.
	//변수인 arr[i]로 초기화해야한다.

	int i;
	for(i=0; i<3; i++){
		cout<<*(ptr+i)<<endl;
		cout<<ref+i<<endl; // 위와 동일하다.
	}
	//포인터와 유사하게 사용 가능.



	cout<<endl;

	Func(*ptr);
	Func(ref);

	
	int &ref2=ReturnRef(arr[0]);
	int num3=ReturnRef(arr[0]);
	num3++;
	cout<<"arr[0] : "<<arr[0]<<" "<<&(arr[0])<<endl;
	cout<<"ref2 : "<<ref2<<" "<<&(ref2)<<endl;
	cout<<"num3 : "<<num3<<" "<<&num3<<endl;

	string result=(&(arr[0]) == &(ref))? "true" : "false";
	string result2=((&arr[0]) == &(num3))? "true" : "false";
	cout<<"arr[0] == ref2 ? : "<<result<<endl;
	cout<<"arr[0] == num3 ? : "<<result2<<endl;
	//ref2 num3은 둘다 동일한 함수로
	//값을 받았으나
	//ref2는 arr[0]의 주소값을 받았고
	//num3은 arr[0]의 값을 받았으므로
	//arr[0]과 ref2의 주소값은 동일하나
	//num3은 값만 같을뿐, 주소값은 다르다

	return 0;
};
