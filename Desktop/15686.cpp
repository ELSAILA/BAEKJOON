#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 15686
using namespace std;

#define MAX 51

struct PR{
	int x, y, dist;
};

int mat[MAX][MAX];
int N, M, ans = 100000000;
bool visited[MAX];
vector<PR> chik, home;

void print(){

	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	
}

void check(){
	
	int b_dist=0;
	
	for(int i=0;i<home.size();++i){
		
		int hx = home[i].x;
		int hy = home[i].y;
		
		for(int j=0;j<chik.size();++j){

			if(visited[j] == false){			
				int tmp = abs(hx - chik[j].x) + abs(hy - chik[j].y);			
				home[i].dist = min(home[i].dist, tmp);
			}
			else
				continue;
		}
		
		b_dist += home[i].dist;
	}
	
	ans = min(ans, b_dist);
}

void DFS(int start, int depth, int cnt){
	
	if(depth == cnt){

		check();
		
		for(int i=0;i<home.size();++i){
			home[i].dist = 10000000;	
		}
		
		return;
	}
	
	for(int i=start;i<chik.size();++i){
		
		if(visited[i] == false){
		
			visited[i] = true;
			DFS(i, depth+1, cnt);
			visited[i] = false;
		}
		
		
	}
	
	
}


int main(){

	cin >> N >> M;

	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin >> mat[i][j];
			
			if(mat[i][j] == 2){
				PR pr;
				pr.x = i;
				pr.y = j;
				pr.dist = 0;
				chik.push_back(pr);
				cnt++;
			}
			
			if(mat[i][j] == 1){
				PR pr;
				pr.x = i;
				pr.y = j;
				pr.dist = 100000000;
				home.push_back(pr);
			}
		}
	}
	
	cnt-=M;
	
	DFS(0, 0, cnt);

	cout << ans << endl;
	
	return 0;
}

/*


5 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1

5 1
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0

5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2

*/


