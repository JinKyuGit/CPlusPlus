#include<iostream>
#include<string>



using namespace std;



string compute(string s){

	int len=s.size();

	int i, j, k;
	string temp=s;
	string temp2;
		for(j=0; j<len; j++){
			for(k=j+1; k<len; k++){
				temp2=s.substr(j, k);
				if(temp.compare(temp2) < 0 ){
					temp=temp2;
					cout<<temp<<endl;
				}
			}
		}

	
	return temp;
}


int main(){


	compute("aaa");
	

	cout<<"결과"<<compute("aaa")<<endl;
	return 0;
}
