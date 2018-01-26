#include<iostream>
#include<vector>

using namespace std;


//vector를 통한 2차원 배열
//push_back 활용

int main(){


	vector<vector<int> > arr(10);
	
	int num=0;
	int i, j;

	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			arr[i].push_back(num);
			num++;
		}
	}	

	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			cout<<arr[i][j];
			cout<<" ";
		}
		cout<<endl;
	}


	return 0;
}
