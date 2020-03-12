#include <iostream>

using namespace std;

int maxi(int x, int y){
	
	if(x>y) 
		return x;
	return y;
	
}

bool check(int num){

	int cnt1=0, how_many=0;
	while(num!=0){
		
		int tmp=num%10;
								
		if(tmp == 6)
			cnt1++;
		else
			cnt1=0;
		
		how_many = maxi(cnt1, how_many);
						
		num/=10;
	}
	
	if(how_many>=3)
		return true;
	else
		return false;
			
}

int main(){
	
	int N, cnt=0, ans=0;
	cin >> N;
	
	int i = 666;
	
	while(cnt!=N){
			
		if(check(i)){
			cnt++;
			ans = i;
//			cout << i << endl;	
		}
		
		i++;
	}
	
	cout << ans << endl;
		
	return 0;	
}
