#include <iostream>

using namespace std;

struct MOV{
	int x, y;
};

int mat[21][21];

int N, M;
int s_size=2;
int ans, cnt;

MOV mov[4] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
MOV s_loc;

void SAME(){
	
	int x = s_loc.x;
	int y = s_loc.y;

	for(int i=0;i<4;++i){
		int next_x = x + mov[i].x;	
		int next_y = y + mov[i].y;	
		
		
		
	}	
	
}

int main(){
	
	cin>>N;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin >> mat[i][j];
			
			if(mat[i][j] == 9){
				s_loc.x = i;
				s_loc.y = j;
			}	
		}
	}
	
	SAME();
	
	return 0;	
}

/*

3
0 0 0
0 0 0
0 9 0

*/