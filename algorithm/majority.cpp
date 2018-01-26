#include<iostream>

using namespace std;

//임의의 배열에서 가장 자주 나타나는 숫자 찾기.
int Majority(int arr[], int len){


	int major=0; //빈도수가 높은 숫자
	int count=0; //major의 빈도
	int temp; // 임시 숫자
	int tempCount; //임시 숫자의 빈도
	
	int i, j;
	for(i=0; i<len; i++){
		//배열 요소 하나 저장.
		temp=arr[i];
		tempCount=0;
		for(j=0; j<len; j++){
			//배열을 순회하면서 카운트
			if(temp==arr[j]){
				tempCount++;
			}
		}
			//만약 major보다 임시 숫자의 빈도가 높은경우 체인지.
		if(count<tempCount){
			major=temp;
			count=tempCount;
		}
	}
		return major;
}


//배열의 숫자가 임의의 범위인 경우 더 효율적인 방법
int Majority2(int arr[], int len){

	int major;
	
	//배열의 길이가 얼마나 되는지 모르므로
	//동적 할당 필요.
	int * countArr=new int[len+1];

	int i;

	//arr[i]의 값을 인덱스로 사용하는  countArr의 요소를 +1 해줌.
	for(i=0; i<len; i++){
		countArr[arr[i]]++;
	}

	
	//맨 첫번째 값의 카운트 숫자를 저장.
	int countCheck=countArr[1]; //빈도수 확인
	int idx=1; //가장 높은 빈도수의 idx
	for(i=2; i<len+1; i++){
		//더 높은 빈도수의 요소가 있는 경우 체인지.
		if(countCheck < countArr[i]){
			countCheck=countArr[i];
			idx=i;
		}
	}
	
	major=arr[idx];
	delete []countArr;
	return major;
}

int main(){

	int arr[10];

	int i;

	for(i=0; i<10; i++){
		cout<<i+1<<"번째 숫자 입력 : ";
		cin>>arr[i];
	}

	
	cout<<"majority : "<<Majority2(arr, 10)<<endl;


	return 0;
}
