#include <iostream>
#include <cstdio>

using namespace std;

int T, A, B;

int main(){

	scanf("%d", &T);
	
	for(int i=0;i<T;++i){
		
		scanf("%d%d", &A, &B);	
		printf("%d\n", A+B);	
	}
	
	return 0;	
}

/*

5
1 1
12 34
5 500
40 60
1000 1000

*/