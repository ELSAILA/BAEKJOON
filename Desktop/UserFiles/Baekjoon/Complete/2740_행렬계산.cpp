#include <iostream>

using namespace std;

int A[101][101],B[101][101],C[101][101];
int N,M,K;

int main(){
	
	cin >> N >> M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> A[i][j];
		}	
	}

	cin >> M >> K;		
	for(int i=0;i<M;++i){
		for(int j=0;j<K;++j){
			cin >> B[i][j];
		}	
	}

	for(int i=0;i<N;++i){
		for(int j=0;j<K;++j){
			for(int k=0;k<M;++k){
				
				cout << C[i][j] << " + " << A[i][k] <<" * "<< B[k][j]<<" = "<<C[i][j] + A[i][k] * B[k][j]<<endl;
				
				
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	for(int i=0;i<N;++i){
		for(int k=0;k<K;++k){
			cout << C[i][k] << " ";
		}
		cout << endl;
	}
	
		
	return 0;	
}

/*

3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3

*/
