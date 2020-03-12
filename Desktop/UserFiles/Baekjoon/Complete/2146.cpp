#include <iostream>
#include <queue>

using namespace std;

struct MOV{
	int x, y;
};

int N, cnt, ans;
int result = 99999;
int mat[101][101];
int visited[101][101];
int xpend[101][101];
MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void print(){

	cout << endl;
	for(int i=0;i<N;++i){	
		for(int j=0;j<N;++j){	
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}	
	
}

// mark each island
void DFS(int a, int b, int cnt){
	
	visited[a][b] = true;
	mat[a][b] = cnt;
	
	for(int i=0;i<4;++i){
		int nextx = a + mov[i].x;	
		int nexty = b + mov[i].y;	
	
		if(0<=nextx && nextx<N && 0<=nexty && nexty<N && mat[nextx][nexty] == 1 && visited[nextx][nexty] == false){
			DFS(nextx, nexty, cnt);	
		}
	}	
}

void BFS(int cnt){
	
	queue< pair<int,int> > q;
		
	for(int i=0;i<N;++i){	
		for(int j=0;j<N;++j){	
			if(mat[i][j] == cnt){
				visited[i][j] = true;
				q.push(make_pair(i,j));	
			}
		}
	}	

	while(!q.empty()){
		
		int p = q.size();	

		for(int k=0;k<p;++k){		
			int x = q.front().first;	
			int y = q.front().second;	
			q.pop();
					
			for(int i=0;i<4;++i){
				int nextx = x + mov[i].x;	
				int nexty = y + mov[i].y;	
				
				if(0<=nextx && nextx<N && 0<=nexty && nexty<N){
					
					if(mat[nextx][nexty]!=0 && mat[nextx][nexty]!=cnt){
						return;	
					}
					else if(mat[nextx][nexty] == 0 && visited[nextx][nexty] == 0){
						visited[nextx][nexty] = true;
						q.push( make_pair(nextx, nexty) );
					}
				}
			}		
		}	
		ans++;
//		print();
	}
	
}

int main(){

	cin >> N;
	
	for(int i=0;i<N;++i){	
		for(int j=0;j<N;++j){	
			cin >> mat[i][j];			
		}
	}
	
	for(int i=0;i<N;++i){	
		for(int j=0;j<N;++j){	
			if(mat[i][j]==1 && visited[i][j]==false){
				DFS(i, j, ++cnt);
			}
		}
	}
	
	for(int i=1;i<=cnt;++i){
		ans=0;
		for(int i=0;i<N;++i){	
			for(int j=0;j<N;++j){	
				visited[i][j] = 0;
			}
		}
		
		BFS(i);
		
		if(ans<result)
			result = ans;
	}					
	
	cout << result << endl;
				
	return 0;	
}

/*

5
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 1 0 1 0
0 0 0 0 0


4
1 1 0 0
0 0 0 1
0 1 1 1
0 0 0 0

10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

10
1 1 1 0 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 0 1 0 1 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

5
1 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 0 0 1



*/
