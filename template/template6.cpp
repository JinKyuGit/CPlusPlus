#include<iostream>

using namespace std;


template <class T>
class Point {

	T x;
	T y;

	public :
		Point(T _x, T _y) : x(_x), y(_y) {
			cout<<"일반 템플릿 생성자 실행.\n";
		}

		void Func(T num);

}; //Point


template <>
class Point <long> {

	long x;
	long y;

	public :
		Point(long _x, long _y) : x(_x), y(_y) {
			cout<<"long 템플릿 생성자 실행.\n";
		}

		void Func(long num);

}; //Point
template <class T>
void Point<T>:: Func(T num){
	cout<<"Point<T> 실행\n";
}

template<>
void Point<double>:: Func(double num){
	cout<<"Point<double> 실행\n";
}

//상기 2개 함수는 기본형 템플릿에 종속적이나
//아래 함수는 long형 특수화 템플릿에만 종속적이다.
//따라서 template<> 문구가 필요없다.
void Point<long>:: Func(long num){
	cout<<"Point<long> 실행\n";
}

int main(){

	Point<int> p1(3, 3);
	Point<double> p2(3, 3);
	p1.Func(1);
	p2.Func(2);

	Point<long> p3(3, 3);
	p3.Func(3);


	return 0;
}
