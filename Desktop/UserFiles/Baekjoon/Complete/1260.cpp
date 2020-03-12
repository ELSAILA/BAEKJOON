#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int mat[1001][1001];
bool dfs_mark[1001];
bool bfs_mark[1001];
queue <int> q;

void dfs(int node){

	dfs_mark[node] = true;
	
	cout << node << " ";			
	
	for(int i=1;i<N+1;++i){

		if( mat[node][i] == 1 && dfs_mark[i] == false){
			dfs_mark[i] = true;			
			dfs(i);	
		}
	}
}

void bfs(int node){
	
	bfs_mark[node] = true;	

	q.push(node);
	while(!q.empty()){
		
		int loc = q.front();
		q.pop();
		
		cout << loc << " ";
		
		for(int i=1;i<N+1;++i){
			
			if( mat[loc][i] == 1 && bfs_mark[i] == false){
				bfs_mark[i] = true;
				q.push(i);\
			}
		}
		
	}
	
}

int main(){
	
	cin >> N >> M >> V;
	
	for(int i=1;i<M+1;++i){

		int from, to;		
		cin >> from >> to;	

		mat[from][to] = 1;
		mat[to][from] = 1;
		
	}		
	
	dfs(V);
	cout << endl;
	
	bfs(V);
	cout << endl;

		
	
	return 0;	
}

/*

4 5 1
1 2
1 3
1 4
2 4
3 4

5 5 3
5 4
5 2
1 2
3 4
3 1

1000 1 1000
999 1000

*/
