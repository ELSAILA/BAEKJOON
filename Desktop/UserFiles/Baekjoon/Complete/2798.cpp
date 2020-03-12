#include <iostream>
#include <vector>

using namespace std;

int N, M;
int card[100];
bool used[100];
int ans = 0;

void DFS(int loc, int cnt){
	
	if(cnt == 3){
		int tmp = 0;
		for(int i=0;i<N;++i){
			if(used[i]==true){
				tmp+=card[i];
			}
		}
			
		if(tmp>ans && tmp<=M){
			ans = tmp;
		}
			
		return;			
	}
	
	for(int i=loc;i<N;++i){
		
		if(used[i]==true)
			continue;			
		
		used[i] = true;		
		DFS(i, cnt+1);	
		used[i] = false;
		
	}
	
}

int main(){
	
	cin >> N >> M;
		
	for(int i=0;i<N;++i){
		cin >> card[i]; 
	}
		
	DFS(0,0);
		
	cout << ans << endl;
		
	return 0;	
}

/*

5 10
1 2 3 4 10

5 21
5 6 7 8 9

*/
