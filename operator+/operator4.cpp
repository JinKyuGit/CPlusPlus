#include<iostream>

using namespace std;



class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) {  }
		
		//이대로는 p1*num은 되나
		//num*p1은 안됨.
		Point operator*(int num){

			Point p(x*num, y*num);
			return p;
		}

		//교환법칙을 위한 전역함수.
		friend Point operator*(int num, Point &p);

		void ShowPoint(){
			
			cout<<"x : "<<x<<" y : "<<y<<endl;

		}



}; //Point


//Point class 의 operator*(int num) 함수를 이용하여
//교환법칙이 성립하도록 함.
Point operator*(int num, Point &p){
	
	return p*num;
}


int main(){


	Point p1(2, 3);

	Point p2=p1*3;
		
	Point p3=3*p1;

	p2.ShowPoint();
	p3.ShowPoint();


	return 0;
}
