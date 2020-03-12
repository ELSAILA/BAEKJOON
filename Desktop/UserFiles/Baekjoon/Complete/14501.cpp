#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int day[16][2];
bool visited[16];

void check(){
	
	for(int i=0;i<N;++i){
		
		if(visited[i] == true){
			cout << i << " ";
		}	
	}

	cout << endl;
}


void DFS(int start, int money){
	
	if(start > N){

//		check();

//		cout << "A" << endl;
						
		for(int i=N-1;i>=0;--i){
			
			if(visited[i] == true){
				money-=day[i][1];	
				break;
			}			
		}
		
		ans = max(ans,money);
					
		return;
	}
	else if(start == N-1){
		
//		check();
//		cout << "B" << endl;
		
		if(day[N-1][0]>1)
				;
		else
			money+=day[N-1][1];		

		ans = max(ans,money);
						
		return;
	}
	else if(start == N){
		
//		check();
//		cout << "C" << endl;	

		ans = max(ans,money);
			
		return;		
	}

		
	for(int i=start;i<N;++i){
		
		if(visited[i] == false){
			visited[i] = true;
						
			DFS(i+day[i][0], money+day[i][1]);
			visited[i] = false;
			
		}
		
	}
	
}

int main(){

	cin >> N;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<2;++j){
			cin >> day[i][j];
		}	
	}
	
	for(int i=0;i<N;++i){
		DFS(i, 0);
	}
	
	cout << ans << endl;
	
	return 0;	
}

