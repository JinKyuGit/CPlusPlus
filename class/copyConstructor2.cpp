#include<iostream>

using namespace std;


class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) {
			cout<<"기본 생성자 실행.\n";
		}
		Point(const Point &copy)
		: x(copy.x), y(copy.y)
		{
			cout<<"복사 생성자 실행\n";
		}

		Point Temp(Point p){
					//매개변수에 오면서 복사생성자 실행 1
			return p;
			//리턴하면서 복사생성자 실행 2
			//이유 : 함수가 끝나면 매개변수 등은 소멸됨
			//따라서 임시 객체 생성하는 것.
			//리턴되는 임시객체는
			//이를 받아주는 변수 등이 없을 경우
			//바로 소멸.
		}

}; //Point

int main(){

	Point p1(1, 1);

//	Point p2=p1;

	Point p3=p1.Temp(p1);


	return 0;
}
