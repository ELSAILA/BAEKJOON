#include <iostream>
#include <vector>

using namespace std;

struct MOV{
	int x, y;	
};

int R, C, tmp;
bool visited[26];
char mat[21][21];
int ans = 1;

MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int cmp(int x, int y){
	
	if(x>y)
		return x;
	return y;
		
}

void DFS(int x, int y, int cnt){
	
	int idx = mat[x][y] - 65;
	visited[idx] = true;	
	
	for(int i=0;i<4;++i){
		int nextx = x + mov[i].x;
		int nexty = y + mov[i].y;
		
		if(0<=nextx && nextx<R && 0<=nexty && nexty<C && visited[mat[nextx][nexty] - 65] == false){
			
			DFS(nextx, nexty, cnt+1);
			visited[mat[nextx][nexty] - 65] = false;
		}
	}	
	ans = cmp(cnt, ans);
			
}


int main(){
	
	cin >> R >> C;
	
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin >> mat[i][j];		
		}			
	}
		
	DFS(0,0,1);
		
	cout << ans << endl;
		
	return 0;	
}

/*

2 4
CAAB
ADCB

3 6
HFDFFB
AJHGDH
DGAGEH

5 5
IEFCJ
FHFKC
FFALF
HFGCF
HMCHH

*/
