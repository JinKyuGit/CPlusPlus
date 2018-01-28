#include<iostream>
#include<string>

using namespace std;


string Caesar(string s, int n){

	string answer="";

	string temp;
	char ch, ch2;
	int i=0;
	while(i<=n){
		ch=s.at(i);
		//공백인 경우 처리.
		if(ch==' '){
			answer+=" ";
			i++;
			continue;
		}

		//공백이 아닌경우
		ch2=ch+n;
			//Z나 z를 넘어선 경우.
		if(ch2 > 122 || (ch2 > 90 && ch2 < 97) ){
			int nTemp=n;		
			while(nTemp != 0){
				if(ch == 90 || ch == 122){
					(ch==90)? ch='A' : ch='a';
					nTemp--;
				}
				ch+=1;
				nTemp--;
			}
			ch2=ch;
		}
			
		temp=ch2;
		answer+=temp;
		i++;
	}

	return answer;
}



int main(){


	string a="a Z x";
	int n=4;
	cout<<"원문 : "<<a<<", n = "<<n<<endl;	
	cout<<"변환 : "<<Caesar(a, n)<<endl;

	return 0;
}
