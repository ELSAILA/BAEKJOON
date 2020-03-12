#include <iostream>

using namespace std;

int N;
int test[101],ans[6];

void dfs(int depth, int src){
	
	// print out
	if(depth == 6){
		
		for(int i=0;i<6;++i){
			cout << ans[i] << " ";
		}
		
		cout << endl; 
		return;
	}	
		
	// dfs search
	for(int i=src;i<N;++i){
		ans[depth] = test[i];		
		dfs(depth+1, i+1);
	}
	
}

int main(){
	
	while(1){
			
		cin >> N;	
		
		if(N==0)
			break;
	
		for(int i=0;i<N;++i){
			test[i] = 0;
		}		
					
		for(int i=0;i<N;++i){
			cin >> test[i];
		}
	
		dfs(0,0);		
		cout << endl;
	}
	
	return 0;	
}

/*

7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

*/
