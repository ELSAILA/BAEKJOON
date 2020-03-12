#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int mat[21][21];
bool visited[21];
vector<int> arr;
int ans = 100000000;


void print(){
		
	for(int i=0;i<arr.size();++i){
		cout << arr[i] << " ";	
	}
	cout << endl;
}

void DFS(int start, int depth){
	
	if(depth == N/2){
	
//		print();
		
		int start=0, lik=0;
		
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				
				if(i!=j && visited[i] == true && visited[j] == true){
						
					start = start+mat[i][j];
						
				}				
				else if(i!=j && visited[i] == false && visited[j] == false){
					lik = lik+mat[i][j];	
				}
								
			}		
		}	
		
		
//		cout << "start: "<<start<<", lik: "<<lik << endl; 
		
		ans = min(ans, abs(start-lik));
		
		return;
	}
	
	
	
	for(int i=start;i<N;++i){
		
		if(visited[i] == false){
		
			visited[i] = true;
			arr.push_back(i);
			DFS(i, depth+1);
			visited[i] = false;
			arr.pop_back();
							
		}
	}
	
	return;
}

int main(){
	
	scanf("%d", &N);	
	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			scanf("%d", &mat[i][j]);
		}		
	}
	
	DFS(0, 0);
	
	printf("%d\n", ans);
		
	return 0;	
}