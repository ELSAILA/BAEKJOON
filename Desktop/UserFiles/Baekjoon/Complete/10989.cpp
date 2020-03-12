#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

int N;
int num[10001];
int maxi;

int main(){
		
	scanf("%d", &N);	
	
	clock_t start, end;
	
	for(int i=0;i<N;++i){
		int tmp;

		scanf("%d", &tmp);						
		num[tmp]++;
		
		if(maxi < tmp)
			maxi = tmp;
	}	
	
	start = clock();
	
	for(int i=1;i<maxi+1;++i){
		
		if(num[i]==0)
			continue;
		else{
			int j=0;
			while(j!=num[i]){
				
				printf("%d\n", i);				
				j++;
			}	
		}
	}

	end = clock();	
	
//	double result = (double)(end - start);
			
//	cout << "time: " << result << endl;
	
	return 0;
}

/*

10
5
2
3
1
4
2
3
5
1
7

*/
