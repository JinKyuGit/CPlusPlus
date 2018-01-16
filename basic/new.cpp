#include<iostream>

using namespace std;


int * MakeArray(int num){

	int * temp=new int[num];
	//int * temp=(int *)malloc(sizeof(int)*num));
	return temp;
}

int main(){

	int * arr=MakeArray(10);

	int i;
	for(i=0; i<10; i++){
		arr[i]=i+1;
		cout<<arr[i]<<" ";
	}
	cout<<"\n";

	delete []arr; //free(arr);
	
	return 0;
}

