#include<iostream>

using namespace std;

class Point {

	private :
		int x;
		int y;
	public :
		Point(int _x=0, int _y=0) :  x(_x), y(_y) { }

		~Point(){}

		Point operator+(const Point & p){
		
			Point point(x+p.x, y+p.y);
			return point;
		}
		
		Point& operator=(const Point & p){
			
			x=p.x;
			y=p.y;

			return *this;
		}
		friend ostream& operator<<(ostream& os, Point & p);
	
		Point& operator++(){
			
				x+=1;
				y+=1;
			
			return *this;
		}

		Point operator++(int){
			
				Point p(this->x, this->y);
				this->x+=1;
				this->y+=1;
				
				return p;
		}

		Point operator*(int num){
			
			Point p(x*num, y*num);
			return p;
		}

		friend Point operator*(int num, Point & p);

}; //Point

ostream& operator<<(ostream & os, Point & p){

	os<<"["<<p.x<<", "<<p.y<<"]"<<endl;
	return os;
}

Point operator*(int num, Point & p){
	return p*num; //Point내의 함수활용.
}


int main(){

	Point p1(1, 1);
	Point p2(2, 2);

	Point p3;
	cout<<p3;
	
	p3=p2+p1;

	cout<<p3;

	
	Point p4=p3++;

	cout<<p3;
	cout<<p4;
	
	Point p5=2*p4;

	cout<<p5;

	return 0;
}
