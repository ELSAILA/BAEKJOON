#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct sq{
	int x1, y1, x2, y2, line1, line2;
};

typedef struct{
	int x, y;
}MOV;

int M,N,K,ans;
int mat[101][101];
bool visited[101][101];
int cnt, k;
int area[101];
MOV mov[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} }; 

void print(){

	cout << endl;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cout << visited[i][j] <<" ";
		}
		cout << endl;
	}	
			
}

void bfs(int x, int y){
	
	visited[x][y] = true;
	cnt++;
	
	queue< pair<int, int> > q;
	q.push(make_pair(x,y));
	
	while(!q.empty()){
	
		area[k]++;		
		pair<int, int> node = q.front();
		q.pop();
				
		for(int i=0;i<4;++i){
		
			int nextx = node.first + mov[i].x;
			int nexty = node.second + mov[i].y;
			
			if(0<=nextx && nextx<N && 0<=nexty && nexty<M && visited[nextx][nexty] == false && mat[nextx][nexty] !=3){
				visited[nextx][nexty] = true;
				q.push(make_pair(nextx,nexty));				
			}	
		}
	}
	
	k++;	
}

void swap(int x, int y){

	int tmp = x;
	x = y;
	y = tmp;	
}

int main(){
	
	cin >> M >> N >> K;
	
	sq square[K];
	
	// fill
	for(int i=0;i<K;++i){
		cin >> square[i].x1 >> square[i].y1 >> square[i].x2 >> square[i].y2;
		square[i].line1 = square[i].x2 - square[i].x1;
		square[i].line2 = square[i].y2 - square[i].y1;		 		
				
		for(int j=0;j<square[i].line1;++j){		
			for(int p=0;p<square[i].line2;++p){
						
				mat[square[i].x1+j][square[i].y1+p] = 3;
					
			}
		}
	}
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			
			if(visited[i][j] == false && mat[i][j]!=3)
				bfs(i,j);
			else
				continue;
		}
	}
	
	cout << cnt << endl;
	
	sort(area,area+cnt);

	for(int i=0;i<cnt;++i){
		cout << area[i] << " ";		
	}
				
	return 0;	
}

/*

5 7 3
0 2 4 4
1 1 2 5
4 0 6 2

*/
