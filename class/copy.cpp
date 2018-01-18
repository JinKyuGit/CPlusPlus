#include<iostream>

using namespace std;


class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) {
			cout<<"기본 생성자 실행 : "<<this<<endl;
		}

		~Point(){
			cout<<"기본 소멸자 실행 : "<<this<<endl;
		}

		Point(const Point & copy) 
		: x(copy.x), y(copy.y)
		{
			cout<<"복사 생성자 실행 : "<<this<<endl;
		}
}; //Point

Point Temp(Point p){

	cout<<"넘겨받은 매개변수 : "<<&p<<" p2와 상이함을 주목\n";
	return p;
}

int main(){

	cout<<" == p1 생성 ==\n";
	Point p1(1, 1);
	
	cout<<" == p2=p1 ==\n";
	Point p2=p1;

	cout<<" == p3=Temp(p2) ==\n";
	Point p3=Temp(p2);
	cout<<"p3의 값 : "<<&p3<<endl;
	return 0;
}
