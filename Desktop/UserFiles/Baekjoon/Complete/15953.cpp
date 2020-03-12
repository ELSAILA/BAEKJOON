#include <iostream>

using namespace std;

int T;
int f_2017[7] = {0,500,300,200,50,30,10};
int f_2018[6] = {0,512,256,128,64,32};

int Cal(int a, int b){
	
	if(a==0 || a > 21){
		a = 0;
	}
	else{
		// 2017
		for(int i=1;i<7;++i){
		
			
			if(a-i <= 0){
//cout <<"you: "<<i<<", prize: "<< f_2017[i]<<endl;				
				
				a = f_2017[i];
				break;
			}
			
			a-=i;

//cout << i << "  is remaining: " << a << endl;
				
		}
		
	}
	
	
	if(b==0 || b > 31){
		b = 0;
	}
	else{
		//2018
		int c = 1;
		for(int i=1;i<6;++i){
			
			if(b-c<=0){
//cout << "you: "<<i<<", prize: "<<f_2018[i]<<endl;				
				
				b = f_2018[i];
				break;
			}
		
			b-=c;	
			c*=2;

//cout << i << " is remaining: " << b << ", "<<c<<endl;			
								
		}
	}
	
//	cout << a <<", "<<b << endl;
			
	return (a+b)*10000;	
}

int main(){
	
	cin >> T;
	
	for(int i=0;i<T;++i){
		int a, b;
		
		cin >> a >> b;
		
		int ans = Cal(a, b);
		
		cout << ans << endl;
	}
	
	
	return 0;	
}

/*
6
8 4
13 19
8 10
18 18
8 25
13 16

*/
