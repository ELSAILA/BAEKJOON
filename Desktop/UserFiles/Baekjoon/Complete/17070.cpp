#include <iostream>

using namespace std;

struct MOV{
	int x, y;	
};

MOV mov[3] = {{1,0},{0,1},{1,1}};

int ans, N, mat[17][17];

void print(){

	cout << endl;
	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}	
	
}

void BFS(int fx, int fy, int tx, int ty){

	mat[tx][ty] = 3;
//	print();
	
	if(tx == N && ty == N){
		ans++;
//		print();
		return;
	}
	
	int tmpx = tx - fx;
	int tmpy = ty - fy;
	int nx=0, ny=0;
	
	if(tmpx == 0 && tmpy == 1){
				
		nx = tx + mov[1].x;	
		ny = ty + mov[1].y;	
		
		if(0<=nx && nx<N+1 && 0<=ny && ny<N+1 && mat[nx][ny]==0){
			BFS(tx, ty, nx, ny);			
			mat[nx][ny] = 0;	
		}
		
		nx = tx + mov[2].x;	
		ny = ty + mov[2].y;	
		
		if(0<=nx && nx<N+1 && 0<=ny && ny<N+1 && mat[nx][ny]==0 && mat[tx+1][ty]==0 && mat[tx][ty+1]==0){
			BFS(tx, ty, nx, ny);
			mat[nx][ny] = 0;
		}
				
	}
	else if(tmpx == 1 && tmpy == 1){
				
		for(int i=0;i<3;++i){
		
			nx = tx + mov[i].x;	
			ny = ty + mov[i].y;	
			
			if(i!=2){
				
				if(0<=nx && nx<N+1 && 0<=ny && ny<N+1 && mat[nx][ny]==0){
					BFS(tx, ty, nx, ny);			
					mat[nx][ny] = 0;	
				}		
			}	
			else{
				
				if(0<=nx && nx<N+1 && 0<=ny && ny<N+1 && mat[nx][ny]==0 && mat[tx+1][ty]==0 && mat[tx][ty+1]==0){
					BFS(tx, ty, nx, ny);
					mat[nx][ny] = 0;
				}
													
			}	
		}
		
	}
	else if(tmpx == 1 && tmpy == 0){
				
		nx = tx + mov[0].x;	
		ny = ty + mov[0].y;	
		
		if(0<=nx && nx<N+1 && 0<=ny && ny<N+1 && mat[nx][ny]==0){
			BFS(tx, ty, nx, ny);			
			mat[nx][ny] = 0;			
		}
		
		nx = tx + mov[2].x;	
		ny = ty + mov[2].y;	
		
		if(0<=nx && nx<N+1 && 0<=ny && ny<N+1 && mat[nx][ny]==0 && mat[tx+1][ty]==0 && mat[tx][ty+1]==0){
			BFS(tx, ty, nx, ny);
			mat[nx][ny] = 0;
		}				
	}
	
	
	return;
	
}


int main(){
	
	cin >> N;
	
	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j){
			cin >> mat[i][j];	
		}	
	}	
					
	mat[1][1] = 3;
	BFS(1,1,1,2);
	
	cout << ans << endl;
	
	return 0;	
}

/*

4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

*/
