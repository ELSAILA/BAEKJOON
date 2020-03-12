#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 101

int n, m;
int city[MAX][MAX];

void print(){

	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			
			printf("%d ", city[i][j]);
		}
		printf("\n");
	}
}

void Floyd(){

	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
									
				if(i==j)
					continue;
				
				if(city[i][j] == 0){
					
					if(city[i][k] != 0 && city[k][j] != 0)	
						city[i][j] = city[i][k] + city[k][j];
				}
				else{
					
					if(city[i][k] != 0 && city[k][j] != 0)	
						city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
				
				}	
			}
		}			
	}	
	
	print();
	
}

int main(){
	
	cin >> n >> m;
	
	for(int i=0;i<m;++i){
		
		int from, to, price;		
		cin >> from >> to >> price;
		
		if(city[from][to] == 0)	
			city[from][to] = price;
		else
			city[from][to] = min(city[from][to], price);	
		
	}
		
	Floyd();
	
	return 0;
}

/*

5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4

*/
