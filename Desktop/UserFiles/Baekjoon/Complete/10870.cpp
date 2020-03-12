#include <iostream>
using namespace std;

int N;
int sum=0;
long long int num[1001];

int main(){
	
	cin >> N;
	num[0] = 0;
	num[1] = 1;
	
	for(int i=2;i<=N;++i){
		num[i] = num[i-1] + num[i-2];
	}
	
	cout << num[N]%1000000 << endl;
	
	return 0;	
}
