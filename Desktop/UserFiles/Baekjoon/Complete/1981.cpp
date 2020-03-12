#include<iostream>
#include<queue>
using namespace std;

struct MOV{
	int x, y;
};

struct VIS{
	bool val;
	int depth;
};

int n, ans; 
int maxi = 0;
int mini = INT_MAX;
int mat[101][101];
queue<pair<int, int>> q;
VIS visited[101][101];
MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void print(){
	
	for(int i=1;i<n+1;++i){
		for(int j=1;j<n+1;++j){
			cout << visited[i][j].depth <<" ";
		}
		cout << endl;
	}	
	
	
}

void BFS(int a, int b){

	q.push(make_pair(a,b));
	visited[a][b].val = true;
	visited[a][b].depth = 0;
	
	while(!q.empty()){	
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		if(x==n && y==n){
			break;
		}
				
		for(int i=0;i<4;++i){
			int nextx = x + mov[i].x;
			int nexty = y + mov[i].y;
			
			if(0<nextx && nextx<=n && 0<nexty && nexty<=n && visited[nextx][nexty].val==false){
				visited[nextx][nexty].val = true;
				visited[nextx][nexty].depth = visited[x][y].depth+1;
																
				q.push( make_pair(nextx, nexty) );				
			}
			
			if(mat[nextx][nexty]>maxi)
				maxi = mat[nextx][nexty];
			if(mat[nextx][nexty]<mini)
				mini = mat[nextx][nexty];
			
			cout << maxi-mini << endl;
				
			if(maxi-mini<ans)
				ans = maxi-mini;
			
		}
		
	}
		
	
}

int main(){
	
	cin >> n;
	
	for(int i=1;i<n+1;++i){
		for(int j=1;j<n+1;++j){
			cin >> mat[i][j];
			
			if(mat[i][j]>maxi)
				maxi = mat[i][j];
			if(mat[i][j]<mini)
				mini = mat[i][j];	
		}
	}	
	
	ans = maxi-mini;
	
	BFS(1,1);
		
//	print();
	
	cout << ans << endl;
	
	return 0;	
}

/*

5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1

*/
