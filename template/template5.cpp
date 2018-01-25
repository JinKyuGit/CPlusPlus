#include<iostream>

using namespace std;


//일반 템플릿.
template <class T=int>
class Temp {

	T num;

	public :
		Temp(T _num) : num(_num){
			cout<<"일반 템플릿 생성자\n";
		}

}; //Temp

//double형에 대한 특수화 템플릿.
template <>
class Temp<double> {

	double num;

	public :
		Temp(double _num) : num(_num){
			cout<<"double 템플릿 생성자\n";
		}

}; //Temp

int main(){

	Temp<> t1(2); //디폴트값 이용한 객체생성.
	Temp<int> t2(3);
	Temp<double> t3(3.3);
	

	return 0;
}
