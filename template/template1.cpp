#include<iostream>

using namespace std;

template <typename T>  // == <class T>
//typename이라는 것을 통해
//아래 함수를 템플릿으로 정의한다는 의미.
//template <class T>와 동일.
T AddNum(T num1, T num2){

	return num1+num2;
}


int main(){

	int result1=AddNum<int>(1, 2);
	//템플릿이름<자료형>
	//해당 템플릿의 자료형을 결정.
	cout<<result1<<endl;
	

	return 0;
}
