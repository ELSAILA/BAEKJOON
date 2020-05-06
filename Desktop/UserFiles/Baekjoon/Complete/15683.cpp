#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, M, ans = 100000000;

vector< pair<int, int> > cctv;
vector<int> dir;
bool visited[4];

int mat[9][9], tmp[9][9];

void print(){

/*
	cout << endl;
	cout <<"< ";
	for(int i=0;i<dir.size();++i){
		cout << dir[i] << " ";
	}
	cout <<" >"<< endl;


	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
*/

	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){

			if(mat[i][j] == 0)
				cnt++;

		}
	}	

	ans = min(ans, cnt);

}

void left(int x, int y){

	for(int i=y;i>=0;--i){

		if(mat[x][i] == 6)
			break;
		else if(mat[x][i]==0)
			mat[x][i] = 9;
	}

}

void right(int x, int y){

	for(int i=y;i<M;++i){

		if(mat[x][i] == 6)
			break;
		else if(mat[x][i]==0)
			mat[x][i] = 9;		
	}	
}

void up(int x, int y){

	for(int i=x;i>=0;--i){

		if(mat[i][y] == 6)
			break;
		else if(mat[i][y] == 0)
			mat[i][y] = 9;
	}	
}

void down(int x, int y){

	for(int i=x;i<N;++i){

		if(mat[i][y] == 6)
			break;
		else if(mat[i][y] == 0)
			mat[i][y] = 9;
	}	

}

void spread(){

	for(int i=0;i<cctv.size();++i){

		int x = cctv[i].first;
		int y = cctv[i].second;

		// 카메라 유형
		if(mat[x][y] == 1){
			
			if(dir[i] == 1){
				left(x, y);
			}	
			else if(dir[i] == 2){
				right(x, y);
			}			
			else if(dir[i] == 3){
				up(x, y);
			}
			else if(dir[i] == 4){
				down(x, y);
			}			

		}
		else if(mat[x][y] == 2){

			if(dir[i] == 1){
				left(x, y);
				right(x, y);				
			}	
			else if(dir[i] == 2){
				left(x, y);				
				right(x, y);
			}			
			else if(dir[i] == 3){
				up(x, y);
				down(x, y);				
			}
			else if(dir[i] == 4){
				up(x, y);				
				down(x, y);
			}	
		}
		else if(mat[x][y] == 3){

			if(dir[i] == 1){
				left(x, y);
				up(x, y);			
			}	
			else if(dir[i] == 2){
				up(x, y);				
				right(x, y);
			}			
			else if(dir[i] == 3){
				right(x, y);
				down(x, y);				
			}
			else if(dir[i] == 4){
				left(x, y);				
				down(x, y);
			}	
		}
		else if(mat[x][y] == 4){

			if(dir[i] == 1){
				left(x, y);
				up(x, y);
				right(x, y);				
			}	
			else if(dir[i] == 2){
				up(x, y);				
				right(x, y);
				down(x, y);
			}			
			else if(dir[i] == 3){
				right(x, y);
				down(x, y);
				left(x, y);				
			}
			else if(dir[i] == 4){				
				down(x, y);
				left(x, y);
				up(x, y);
			}	

		}
		else if(mat[x][y] == 5){

				up(x, y);
				down(x, y);				
				right(x, y);
				left(x, y);			
		}
	}

}

void DFS(int num_of_cctv, int depth){

	if(depth == num_of_cctv){

		spread();
		print();


		/* initialize q & matrix */
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				mat[i][j] = tmp[i][j];
			}
		}

		return;
	}

	for(int i=1;i<=4;++i){

			dir.push_back(i);
			DFS(num_of_cctv, depth+1);
			dir.pop_back();

	}

}

int main(){
	
	cin >> N >> M;	


	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> mat[i][j];
			tmp[i][j] = mat[i][j];

			if(mat[i][j]>=1 && mat[i][j]<=5){
				cctv.push_back(make_pair(i, j));
			}
		}
	}

	int ct = cctv.size();

	if(ct != 0){
		DFS(ct, 0);
		cout << ans << endl;
	}
	else{
		print();
		cout << ans << endl;
	}

	return 0;
}


/*

1, 2, 3, 4, 5

1 ~ 4

1 1 1 1 1
1 1 1 1 2
...
4 4 4 4 4

4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0 6 0
0 0 0 0 0 0

*/