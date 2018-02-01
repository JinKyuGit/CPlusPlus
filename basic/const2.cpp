#include<iostream>

using namespace std;



int Add(const int &ref1, const int &ref2);


int main(){


	const int num=10;

//	int &ref=num; 에러 : const형 num을 참조자로 변환할 수 있음
	const int &ref=num; //OK

	cout<<ref<<endl;

//	int &ref2=20; //에러
	const int &ref2=20; //허용.
	//참조자는 본래 변수만 참조할 수 있으나
	//const형으로 인해. 우측의 상수를
	//상수화된 변수로 인식한다.
	//이를 가능하게 하기 위해
	//20은 임시변수가 되어 메모리상에 남게 된다.
	
	cout<<Add(10, 20)<<endl;
	//이것이 가능한 이유는
	//함수 호출문의 매개변수가 임시변수가 되어
	//함수 호출시 매개변수에 복사되기 때문.

	return 0;
}


int Add(const int &ref1, const int &ref2){

	return ref1+ref2;
}
