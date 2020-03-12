#include<iostream>
#include<cmath>

using namespace std;

int N, ans;

int main(){
	
	cin >> N;
	
	int tmp  = N;
	int num=0;
	
	while(tmp!=0){
		tmp/=10;
		num++;
	}
	
	// same stuff		
	for(int i=num-1;i>=1;--i){
		ans+=i*9*pow(10,i-1);
	}
	
	// differ
	int tmx = N-pow(10,num-1)+1;
	ans+=tmx*num;
	
	cout << ans << endl;	
			
	return 0;	
}
