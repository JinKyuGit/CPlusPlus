#include<iostream>
#include<vector>

using namespace std;


int main(){

	vector<int> v; //백터 생성
	v.reserve(10); //벡터 공간 10개 할당.

	v.clear(); //백터 비우기.
	cout<<"size : "<<v.size()<<endl; //넣은 값의 갯수
	cout<<"capacity : "<<v.capacity()<<endl; // 용량

	int i;

	
	for(i=0; i<v.capacity(); i++){
		v.push_back(i+1); //값 넣기.
	}


	for(i=0; i<v.capacity(); i++){
		cout<<v[i]; // 배열처럼 사용 가능.
	}

	cout<<endl;
	cout<<"size : "<<v.size()<<endl;
	cout<<"capacity : "<<v.capacity()<<endl;

	return 0;
}
