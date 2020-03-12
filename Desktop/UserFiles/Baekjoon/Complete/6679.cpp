#include <iostream>

using namespace std;

int TEN(int num){
	
	int sum=0;
	
	while(num!=0){
				
		sum+=num%10;
		num/=10;
	}
	
	return sum;
}

int TWE(int num){
	
	int sum=0;
	
	while(num!=0){
		sum+=num%12;
		num/=12;
	}
	
	return sum;	
}

int HEX(int num){
	
	int sum=0;
	
	while(num!=0){
		sum+=num%16;
		num/=16;
	}	
	
	return sum;
}

int main(){
	
	for(int i=1000;i<9999;++i){	
	
		if( TEN(i) == TWE(i) && TWE(i) == HEX(i))	
			cout << i << endl;
	}
	
	return 0;	
}
