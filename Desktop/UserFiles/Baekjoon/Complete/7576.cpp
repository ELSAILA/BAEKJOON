#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

static bool sync_with_stdio;

struct MOV{
	int x, y;
};

int M,N,cnt, tmp, unripped;
int mat[1001][1001];
bool visited[1001][1001];
queue <pair <int, int> > q;
MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void print(){

	cout << cnt << endl;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

void bfs(int x, int y){

	visited[x][y] = true;
	q.push( make_pair(x, y) );

	while(!q.empty()){

		int tmp = q.size();
		
		// spread
		for(int j=0;j<tmp;++j){
		
				int xloc = q.front().first;
				int yloc = q.front().second;		
				q.pop();
		
				// search
				for(int i=0;i<4;++i){
		
					int nextx = xloc + mov[i].x;
					int nexty = yloc + mov[i].y;
		
					if(0<=nextx && nextx<N && 0<=nexty && nexty<M && mat[nextx][nexty] == 0 && visited[nextx][nexty] == false){
						visited[nextx][nexty] = true;
						mat[nextx][nexty] = 1;
						unripped--;
						q.push(make_pair(nextx, nexty));			
					}
				}					
		}

				
		cnt++;			
//		print();
		
		if(unripped==0)
			return;
	}
}

int main(){

	scanf("%d%d", &M,&N);
		
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			scanf("%d", &mat[i][j]);
			
			if(mat[i][j] == 0)
				unripped++;
			if(mat[i][j] == 1)
				q.push( make_pair(i, j) );
			
		}
	}

	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			
			if(mat[i][j]==1 && unripped>0){
				bfs(i, j);
			}
			else
				continue;
		}
	}

	if(unripped!=0)
		printf("%d\n", -1);		
	else
		printf("%d\n", cnt);
	
	
	return 0;
}

/*

6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

5 5
-1 1 0 0 0
0 -1 -1 -1 0
0 -1 -1 -1 0
0 -1 -1 -1 0
0 0 0 0 0

6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

11 11
0 0 0 0 1 0 -1 -1 0 0 0
0 -1 1 1 0 0 1 1 0 0 0
0 0 0 0 -1 1 0 0 1 0 0
0 0 -1 0 0 -1 -1 0 0 0 -1
1 1 -1 0 0 1 0 0 0 -1 1
-1 0 0 0 0 0 1 0 0 1 0
0 1 0 -1 0 0 0 0 1 1 1
0 0 0 1 0 0 0 0 0 -1 0
0 0 0 0 0 0 0 0 0 0 -1
-1 0 0 0 0 0 1 1 0 0 1
-1 0 0 0 0 -1 -1 0 0 0 -1



*/
