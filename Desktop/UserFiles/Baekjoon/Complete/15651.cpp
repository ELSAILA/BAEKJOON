#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[9];
vector<int> arr;

void print(){

	for(int i=0;i<arr.size();++i){
		cout << arr[i] << " ";
	}	
	cout << endl;
	
}

void DFS(int depth){
	
	if(depth == M){
		print();
		return;	
	}
	
	for(int i=1;i<N+1;++i){
		
//		if(visited[i] == false){
//			visited[i] = true;
			arr.push_back(i);			
			DFS(depth+1);
//			visited[i] = false;
			arr.pop_back();			
		}
		
	}
	
//}

int main(){
	
	cin >> N >> M;
	
	DFS(0);
	
	return 0;	
}
