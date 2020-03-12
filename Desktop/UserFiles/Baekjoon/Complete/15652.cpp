#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];
vector<int> save;

void DFS(int start, int depth){
	
	if(depth == M){
		
		for(int i=0;i<save.size();++i){
			cout << save[i] << " ";	
		}
		cout << endl;	
	
		return;	
	}
	
	for(int i=start;i<=N;++i){
		
		save.push_back(i);		
		DFS(i, depth+1);
		save.pop_back();
	}
	
}

int main(){
	
	cin >> N >> M;

		DFS(1, 0);
	
	return 0;	
}