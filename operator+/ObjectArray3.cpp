#include<iostream>
#include<cstdlib>

// 더블 포인터를 통한 객체 배열다루기.

using namespace std;


class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) {
			//cout<<"기본 생성자 실행\n";
		}

		friend ostream& operator<<(ostream& os, const Point& p);

}; //Point

ostream& operator<<(ostream& os, const Point &p){
	
	os<<"[ x : "<<p.x<<" y : "<<p.y<<" ]"<<endl;
	return os;
}


//typedef Point * PTR;

class PointArray {

	Point ** arr;
	int numOfPoint;

	public :
		PointArray(int _numOfPoint) : numOfPoint(_numOfPoint) {
			arr=new Point*[_numOfPoint];
		}

		~PointArray(){
			delete []arr;
		}

		Point*& operator[](int idx){
			
			if(idx < 0 || idx >= numOfPoint){
				cout<<"Exception : Array out of Bounds\n";
			}

			return arr[idx];
		
		}
		Point* operator[](int idx) const {
			
			if(idx < 0 || idx >= numOfPoint){
				cout<<"Exception : Array out of Bounds\n";
			}
				return arr[idx];
		}
	
}; // PointArray

int main(){

	PointArray arr(10);

	int len=10;

	int i;
	for(i=0; i<len; i++){
		arr[i]=new Point(i+1, i+2);
	}

	for(i=0; i<len; i++){
		cout<<*(arr[i]);
	}

	for(i=0; i<len; i++){
		delete arr[i];
	}



	return 0;
}
