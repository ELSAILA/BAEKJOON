#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct MOV{
	int x, y;
};

int N, M, ans, sum;
int mat[501][501];
bool visited[501][501];

MOV mov[4] = {{1,0},{0,1},{-1,0},{0,-1}};

void reset(int x, int y){
	
	visited[x][y] = false;
	
	for(int i=0;i<4;++i){
		int nx = x + mov[i].x;
		int ny = y + mov[i].y;
		
		if(0<=nx && nx<N && 0<=ny && ny<M){
			visited[nx][ny] = false;			
		}	
	}
	
}

int bigger(int a, int b){
	
	if(a>b)
		return a;
	return b;
}

int smaller(int a, int b){
	
	if(a>b)
		return b;
	return a;
}

int fx, fy;
int search(int x, int y){
	
	int g=0, val=0;
	
	for(int i=0;i<4;++i){
		int nx = x + mov[i].x;
		int ny = y + mov[i].y;
		
		if(0<=nx && nx<N && 0<=ny && ny<M && visited[nx][ny] == false){
			val = mat[nx][ny];
			
			g = bigger(g, val);		
		}	
	}

		
	for(int i=0;i<4;++i){
		int nx = x + mov[i].x;
		int ny = y + mov[i].y;
	
		if(0<=nx && nx<N && 0<=ny && ny<M && mat[nx][ny] == g && visited[nx][ny] == false){
			
			visited[nx][ny] = true;			
			fx = nx;
			fy = ny;				
		}
	}	
	
	return g;
}

int spread(int x, int y){
	
	int s=10000000, val=0, tmp=mat[x][y], cnt=0;	
	
	for(int i=0;i<4;++i){
		int nx = x + mov[i].x;
		int ny = y + mov[i].y;
		
		if(0<=nx && nx<N && 0<=ny && ny<M && visited[nx][ny] == false){
			
			cnt++;
			val = mat[nx][ny];
			tmp += val;
			
			s = smaller(s, val);				
		}	
	}
	
	reset(x, y);
	
	if(cnt==4){	
				
		tmp -= s;
				
		return tmp;
	}
	else if(cnt==3){
		return tmp;
	}
		return 0;
}

int tetro(int x, int y, int depth){
	
	if(depth==4){
		reset(x,y);				
		return sum;
	}
		
	int tmp = search(x, y);
	sum+=tmp;
		
	tetro(fx, fy, depth+1);
	return sum;
}

int main(){
	
	scanf("%d%d", &N, &M);
		
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			scanf("%d", &mat[i][j]);			
		}
	}		
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			
			sum = 0;			
			sum+=mat[i][j];
			
			reset(i, j);
			visited[i][j] = true;						
			int normal = tetro(i, j, 1);
			
			reset(i, j);						
			visited[i][j] = true;						
			int abnormal = spread(i, j);
						
			ans = bigger( ans, bigger(normal, abnormal) );
			
		}
	}
	
	printf("%d\n", ans);
		
	return 0;	
}

/*

5 10
1 2 1 2 1 2 1 2 1 1
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 1
2 1 2 1 2 1 1 10 10 10
1 1 1 1 1 1 1 1 10 1

5 5
0 0 0 0 0
0 5 5 0 0 
0 0 5 0 0 
0 0 5 0 0 
0 0 0 0 0

4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1

5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1

*/

