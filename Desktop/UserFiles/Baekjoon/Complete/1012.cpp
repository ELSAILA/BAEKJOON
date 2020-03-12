#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int mat[51][51];
bool visited[51][51];

struct MOV{
	int x, y;	
};

MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };
int T, M, N, K, X, Y, cnt;
queue< pair<int, int> > q;

void BFS(int a, int b){
	
	visited[a][b] = true;
	q.push(make_pair(a, b));
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;++i){
			int nextx = x + mov[i].x;
			int nexty = y + mov[i].y;
			
			if(0<=nextx && nextx<M && 0<=nexty && nexty<N && mat[nextx][nexty] == 1 && visited[nextx][nexty]==false){
				visited[nextx][nexty] = true;
				q.push( make_pair(nextx, nexty) );
			}
		}
			
	}
}

void print(){
	
	cout << endl;
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			cout << mat[i][j] <<" ";	
		}
		cout << endl;
	}		
}

int main(){
	
	cin >> T;	
	
	for(int i=0;i<T;++i){
				
		cin >> M >> N >> K;

		cnt=0;
		for(int i=0;i<M;++i){
			memset(mat[i], 0, sizeof(int)*N);
			memset(visited[i], 0, sizeof(int)*N);			
		}
							
		for(int j=0;j<K;++j){
			cin >> X >> Y;
			mat[X][Y] = 1;
		}
		
		for(int j=0;j<M;++j){
			for(int k=0;k<N;++k){
				if(mat[j][k]==1 && visited[j][k] == false){
					cnt++;
					BFS(j, k);
				}
				else
					continue;
			}
		}

		cout << cnt << endl;	
	}
			
	return 0;	
}

/*

2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5

*/
