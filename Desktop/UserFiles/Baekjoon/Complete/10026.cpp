#include <iostream>
#include <queue>

using namespace std;

int N, cnt, cnt1, cnt2;
char matrix[101][101];
bool visited[101][101];
queue< pair<int, int> > q;

typedef struct {
	int x, y;
}MOV;

MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };


void print(){

		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
}	

void nodys(int x, int y){
	
	visited[x][y] = true;
	
	cnt++;
	q.push( make_pair(x, y) );
	
	while(!q.empty()){
			
		pair<int, int> node = q.front();
		q.pop();
				
		for(int i=0;i<4;++i){
			pair<int, int> nextloc;
			
			nextloc.first = node.first + mov[i].x;
			nextloc.second = node.second + mov[i].y;
			
			if(nextloc.first >=0 && nextloc.first <N && nextloc.second >=0 && nextloc.second <N && matrix[node.first][node.second] == matrix[nextloc.first][nextloc.second] && visited[nextloc.first][nextloc.second] == false){
				q.push( make_pair(nextloc.first, nextloc.second) );
				
				visited[nextloc.first][nextloc.second] = true;
			}
		}
	}
}


int main(){
	
	cin >> N;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin >> matrix[i][j];
		}
	}
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(visited[i][j] == false){
				nodys(i,j);
			}
			else
				continue;
		}
	}	
	
	cnt1 = cnt;
	cnt = 0;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			visited[i][j] = false;
		}
	}	
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(matrix[i][j] == 'G')
				matrix[i][j] = 'R';
		}
	}
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(visited[i][j] == false){
				nodys(i,j);
			}
			else
				continue;
		}
	}	
	
	cnt2 = cnt;
	
	cout << cnt1 << " " << cnt2 << endl;
		
	return 0;	
}

/*


if visited all -> cnt++;

move -> 8 directions

5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

*/
