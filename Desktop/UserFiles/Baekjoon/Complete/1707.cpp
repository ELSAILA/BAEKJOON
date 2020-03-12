#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int K, V, E;
int cnt;
string ans;
bool vertex[20001];
vector<int> mat[20001];

enum color{
	RED, BLUE	
};

void dfs(int start, int color){
	
	vertex[start] = color;
	cnt++;
	if(cnt==V)
		return;
	
	for(int i=0;i<mat[start].size();++i){
		
		if(vertex[ mat[start][i] ] == false)
			dfs(mat[start][i], (color+1)%2);
		if(vertex[ mat[start][i] ] == color){
			ans = "NO";
			return ;	
		}
	}
	return;
}

int main(){
	
	cin >> K;
	
	for(int i=0;i<K;++i){
		ans = "YES";		
		cin >> V >> E;
		
		for(int j=0;j<20001;++j){
			vertex[j] = false;
			mat[j].clear();	
		}
		
		for(int j=0;j<E;++j){
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			
			mat[tmp1].push_back(tmp2);
			mat[tmp2].push_back(tmp1);
		}
		
		for(int j=1;j<V+1;++j){
			if(vertex[j] == false)
				dfs(j, RED);
		}
		
		cout << ans << endl;
		
	}
	
	return 0;	
}

/*

2
3 2
1 3
2 3

4 4
1 2
2 3
3 4
4 2


1
3 2
1 3
2 3

*/