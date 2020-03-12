#include<iostream>
#include<queue>

using namespace std;

struct MOV{
	int x, y;	
};

int R, C, T, ans;
int mat[51][51];
int after[51][51];
int aftcircul[51][51];
MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };
queue<pair< int, int> > q;

void print(){

	cout <<"after circulation"<< endl;
	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){
			cout << aftcircul[i][j] <<" ";
		}
		cout << endl;
	}	
		
}

void BFS(){

	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){	
			if(mat[i][j]!=-1 && mat[i][j]!=0){
				q.push(make_pair(i, j));	
			}
		}
	}
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		int cnt = 0;
		for(int i=0;i<4;++i){
			int nextx = x + mov[i].x;
			int nexty = y + mov[i].y;
			
			if(1<=nextx && nextx<R+1 && 1<=nexty && nexty<C+1 && mat[nextx][nexty]!=-1){
				after[nextx][nexty]+=mat[x][y]/5;
				cnt++;				
			}
		}
		
		after[x][y]+=mat[x][y]-mat[x][y]/5*cnt;		
	}

	/*	
	cout <<endl<<"after spread"<< endl;
	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){
			cout << after[i][j] <<" ";
		}
		cout << endl;
	}
	*/		
		
}

int cond[2];
bool visited[51][51];
void Circulation(){
		
	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){	
			visited[i][j] = false;
		}
	}	
			
	for(int j=2;j<C;++j){
		aftcircul[cond[0]][j+1] = after[cond[0]][j];
		aftcircul[cond[1]][j+1] = after[cond[1]][j];		
		visited[cond[0]][j+1] = true;
		visited[cond[0]][j] = true;
		visited[cond[1]][j+1] = true;
		visited[cond[1]][j] = true;
	}

	for(int i=cond[0];i>1;--i){
		aftcircul[i-1][C] = after[i][C];
		visited[i-1][C] = true;
		visited[i][C] = true;	
	}
	
	for(int i=cond[1];i<R+1;++i){
		aftcircul[i+1][C] = after[i][C];
		visited[i+1][C] = true;
		visited[i][C] = true;				
	}
		
	for(int j=C;j>1;--j){
		aftcircul[1][j-1] = after[1][j];
		aftcircul[R][j-1] = after[R][j];				
		visited[1][j-1] = true;
		visited[R][j-1] = true;
		visited[1][j] = true;
		visited[R][j] = true;
	}	
	
	for(int i=R;i>cond[1]+1;--i){
		aftcircul[i-1][1] = after[i][1];	
		visited[i-1][1] = true;
		visited[i][1] = true;
	}
	
	for(int i=1;i<cond[0]-1;++i){
		aftcircul[i+1][1] = after[i][1];
		visited[i+1][1] = true;
		visited[i][1] = true;	
	}
	
	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){
			if( visited[i][j] == false){
				aftcircul[i][j] = after[i][j];
			}
		}
	}	
	
}

void summ(){
	
	ans=0;
	
	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){
			ans+=aftcircul[i][j];
		}
	}

	ans+=2;
}

int main(){
	
	cin >> R >> C >> T;
	
	int k=0;
	for(int i=1;i<R+1;++i){
		for(int j=1;j<C+1;++j){
			cin >> mat[i][j];
			if(mat[i][j]==-1){
				cond[k] = i;
				k++;
				after[i][j] = -1;
				aftcircul[i][j] = -1;
			}
			
		}
	}

	for(int i=0;i<T;++i){
		
//		cout << "T: "<< i+1 << endl;		
		BFS();
		Circulation();
		summ();
//		cout << ans << endl;
		
		for(int i=1;i<R+1;++i){
			for(int j=1;j<C+1;++j){
				mat[i][j] = aftcircul[i][j];
			}
		}	
		
		for(int i=1;i<R+1;++i){
			for(int j=1;j<C+1;++j){
				if(mat[i][j] == -1){
					after[i][j] = -1;
					aftcircul[i][j] = -1;			
				}
				else{
					after[i][j] = 0;
					aftcircul[i][j] = 0;								
				}
			}
		}
		
	}	
		
	cout << ans << endl;
	
	return 0;	
}

/*

7 8 50
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

7 7 1

0 0 0 0 0 0 0
0 0 0 0 0 0 0
-1 0 0 0 0 0 0
-1 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 10

*/
