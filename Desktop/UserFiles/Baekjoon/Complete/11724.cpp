#include <iostream>
#include <queue>

using namespace std;

int N,M,from,to,cnt;
int mat[1001][1001];
int visited[1001][1001];
queue<int> q;

void BFS(int a, int b){
	
	visited[a][b] = true;
	q.push(b);
		
	while(!q.empty()){
		int src = q.front();
		q.pop();	
		
		for(int i=1;i<N+1;++i){
			if( mat[src][i] == 1 && visited[src][i] == false){
				visited[src][i] = true;
				visited[i][src] = true;
				
				q.push(i);	
			}
		}
	}	
	
}

void print(){
	
	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j){
			cout << visited[i][j] <<" ";
		}
		cout << endl;
	}
}

int main(){
	
	cin >> N >> M;
	
	for(int i=1;i<N+1;++i){
		mat[i][i] = 1;	
	}
	
	for(int i=0;i<M;++i){
		cin >> from >> to;
		mat[from][to] = 1;
		mat[to][from] = 1;
	}	

	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j){
			
			if(mat[i][j]==1 && visited[i][j]==false){
				cnt++;
				BFS(i, j);
			}
			else
				continue;
		}
	}

	cout << cnt << endl;	
		
	return 0;	
}

/*

6 5
1 2
2 5
5 1
3 4
4 6

6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3


5 1
1 2

*/
