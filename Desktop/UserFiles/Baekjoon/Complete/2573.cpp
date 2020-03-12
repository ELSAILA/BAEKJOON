#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DIRI{
	int x, y;
};

#define MAX 301

DIRI dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int N, M, ans;
int mat[MAX][MAX];
int n_mat[MAX][MAX];

queue< pair<int, int> > cur_loc;

void print(){
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cout << n_mat[i][j] << " ";
		}
		cout << endl;
	}		
	
}

bool is_one(int ice){
		
	int stx = cur_loc.front().first;
	int sty = cur_loc.front().second;
	queue< pair<int, int> > find;
	bool visited[MAX][MAX];
	int v_cnt = 0;
	
	find.push(make_pair(stx, sty));	
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			visited[i][j] = false;
		}	
	}
		
	while(!find.empty()){
	
		int chx = find.front().first;
		int chy = find.front().second;
		visited[chx][chy] = true;
				
		find.pop();
				
		for(int i=0;i<4;++i){
						
			int nx = chx + dir[i].x;
			int ny = chy + dir[i].y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M && mat[nx][ny]!=0 && visited[nx][ny]==false){
				
				find.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				v_cnt++;
			}	
		}
		
	}
		
	if(v_cnt+1==ice){
		ans++;
		return true;
	}
	return false;
	
}

void Year(){
		
	while(!cur_loc.empty()){
		
		int cnt = 0;
		int x = cur_loc.front().first;
		int y = cur_loc.front().second;
		cur_loc.pop();
		
		for(int i=0;i<4;++i){
			int nx = x + dir[i].x;
			int ny = y + dir[i].y;
			
			if(mat[nx][ny]==0){
				cnt++;	
			}
		}
		
		n_mat[x][y] = mat[x][y] - cnt;
				
		if(n_mat[x][y]<0)
			n_mat[x][y] = 0;
		
	}	
		
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			mat[i][j] = n_mat[i][j];
			
			if(mat[i][j]!=0)
				cur_loc.push(make_pair(i, j));
		}
	}	
			
}

bool is_over(){

	int tmp=0;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){		
			if(mat[i][j]!=0)
			tmp++;		
		}
	}
	
	if(tmp!=0)
		return false;
	return true;
	
}

int main(){
	
	cin >> N >> M;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> mat[i][j];
			
			if(mat[i][j]!=0)
				cur_loc.push(make_pair(i, j));
		}		
	}
	
	while( is_one(cur_loc.size()) ){
		Year();			
		
		if(is_over()){
			ans = 0;	
		}
			
	}	
	
	cout << ans << endl;
		
	return 0;	
}

/*

5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

5 7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 7 0 0 0 0 0
0 0 0 0 0 0 0



40 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0 
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0 
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 10 10 10 10 1 10 10 10 10 10 10 10 10 10 10 10 10 10 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

7 7
0 0 0 0 0 0 0
0 9 9 9 9 9 0
0 9 0 1 0 9 0
0 9 0 9 0 9 0
0 9 0 0 0 9 0
0 9 9 9 9 9 0
0 0 0 0 0 0 0
*/