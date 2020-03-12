#include <iostream>

using namespace std;

struct CHS{
	int color = 2;
	bool mal;	
};

struct MOV{
	int x, y;
};

CHS mat[8][8];
MOV mov[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int ans;

void print(){
	
	for(int i=0;i<8;++i){	
		for(int j=0;j<8;++j){	
			cout << mat[i][j].color << " ";
		}
		cout << endl;
	}
}

void BFS(int x, int y){
		
	for(int i=0;i<4;++i){
		
		int next_x = x+mov[i].x;
		int next_y = y+mov[i].y;
		
		if(0<=next_x && next_x<8 && 0<=next_y && next_y<8 && mat[next_x][next_y].color == 2){
			
			if(mat[x][y].color==0)
				mat[next_x][next_y].color = 1;
			else
				mat[next_x][next_y].color = 0;
		}
	}
			
}

int main(){
	
	mat[0][0].color = 0;
	
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			BFS(i,j);
		}
	}
			
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			char tmp;
			cin >> tmp;
			
			if(tmp == 'F' && mat[i][j].color == 0){
				mat[i][j].mal = true;
				ans++;	
			}
		}	
	}
	
	cout << ans << endl;
	
	
	return 0;	
}

/*

.F.F...F
F...F.F.
...F.F.F
F.F...F.
.F...F..
F...F.F.
.F.F.F.F
..FF..F.

*/