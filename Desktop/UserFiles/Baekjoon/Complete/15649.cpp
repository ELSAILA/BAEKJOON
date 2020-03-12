#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, order=1;
int visited[9];
vector<int> num;


void print(){
	
	for(int i=0;i<num.size();++i){
		
		printf("%d ", num[i]);		
	}
	printf("\n");
	
}

void Perm(int start, int depth){
	
	if(depth == M){
		print();
		return;	
	}
	
	for(int i=1;i<=N;++i){
		
		if(visited[i]==false){
			visited[i] = true;
			num.push_back(i);
			
			Perm(i+1, depth+1);
			visited[i] = false;
			num.pop_back();
		}
	}

	
}

int main(){

	cin >> N >> M;
	
	Perm(1,0);
		
	return 0;	
}
