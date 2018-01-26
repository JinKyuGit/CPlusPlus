#include<iostream>

using namespace std;

/*
d(n) = n과 n의 모든 자릿수의 합.
ex) d(91) = 9 + 1 + 91 =101
이때 d(91)을 101의 제너레이터라고 함.
제너레이터가 없는 숫자를 셀프넘버라고 함.
1이상 5000미만의 셀프넘버 구하기.
*/

/* 제너레이터는 항상 해당 숫자보다 작은 값이므로
 * 5000미만의 숫자를 만드는 제너레이터를 전부확인하여
 * bool형 배열에 담아둔다.
 */

//제너레이터를 매개변수로 받아 결과값 생성.
int generator(int num){
	
	int result=num;
	//매개변수를 10으로 나눈 나머지 = 자릿수
	//10으로 나눠가며 각 자릿수 더함.
	//탈출조건은 num이 1보다 작을때.
	while(num >= 1){
		
		result += num % 10;
		num /= 10;
	}

	return result;
}


int main(){


	bool check[5000];
	
	int i;
	int result;
	int sum=0;
	
	//1~ 5000의 자리마다 제너레이터 유무 체크.
	//해당 제너레이터를 인덱스로 하여
	//배열에 저장.
	for(i=1; i<5000; i++){
		result=generator(i);
		
		//5000이하의 값 체크.
		if(result >= 1 && result < 5000){
			check[result]=true;
		}
	}

	for(i=1; i<5000; i++){	
		if(check[i] == false){	
			sum+=i;
		}
	}
	
	cout<<"1~5000 셀프 넘버의 합 : "<<sum<<endl;


	return 0;
}
