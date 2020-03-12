#include <iostream>

using namespace std;

#define MAX 21

struct MOV{
	int x, y;
};

struct DICE{
	int t, b, l, r, u, d;
};

int N,M,A,B,K,x,y,top;
int maps[MAX][MAX];
MOV mov[4] = {{0,1},{0,-1},{-1,0},{1,0}}; 
DICE dice;

void Dice_roll(int a, int b){
	
	// east
	if(a==0 && b==1){
		
//		cout << "EAST" << endl;
		
		int tmp = dice.r;
		dice.r = dice.t;
		dice.t = dice.l;
		dice.l = dice.b;
		dice.b = tmp;		
		
		return;
	}

	// west
	if(a==0 && b==-1){

//		cout << "WEST" << endl;
				
		int tmp = dice.r;
		dice.r = dice.b;
		dice.b = dice.l;
		dice.l = dice.t;
		dice.t = tmp;		
				
		return;
	}

	// south
	if(a==1 && b==0){
		
//		cout << "SOUTH" << endl;
				
		int tmp = dice.u;
		dice.u = dice.b;
		dice.b = dice.d;
		dice.d = dice.t;
		dice.t = tmp;	
				
		return;
	}

	// north
	if(a==-1 && b==0){

//		cout << "NORTH" << endl;
		
		int tmp = dice.t;
		dice.t = dice.d;
		dice.d = dice.b;
		dice.b = dice.u;
		dice.u = tmp;	
		return;
	}
				
}

void Search(int dir){

	int nx = x + mov[dir].x;
	int ny = y + mov[dir].y;
	
	if(0>nx || nx>=N || 0>ny || ny>=M){
		
//		cout << "GO AWAY!!" << endl;
		return;
	}
	
	Dice_roll(mov[dir].x, mov[dir].y);
	
	if(maps[nx][ny] == 0){
		maps[nx][ny] = dice.b;
	}
	else{
		dice.b = maps[nx][ny];
		maps[nx][ny] = 0;
	}	
	
	cout << dice.t << endl;
	
	x = nx;
	y = ny;
	
	return;
}

int main(){
	
	cin >> N >> M >> A >> B >> K;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> maps[i][j];
		}
	}
	
	x = A;
	y = B;
	
	for(int i=0;i<K;++i){
		int tmp;
		cin >> tmp;
		
		Search(tmp-1);
	}
	
	return 0;	
}

/*

4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3

2 2 0 0 16
0 2
3 4
4 4 4 4 1 1 1 1 3 3 3 3 2 2 2 2

3 3 0 0 16
0 1 2
3 4 5
6 7 8
4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2

1 4 0 0 3
0 1 2 3
1 1 1

*/
