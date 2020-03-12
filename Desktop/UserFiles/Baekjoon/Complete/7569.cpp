#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static bool sync_with_stdio;

/* 아무리 봐도 터질 것 같은데... */
/* 높이 고려 제대로 안됨 */
struct MOV{
	int x, y, z;
};

int M,N,H, cnt;
int unrotten;
queue<MOV> q;
MOV mov[6] = { {1,0,0},{0,1,0},{-1,0,0},{0,-1,0},{0,0,1},{0,0,-1} };
int mat[101][101][101];
bool visited[101][101][101];

void print(){
		
	cout << endl;
	for(int k=0;k<H;++k){
		cout << k<<"th floor" << endl;
		for(int i=0;i<N;++i){	
			for(int j=0;j<M;++j){	
				cout << mat[i][j][k]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	
}

void dayafter(int a, int b, int c){

	q.push({a,b,c});				
	visited[a][b][c] = true;
				
	while(!q.empty()){
		
		int tmp = q.size();
		
for(int p=0;p<tmp;++p){
		
		int x = q.front().x;		
		int y = q.front().y;		
		int z = q.front().z;
		q.pop();
										
		for(int i=0;i<4;++i){
			int nextx = x + mov[i].x;
			int nexty = y + mov[i].y;
			int nextz = z + mov[i].z;
			
			if(0<=nextx && nextx<N && 0<=nexty && nexty<M && mat[nextx][nexty][z]==0 && visited[nextx][nexty][z] == false){
				unrotten--;	
				visited[nextx][nexty][z] = true;
				mat[nextx][nexty][z] = 1;
				q.push({nextx,nexty,z});
			}				
		}	
		
		for(int i=4;i<6;++i){

			int nextz = z + mov[i].z;			
			if(0<=nextz && nextz<H && mat[x][y][nextz]==0 && visited[x][y][nextz] == false){
				unrotten--;	
				visited[x][y][nextz] = true;
				mat[x][y][nextz] = 1;
				q.push({x,y,nextz});
			}
		}
		
}		
		
		cnt++;
//		cout << "unrot: "<<unrotten << endl;
//		print();

		if(unrotten==0)
			return;	
		
	}


		
}

int main(){

	cin >> M >> N >> H;

	for(int k=0;k<H;++k){
		for(int i=0;i<N;++i){	
			for(int j=0;j<M;++j){	
				cin >> mat[i][j][k];
				
				if(mat[i][j][k] == 0){
					unrotten++;
				}
				
				if(mat[i][j][k] == 1){
					q.push({i,j,k});	
				}
				
			}
		}
	}

	
	for(int k=0;k<H;++k){
		for(int i=0;i<N;++i){	
			for(int j=0;j<M;++j){	
				if(mat[i][j][k]==1 && unrotten>0){
					dayafter(i,j,k);		
				}
				else
					continue;
			}
		}
	}
				
							
	if(unrotten==0)
		cout << cnt << endl;
	else
		cout << -1 << endl;
		
	return 0;
}	

/*

5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

6 4 1
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1


*/
