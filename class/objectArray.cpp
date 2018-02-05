#include<iostream>

using namespace std;

//객체 배열 선언 및 활용.


class A {

	int num;

	public :
	  A () {}
	  
	  A (int _num) : num(_num) {}
	  
	  void SetNum(int num){
			this->num=num;
	  }

	  int GetNum(){
			return this->num;
	  }
	  ~A() { }
}; // A


int main(){

	A arr1[5]; //객체 배열
	A * arr2[5];//객체 포인터 배열

	int i;
	//객체 배열인 경우
	//기본 생성자로만 생성됨.
	//따라서 멤버변수의 초기화 과정 별도 필요.
	for(i=0; i<5; i++){
		arr1[i].SetNum(i);
		cout<<arr1[i].GetNum()<<endl;
	}
	
	cout<<endl;

	//객체 포인터 배열의 경우
	//각각의 요소에 메모리 할당과정 필요.
	for(i=0; i<5; i++){
		arr2[i]=new A(i);
		cout<<arr2[i]->GetNum()<<endl;
	}


	
	for(i=0; i<5; i++){
		delete arr2[i];
	}

	return 0;
}
