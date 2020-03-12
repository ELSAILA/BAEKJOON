#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M, K;
int ans = 1000000;
int mat[51][51];
int mat2[51][51];
int tmp[51][51];

vector<tuple<int, int, int>> m;

void print(){

	for(int i=1;i<N+1;++i){
		for(int j=1;j<M+1;++j){ 
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}	
	
}

void mov(int x1, int y1, int x2, int y2, int d){
	
	while(x1!=x2 && y1!=y2){
	
		//up
		for(int i=x1+d-1;i>x1;--i){
			tmp[i-1][y1] = mat[i][y1];
		}

		//down
		for(int i=x1;i<x1+d-1;++i){
			tmp[i+1][y2] = mat[i][y2];
		}
		
		//l->r
		for(int j=y1;j<y1+d-1;++j){
			tmp[x1][j+1] = mat[x1][j];
		}
		
		//r->l
		for(int j=y1+d-1;j>y1;--j){
			tmp[x2][j-1] = mat[x2][j];
		}
		
		
//		print();		
			
		x1+=1;
		y1+=1;
		x2-=1;
		y2-=1;	
		d-=2;

		for(int i=1;i<N+1;++i){
			for(int j=1;j<M+1;++j){
				mat[i][j] = tmp[i][j];			
			}	
		}					
	}
	
	int sum=0;
	for(int i=1;i<N+1;++i){
		for(int j=1;j<M+1;++j){
			sum+=mat[i][j];
		}
		
		ans = min(ans, sum);
		sum=0;
	}
	
}

int main(){
	
	cin >> N >> M >> K;
	
	for(int i=1;i<N+1;++i){
		for(int j=1;j<M+1;++j){
			cin >> mat[i][j];
			tmp[i][j] = mat[i][j];
			mat2[i][j] = mat[i][j];
		}	
	}
	
	int r, c, s;
	for(int i=0;i<K;++i){
		cin >> r >> c >> s;
		
		m.push_back(make_tuple(r, c, s));					
	}
	
	sort(m.begin(), m.end());
	
	do{
				
		for(int i=0;i<m.size();++i){
				
			tuple<int, int, int> t = m[i];	
			int y = get<0>(t);			
			int x = get<1>(t);
			int s = get<2>(t);
			
//			cout << y << ", "<<x <<", "<< s<<endl;
			
			mov(y-s, x-s, y+s, x+s, 2*s+1);
//			print();						
		}
		
		for(int i=1;i<N+1;++i){
			for(int j=1;j<M+1;++j){
				mat[i][j] = mat2[i][j];
				tmp[i][j] = mat2[i][j];
			}
		}					
			
			
	}while(next_permutation(m.begin(), m.end()));
			
	cout << ans << endl;	
		
	return 0;	
}

/*
5 6 2
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
4 2 1
3 4 2

next_permutation 버리자이병신같은거

*/
