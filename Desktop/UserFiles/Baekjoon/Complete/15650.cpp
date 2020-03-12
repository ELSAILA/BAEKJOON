#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];
vector<int> v;

void print(){

	for(int i=0;i<v.size();++i){
		cout << v[i] << " ";
	}
	cout << endl;
			
}

void Perm(int start, int depth){
	if(depth == M){
		print();
		return;	
	}
	
	for(int i=start;i<=N;++i){
		
		if(visited[i] == false){
			visited[i] = true;
			
			v.push_back(i);
			Perm(i, depth+1);			
			v.pop_back();
			
			visited[i] = false;	
		}
		
	}
}

int main(){
	
	cin >> N >> M;
		
	Perm(1, 0);	
		
	return 0;	
}
