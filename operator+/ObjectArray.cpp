#include<iostream>
#include<cstdlib>

using namespace std;

//operator를 활용한 array


class ObjectArray {

	int * arr;
	int boundsOfArray;

	public :
		ObjectArray(int n) : boundsOfArray(n) {

				this->arr=new int[n];
		}
		int& operator[](int idx){

			if(idx < 0 || idx >= boundsOfArray) {
				cout<<"boundsOfArray Excetion\n";
				exit(1);
			}
			return arr[idx];
		}


		~ObjectArray(){
			delete []arr;
		}

}; //ObjectArray

int main(){

	ObjectArray arr(10);

	int i;
	for(i=0; i<10; i++){
		arr[i]=i+1;
	}

	for(i=0; i<10; i++){
		cout<<arr[i]<<endl;
	}



	return 0;
}
