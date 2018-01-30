#include<iostream>

using namespace std;


int main(){

	
	int num=0x010203; // 00000001 00000010 00000011

	char * ptr=reinterpret_cast<char *>(&num);

	int i;

	for(i=0; i<sizeof(num); i++){
		cout<<static_cast<int>(*(ptr+i))<<endl;
	}

	return 0;
}
