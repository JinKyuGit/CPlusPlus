#include<iostream>
#include<cstdlib>

using namespace std;


class Point {

	int x;
	int y;

	public:
		Point(int _x=0, int _y=0) : x(_x), y(_y) { }
		Point& operator= (const Point& p){
				x=p.x;
				y=p.y;

				return *this;
		}
		friend ostream& operator<< (ostream& os, const Point& p);
}; //Point


template <class T>
class TArray {

	private :
		T * arr;
		int bounds;
	public :
		TArray();
		TArray(int n);
		T& operator[](int idx);
		~TArray(){
			delete []arr;
		}
}; // TArray


int main(){

	//int 배열
	TArray<int> arr1(5);
	int i;
	
	for(i=0; i<5; i++){
		arr1[i]=i+1;
		cout<<arr1[i];
		
	}
	cout<<endl;	
	cout<<endl;
	
	//객체 배열
	TArray<Point> arr2(5);

	
	for(i=0; i<5; i++){
		arr2[i]=Point(i*2, i*3);
		cout<<arr2[i];
	}
	
	cout<<endl;

	//객체 포인터 배열
	TArray<Point *> arr3(5);

	for(i=0; i<5; i++){
		arr3[i]=new Point(i+1, i+2);
		cout<<*(arr3[i]);
	}
	cout<<endl;


	return 0;
}

	


ostream& operator<< (ostream& os, const Point& p){
	
	os<<"["<<p.x<<", "<<p.y<<"]"<<endl;
	return os;
}

template <class T>
TArray<T>:: TArray(){
	T * arr=NULL;
	bounds=0;
}

template <class T>
TArray<T>:: TArray(int n) : bounds(n) {
	arr=new T[bounds];
}

template <class T>
T& TArray<T>:: operator[](int idx){
	
	if(idx < 0 || idx>= bounds){
		cout<<"Exception : out of bounds\n";
		exit(1);
	}

	return arr[idx];
}





