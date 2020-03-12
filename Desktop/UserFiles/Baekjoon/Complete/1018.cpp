#include <iostream>

using namespace std;

int N, M;
bool mat[51][51];
int ans=64;

struct MOV{
	int x, y;	
};

MOV mov[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int min(int x, int y){
	
	if(x>y)
		return y;
	return x;
	
}

void check(int x, int y){
	
	int test[51][51];
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			test[i][j] = mat[i][j];		
		}
	}		
		
	
	int cnt=0;
	int cur_x = x, cur_y = y;		
	
		if(test[x][y]==true)
			;
		else{
			test[x][y] = true;		
			cnt++;
		}
		
		for(int k=cur_x;k<cur_x+8;++k){				
			for(int j=cur_y;j<cur_y+8;++j){
				
				for(int i=0;i<4;++i){
					int nextx = k+mov[i].x;
					int nexty = j+mov[i].y;
					
					if(test[k][j] == test[nextx][nexty] && cur_x<=nextx && nextx<cur_x+8 && cur_y<=nexty && nexty<cur_y+8){
						test[nextx][nexty] = !test[k][j];
			
						cnt++;
					}
					else
						continue;
				}
			}		
		}
					
		ans = min(ans, cnt);

		
		cnt = 0;
		
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				test[i][j] = mat[i][j];		
			}
		}		
		
		if(test[x][y]==false)
			;
		else{
			test[x][y] = false;		
			cnt++;
		}
		
		for(int k=cur_x;k<cur_x+8;++k){				
			for(int j=cur_y;j<cur_y+8;++j){
				
				for(int i=0;i<4;++i){
					int nextx = k+mov[i].x;
					int nexty = j+mov[i].y;
					
					if(test[k][j] == test[nextx][nexty] && cur_x<=nextx && nextx<cur_x+8 && cur_y<=nexty && nexty<cur_y+8){
						test[nextx][nexty] = !test[k][j];
								
						cnt++;
					}
					else
						continue;
				}
			}
			
		}

		ans = min(ans, cnt);		
	
}

int main(){

	cin >> N >> M;
	
	int test[51][51];
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			
			char tmp;
			cin >> tmp;
			
			if(tmp == 'B'){
				mat[i][j] = true;
			}
			else{
				mat[i][j] = false;
			}
		}
	}
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			
			if(i+8<=N && j+8<=M){				
				check(i, j);
			}			
		}		
	}		
		
	cout << ans << endl;	
			
	return 0;	
}

/*

8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW

10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB

8 8
BBBBWBBW
WWWWBBWB
WWBBWBWW
WBWWBWBW
WBBWBBWB
BWBWBWWB
BWWWWWBW
BWBBBBWW

*/
