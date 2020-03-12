#include <iostream>
#include <algorithm>

using namespace std;

#define INF 9999999
#define MAX 401

int V, E;

int vill[MAX][MAX];
bool visited[MAX][MAX];

void print(){
	
	for(int i=1;i<=V;++i){
		for(int j=1;j<=V;++j){
			cout << vill[i][j] << " ";		
		}
		cout << endl;
	}

}

void Floyd(){
	
	for(int k=1;k<=V;++k){
		for(int i=1;i<=V;++i){
			for(int j=1;j<=V;++j){
								
				if(vill[i][j] == 0){
					
					if(vill[i][k]!=0 && vill[k][j]!=0){
						vill[i][j] = vill[i][k] + vill[k][j];	
					}
						
				}
				else{

					if(vill[i][k]!=0 && vill[k][j]!=0){
						vill[i][j] = min(vill[i][j], vill[i][k] + vill[k][j]);	
					}			
				}
				
			}
		}			
	}
	
}

int main(){

	cin >> V >> E;	

	for(int i=0;i<E;++i){
		int x, y;
		cin >> x >> y >> vill[x][y];
	}

	for(int i=1;i<=V;++i){
		vill[i][i] = INF;
	}	
	
	Floyd();
	
	int ans=INF;
	for(int i=1;i<=V;++i){
		ans = min(ans, vill[i][i]);
	}	
	
	if(ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	
	return 0;	
}

/*

3 4
1 2 1
3 2 1
1 3 5
2 3 2
*/
