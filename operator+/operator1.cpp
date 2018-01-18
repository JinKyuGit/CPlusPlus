#include<iostream>

using namespace std;


class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) { }
		void ShowPoint(){
			cout<<"x : "<<x<<endl;
			cout<<"y : "<<y<<endl;
		}
		//멤버함수.	
		Point operator+(const Point & copy){
			
			int a=this->x+copy.x;
			int b=this->y+copy.y;

			Point p(a, b);

			return p;
		}
		//전역함수.
		//클래스 바깥에서 private 멤버에 접근할 수 있도록
		//friend 선언을 해야함.
		friend void operator++(Point & pos);
}; //Point;

void operator++(Point & pos){

	pos.x+=1;
	pos.y+=1;
}


int main(){
	//연산자 오버로딩이란.
	//객체를 일반 자료형처럼 연산이 가능하도록 함.
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3=p1+p2;
	//연산자 오버로딩에 의해 p1.operator+(p2)로 변환된다.
	//즉 p1+p2  == p1.operator+(p2) 와 같다.
	//피연산자 뒤에 오는 객체가 매개변수가 됨.
	cout<<"p3 = p1+ p2\n";	
	p3.ShowPoint();

	++p3;
	cout<<"++p3\n";
	p3.ShowPoint();

	return 0;
}
