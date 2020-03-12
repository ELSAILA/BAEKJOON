#include <iostream>

using namespace std;

#define INF 9999999

int N, M, ans, sum = INF;
int Know[101][101];

void print(){

	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cout << Know[i][j] << " ";
		}
		cout << endl;
	}
	
}

void Bridge(){
	
	for(int k=1;k<=N;++k){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				
				if(i == j)
					continue;
				
				if(Know[i][j] == 0){
				
					if(Know[i][k] != 0 && Know[k][j] !=0){
						Know[i][j] = Know[i][k] + Know[k][j];	
					}
				}
				else{
					
					if(Know[i][k] != 0 && Know[k][j] !=0){
						Know[i][j] = min( Know[i][j], Know[i][k] + Know[k][j] );	
					}						
				}
			}	
		}			
	}	
}

int main(){
	
	cin >> N >> M;
	
	for(int i=0;i<M;++i){
		int from, to;
		
		cin >> from >> to;
		
		Know[from][to] = 1;
		Know[to][from] = 1;
	}
	
	Bridge();

	for(int i=1;i<=N;++i){
		
		int tmp=0;
		for(int j=1;j<=N;++j){
			
			tmp+=Know[i][j];
		}	
		
		if(sum > tmp){
			sum = tmp;
			ans = i;
		}
		
	}	
	
	cout << ans << endl;
	
	return 0;	
}

/*

5 5
1 3
1 4
4 5
4 3
3 2

*/
