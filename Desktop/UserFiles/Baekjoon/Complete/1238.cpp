#include <iostream>
#include <cstdio>
using namespace std;

int mat[1001][1001];
int N, M, X, ans;

void print(){

	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j){
			cout << mat[i][j] << " ";
		}	
		cout << endl;
	}	
	
}

void Floyd(){
	
	for(int k=1;k<N+1;++k){
		for(int i=1;i<N+1;++i){
			for(int j=1;j<N+1;++j){
				
				if(i!=j && mat[i][k] + mat[k][j] < mat[i][j]){
					mat[i][j] = mat[i][k] + mat[k][j];
				}
				
			}
		}		
	}
	
}

int main(){
	
	cin >> N >> M >> X;

//	scanf("%d%d%d",&N,&M,&X);
	
	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j){
			
			if(i!=j){
				mat[i][j] = 100000;		
			}
		}
	}
	
	for(int i=0;i<M;++i){
		int a, b;
		cin >> a >> b >> mat[a][b];
		
//		scanf("%d%d%d",&a,&b,&mat[a][b]);
		
	}	
	
	Floyd();
	
	for(int i=1;i<N+1;++i){
		int tmp = mat[i][X] + mat[X][i];
		
		ans = max(ans, tmp);
		
	}
	
	printf("%d\n", ans);
			
	return 0;	
}

/*

4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

*/