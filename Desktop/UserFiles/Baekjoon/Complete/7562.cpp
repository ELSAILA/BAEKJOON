#include <iostream>
#include <queue>

using namespace std;

struct MOV{
	int x, y;
};

struct VST{
	bool val;	
	int depth;
};

VST visited[301][301];
int I, TestCase, cnt;
int srtx,srty,endx,endy;	
MOV mov[8] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };

void print(){

	cout << endl;
	for(int i=0;i<I;++i){
		for(int j=0;j<I;++j){
			cout << visited[i][j].depth << " ";
		}		
		cout << endl;
	}

}

void KnightMove(int a, int b){

	queue< pair<int, int> > q;
		
	visited[a][b].val = true;
	visited[a][b].depth = 0;
	q.push(make_pair(a, b));
	
	while(!q.empty()){
		int x = q.front().first;	
		int y = q.front().second;	
		q.pop();
				
		for(int i=0;i<8;++i){
			int nextx = x + mov[i].x;
			int nexty = y + mov[i].y;
				
			if(0<=nextx && nextx<I && 0<=nexty && nexty<I && visited[nextx][nexty].val == false){
				visited[nextx][nexty].depth = visited[x][y].depth+1;
				visited[nextx][nexty].val = true;
				
				if(nextx == endx && nexty == endy){
					return;
				}
				else
					q.push( make_pair(nextx, nexty) );					
			}
		}
		
//		print();
	}
	
}

int main(){

	cin >> TestCase;

	while(TestCase!=0){	

		cin >> I;	
		cin >> srtx >> srty;
		cin >> endx >> endy;
						
		for(int i=0;i<I;++i){
			for(int j=0;j<I;++j){
				visited[i][j].val = false;
			}		
		}
		
		KnightMove(srtx, srty);	
		cout << visited[endx][endy].depth << endl;
					
		TestCase--;
	}
			
	return 0;	
}

/*

1
8
0 0
7 0

1
4
3 2
0 2

1
100
0 0
30 50

3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1

*/