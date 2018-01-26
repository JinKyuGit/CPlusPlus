#include<iostream>

using namespace std;

//예외처리 클래스
class TempException {

	int num;

	public :
		TempException(int _num) : num(_num) {
			
		}

		void ExMessage(){
			cout<<num<<"입력 불가.\n";
		}

}; //TempException

class Temp {

	int num;

	public :
		Temp(int _num){
			
			if(_num < 0 ){
				TempException te(_num);
				throw te;
			}

			this->num=_num;
		}

}; // Temp


int main(){
	
	int num;
	cout<<"숫자 입력(0 이상) : ";
	cin>>num;

	try {
		Temp t1(num);
	} catch (TempException& te){
			te.ExMessage();
	}


	return 0;
}
