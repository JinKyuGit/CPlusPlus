#include<iostream>


using namespace std;


template <class T1, class T2>
void ShowData(T1 data1, T2 data2){

	cout<<(T1)data1<<", "<<(T2)data2<<endl;
}



int main(){

	ShowData<char, int>('A', 5);
	ShowData<int, double>(1, 1);



	return 0;
}
