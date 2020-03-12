#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct MOV{
	int x, y;
};

int N, cnt, k, house;
int mat[26][26];
int visited[26][26];

MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };
queue< pair<int, int> > q;
vector<int> danji;

void print(){

	sort(danji.begin(),danji.begin()+cnt);

	cout << cnt << endl;	
	for(int i=0;i<cnt;++i)
		cout << danji[i] << endl;
	
}

void bfs(int x, int y){
	
	visited[x][y] = cnt;
	house++;
	
	q.push( make_pair(x, y) );
		
	while(!q.empty()){
	
		int nodex = q.front().first;
		int nodey = q.front().second;
	
		q.pop();
		
		for(int i=0;i<4;++i){
			
			int nextx = nodex + mov[i].x;
			int nexty = nodey + mov[i].y;
			
			if( 0<=nextx && nextx<N && 0<=nexty && nexty<N && visited[nextx][nexty] == 0 && mat[nextx][nexty] == 1){
				visited[nextx][nexty] = cnt;
				house++;
				q.push( make_pair(nextx, nexty) );
			}
		}
	}	
	
}


int main(){

	scanf("%d", &N);	
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			scanf("%1d", &mat[i][j]);			
		}
	}		
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			
			if(mat[i][j]==1 && visited[i][j] == 0){
				cnt++;
				house=0;
				bfs(i,j);
				danji.push_back(house);
			}			
			else
				continue;
		}
	}		
	
	print();
		
	return 0;	
}

/*

7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

*/
