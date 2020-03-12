#include <iostream>
#include <cstdio>

using namespace std;

long long int N;
int visited[10];

int main(){

	cin >> N;
	
	while(N!=0){
		
		int tmp = N%10;
		
//		cout << tmp << endl;
		
		visited[tmp]++;
		
		N/=10;
		
//		cout << "cur_N: "<<N << " ";
		
	}		

	for(int i=9;i>=0;--i){
		if(visited[i]!=0){
									
			for(int j=0;j<visited[i];++j){
				printf("%d", i);
			}
		}		
	}
				
	printf("\n");
				
	return 0;	
}
