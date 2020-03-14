#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 51

struct VR{
	int x, y;
};

struct MOV{
	int x, y;
};

int mat[MAX][MAX], mat2[MAX][MAX];
int N, M, ans = 100000000;
int zero_num, zero_tmp;
bool visited[MAX], flag;
bool mat_visited[MAX][MAX];
vector <VR> vr_loc;
MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void print(){
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void spread(){
	
	queue< pair<int, int> > q;
	
	for(int i=0;i<vr_loc.size();++i){
		
		if(visited[i] == true){
			q.push( make_pair(vr_loc[i].x, vr_loc[i].y) );	
			mat_visited[vr_loc[i].x][vr_loc[i].y] = true;
		}
	}
	
	while(!q.empty()){
	
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;++i){
			
			int nextx = x + mov[i].x;
			int nexty = y + mov[i].y;
			
			if(0<=nextx && nextx<N && 0<=nexty && nexty<N && (mat[nextx][nexty]==2 || mat[nextx][nexty]==0) && mat_visited[nextx][nexty] == false && zero_num!=0){

				if(mat[nextx][nexty] == 0){
					zero_num--;
				}
				
				mat[nextx][nexty] = mat[x][y]+1;
				mat_visited[nextx][nexty] == true;			
				q.push(make_pair(nextx, nexty));
			}
			
		}
		
	}
	
	int spm = 0;
	int cnt = 0;	
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){			
			if(mat[i][j]==0)
				cnt++;
		}
	}
	
	if(cnt==0){
	
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){			
				spm = max(spm, mat[i][j]);
			}
		}

		ans = min(ans, spm);
		flag = true;
	}
		
//	print();
}

void BFS(int start, int depth){

	if(depth == M){
		
		// cout << endl << "< ";
		// for(int i=0;i<vr_loc.size();++i){
		// 	cout <<visited[i] << " ";	
		// }
		// cout << " >" <<endl;
		
		spread();
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				mat[i][j] = mat2[i][j];
			}
		}
		
		memset(mat_visited,false,MAX*MAX);
		zero_num = zero_tmp;
		
		return;
	}
	
	for(int i=start;i<vr_loc.size();++i){
		
		if(visited[i] == false){
			visited[i] = true;
			BFS(i, depth+1);
			visited[i] = false;			
		}		
	}
	
}

int main(){

	cin >> N >> M;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin >> mat[i][j];
			mat2[i][j] = mat[i][j];
			
			if(mat[i][j] == 2){
				VR vr;
				vr.x = i;
				vr.y = j;
				vr_loc.push_back(vr);
			}
			
			if(mat[i][j] == 0){
				zero_num++;
			}			
			
		}	
	}
	
	zero_tmp = zero_num;
	
	BFS(0,0);
	
	if(flag == false){
		cout << -1 <<endl;	
	}
	else{
		cout << ans-2 << endl;
	}
	
	return 0;	
}


/*


7 3
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 0 0 2

*/