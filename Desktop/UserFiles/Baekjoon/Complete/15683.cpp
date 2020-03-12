#include <iostream>
#include <vector>

using namespace std;

char mat[9][9];
vector< pair<int, int> > cctvloc;

int N, M;

int main(){
	
	cin >> N >> M;
	
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> mat[i][j];
			
			if(mat[i][j] != 0 && mat[i][j] != 6){
				cctvloc.push_back( make_pair(i, j) );
				cnt++;
			}	
		}
	}

	bool flag=true;	
	while(flag){
		
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				
			}			
		}	
		
	}
	
				
	return 0;	
}
