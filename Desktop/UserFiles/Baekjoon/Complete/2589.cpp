#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 51

queue< pair<int, int> > q, nex;

int row, col, cnt, ans;

bool maps[MAX][MAX];
int visited[MAX][MAX];

struct MOV{
	int x, y;
};

MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void print(){
	
	for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}	
	
}

void BFS(int x, int y){
	
	int sum=0;
	visited[x][y] = 1;
	nex.push(make_pair(x, y));
	
	while(!nex.empty()){
		
		int cur_x = nex.front().first;
		int cur_y = nex.front().second;
		nex.pop();
		
		for(int i=0;i<4;++i){
			int nx = cur_x + mov[i].x;
			int ny = cur_y + mov[i].y;
			
			if(0<=nx && nx<row && 0<=ny && ny<col && maps[nx][ny]==true && visited[nx][ny] == 0){
				
				nex.push(make_pair(nx, ny));
				visited[nx][ny] = visited[cur_x][cur_y] + 1;
				
				if(visited[nx][ny] > sum)
					sum = visited[nx][ny];
			}
		}
	}
	
	ans = max(ans, sum);
	
}

int main(){

	cin >> row >> col;
	
	for(int i=0;i<row;++i){
		for(int j=0;j<col;++j){
			
			char tmp;
			
			cin >> tmp;
			
			if(tmp == 'W')
				maps[i][j] = false;
			else{
				maps[i][j] = true;
				q.push(make_pair(i, j));
				cnt++;
			}
		}	
	}	
	
	for(int i=0;i<cnt;++i){
	
		for(int i=0;i<row;++i){
			for(int j=0;j<col;++j){
				visited[i][j] = 0;	
			}	
		}
		
//		cout <<endl<< q.front().first << ", " << q.front().second<<endl;	
		BFS(q.front().first, q.front().second);
		q.pop();
		
//		print();
	}
		
	cout << ans-1 << endl;	
		
	return 0;	
}