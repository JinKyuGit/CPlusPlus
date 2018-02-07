#include<iostream>

using namespace std;

template<class T>
void Func(T t1){
	cout<<"기본 템플릿 함수 실행\n";
}

template<> //아래에서 매개변수 형을 지정하므로 별도의 지정불필요
void Func(double t1){
	cout<<"특수화 템플릿 함수 실행\n";
}

template<class T=int>
class Point{

	T x;
	T y;

	public :
		Point(T _x=0, T _y=0) : x(_x), y(_y) { }
		void Show(){
			cout<<x<<", "<<y<<endl;
		}

		void Func();


}; //Temp;

template<class T>
void Point<T>:: Func(){
	cout<<"템클릿 클래스 기본함수\n";
}

template<>
void Point<double>:: Func(){
	cout<<"템클릿 클래스 특수화함수\n";	
}



int main(){

//	Func<int>(1);
//	Func<double>(3.3);


	Point<int> p1(1.1, 1.1);
	p1.Show();
	p1.Func();
	Point<double> p2(2.2, 2.2);
	p2.Show();
	p2.Func();

	return 0;
}
