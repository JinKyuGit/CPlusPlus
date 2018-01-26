#include<iostream>
#include<new>

using namespace std;




int main(){

	int num=1;

	try{	
		//컴퓨터가 터질것같아서 무한반복 해제.
		while(num < 10){
			cout<<"count : "<<num<<endl;
			new int[10000][10000];
			num++;
		} //while
	} catch (bad_alloc &bad){
			cout<<"할당 불가\n";
	}

	return 0;
}
