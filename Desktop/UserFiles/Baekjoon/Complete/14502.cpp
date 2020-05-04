#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, M, ans = 0;
int mat[9][9], mat2[9][9];
bool visited[9][9];

queue< pair<int, int> > q;
vector< pair<int, int> > q_tmp;

struct MOV{
	int x, y;
};

MOV mov[4] = {{1,0},{0,1},{-1,0},{0,-1}};

void print(){

	int cnt = 0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
//			cout << mat[i][j] <<" ";

			if(mat[i][j] == 0)
				cnt++;
		}
//		cout << endl;
	}	

//	cout << endl;

	ans = max(ans, cnt);

}

void Spread(){

	while(!q.empty()){

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0;i<4;++i){

			int nx = x + mov[i].x;
			int ny = y + mov[i].y;

			if(0<=nx && nx<N && 0<=ny && ny<M && mat[nx][ny] == 0){

				mat[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

void Wall_set(int depth){

	if(depth == 3){

		Spread();
		print();

		/* re-initialize */
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				mat[i][j] = mat2[i][j];

				if(visited[i][j] == true){
					mat[i][j] = 1;
				}
			}
			
		}

		for(int i=0;i<q_tmp.size();++i){
			q.push(make_pair(q_tmp[i].first, q_tmp[i].second));
		}

		return;
	}

	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){

			if(mat[i][j] == 0 && visited[i][j] == false){

				visited[i][j] = true;
				mat[i][j] = 1;

				Wall_set(depth+1);

				visited[i][j] = false;
				mat[i][j] = 0;
			}

		}
	}	

}

int main(){
	
	cin >> N >> M;

	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> mat[i][j];
			mat2[i][j] = mat[i][j];

			if(mat[i][j] == 2){
				q.push(make_pair(i, j));
				q_tmp.push_back(make_pair(i, j));
			}
		}
	}

	Wall_set(0);

	cout << ans << endl;

	return 0;
}

/*

7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

*/