#include <iostream>
#include <queue>

using namespace std;

int n, src, dst, m, depth, flag, d;
int mat[101][101];
int visited[101][101];
queue< pair<int, int> > q;

void print(){

	for(int i=1;i<n+1;++i){	
		for(int j=1;j<n+1;++j){	
			cout << visited[i][j] << " ";	
		}
		cout << endl;
	}		
}

void BFS(int loc){
	
	q.push( make_pair(loc, 0) );
	while(!q.empty() && flag == false){
		
		int now = q.front().first;
		int deep = q.front().second;
		
		q.pop();
						
		for(int next=1;next<n+1;++next){
			
			if(mat[now][next] == 1 && visited[now][next] == 0){
				visited[now][next] = 1;	
				visited[next][now] = 1;	
								
				q.push( make_pair(next, deep+1) );
							
				d = deep+1;	
				
			}
			
			if(next==dst && visited[now][next]!=0){
				flag = true;
				break;
			}
		}
				
	}
	
}

int main(){
	
	cin >> n >> src >> dst >> m;
	
	int from, to;
	for(int i=1;i<m+1;++i){
		cin >> from >> to;
		mat[from][to] = 1;
		mat[to][from] = 1;

	}	
	
	BFS(src);
	
	if(flag == true)
		cout << d << endl;
	else
		cout << -1 << endl;
					
	return 0;	
}

/*

9
7 4
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6

7
4 7
6
1 2
1 3
2 4
2 5
2 6
3 7

*/
