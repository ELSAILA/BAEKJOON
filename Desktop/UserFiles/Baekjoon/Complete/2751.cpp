#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int num[1000001];

void print(){

	for(int i=0;i<N;++i){
		
		printf("%d\n", num[i]);
		
	}		
}

int main(){
	
	cin >> N;
	
	for(int i=0;i<N;++i){
		int tmp;
		
		cin >> tmp;
		num[i] = tmp;
		
	}
	
	sort(num, num+N);
	
	print();
	
	return 0;	
}

/*

5
5
2
3
4
1

*/
