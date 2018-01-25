#include<iostream>

using namespace std;


template <class T>
class Point {
	
	T x;
	T y;

	public :
		Point(T _x, T _y) : x(_x), y(_y) {

		}

		Point();
		void ShowPoint(){
				
			cout<<"x : "<<x<<" y : "<<y<<endl;
		}
		void ShowPoint2();

}; //Point

//템플릿 외부함수
template <class T>
Point<T>:: Point(){
	cout<<"외부함수 실행.\n";
}

template <class T>
void Point<T>:: ShowPoint2(){
	cout<<"ShowPoint2\n";
}

int main(){

	Point<int> p1(1, 1);
	p1.ShowPoint();

	Point<double> p2(1.1, 2.2);
	p2.ShowPoint();

	Point<int> p3;
	
	p3.ShowPoint2();
	return 0;
}
