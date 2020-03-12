#include <iostream>
#include <queue>
#include <cstring>

static bool sync_with_stdio;

using namespace std;

struct MOV{
	int x, y;
};

int N, waterheight, ans;
int mat[101][101];
bool notdrowned[101][101];
MOV mov[4] = { {1,0},{0,1},{-1,0},{0,-1} };
queue< pair<int, int> > q;

void print(){

	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout << notdrowned[i][j] << " ";		
		}
		cout << endl;
	}
}

void drowncheck(int a, int b){
	
	notdrowned[a][b] = true;
	q.push(make_pair(a, b));	
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;++i){
			int nextx = x + mov[i].x;	
			int nexty = y + mov[i].y;	
			
			if(0<=nextx && nextx<N && 0<=nexty && nexty<N && mat[nextx][nexty]>waterheight && notdrowned[nextx][nexty] == false){
				notdrowned[nextx][nexty] = true;
				q.push( make_pair(nextx, nexty) );
			}
			
		}			
	}
	
}

int main(){

	cin >> N;	
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin >> mat[i][j];
			
			if(mat[i][j]>waterheight)
				waterheight = mat[i][j];		
		}
	}
	

	while(waterheight>=0){
		
		int cnt = 0;
				
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){	
				notdrowned[i][j] = false;
			}		
		}
							
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){			
				if(mat[i][j]>waterheight && notdrowned[i][j] == false){
					cnt++;
					drowncheck(i, j);	
				}
						
			}
		}
	
//		cout << "waterheight: " << waterheight << endl;
//		cout << "cnt: "<<cnt<<endl;
//		print();	
		
//		cout << endl;
		
				
		if(cnt>ans)
			ans = cnt;
	
		waterheight--;
	}
	
	cout << ans << endl;
			
	return 0;	
}

/*

7
9 9 9 9 9 9 9
9 2 1 2 1 2 9
9 1 8 7 8 1 9
9 2 7 9 7 2 9
9 1 8 7 8 1 9
9 2 1 2 1 2 9
9 9 9 9 9 9 9
6

5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

3
1 2 1 
1 1 1 
1 1 3 

*/
