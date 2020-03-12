#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<int> num;
int visited[10];


void chk(){

	for(int i=0;i<10;++i){
		cout << visited[i] << " ";
	}
	cout << endl;
}

int main(){
	
	cin >> str;
	
	int cnt=0;
	for(int i=0;i<str.length();++i){

		int tmp = (int)(str[i] - '0');		
		
		if(tmp == 9 || tmp == 6){
			
			if(cnt%2==0)
				visited[6]++;
			
			cnt++;
			
		}
		else{	
			visited[tmp]++;
		}
	}
	
//	chk();
	
	int ans=0;
	for(int i=0;i<10;++i){
		
		ans = max(ans, visited[i]);
	}
	
	cout << ans << endl;
		
	
	
	
	return 0;	
}

/*

111666

1 1 1
69 6

*/