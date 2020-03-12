#include <iostream>
#include <queue>

using namespace std;

typedef struct{
	int x, y;
}MOV;

int N, M, ans;
long long int tmp;
int mat[101][101];
int visited[101][101];
queue< pair<int,int> > q; 

MOV mov[4] = {{1,0},{0,1},{-1,0},{0,-1}};

void print(){
	
	cout << visited[N][M] << endl;		
}

void bfs(int x, int y){
	
	visited[x][y] = 1;
	
	q.push( make_pair(x,y) );
	
	while(!q.empty()){
	
		int nodex = q.front().first;			
		int nodey = q.front().second;	
		
		q.pop();
		
		for(int i=0;i<4;++i){
			
			int nextx = nodex+mov[i].x;
			int nexty = nodey+mov[i].y;
			
			if(1<=nextx && nextx<=N && 1<=nexty && nexty<=M && visited[nextx][nexty] == false && mat[nextx][nexty] != 0){
				
				mat[nextx][nexty] = 3;
				visited[nextx][nexty] = visited[nodex][nodey]+1;
				
				q.push( make_pair(nextx, nexty) );	
			}
		} 		
	}
	
}

int main(){
	
	scanf("%d%d",&N,&M);
	
	for(int i=1;i<N+1;++i){
		for(int j=1;j<M+1;++j){
			scanf("%1d", &mat[i][j]);
		}	
		
	}
		
	bfs(1,1);	

	print();

	
	return 0;	
}

/*

4 6
101111
101010
101011
111011

4 6
110110
110110
111111
111101

2 25
1011101110111011101110111
1110111011101110111011101

7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111

When input is over 경, even long long int can't solve it.

So we need to divide when we cin it.

*/
