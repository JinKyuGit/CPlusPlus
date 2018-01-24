#include<iostream>

using namespace std;

//템플릿의 특수화


template <class T> //typename T
void ShowData(T data){
	
	cout<<"일반템플릿\n";
	cout<<data<<endl;
}

//이 경우 char형 매개변수는
//아래 함수가 실행됨.
template<>
void ShowData(char ch){

	cout<<"특수템플릿\n";
	cout<<ch<<endl;
}


int main(){

	ShowData<int>(3);
	ShowData<char>('A');



	return 0;
}
