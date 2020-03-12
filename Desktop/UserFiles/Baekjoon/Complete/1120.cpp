#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
	
int main(){

	string a, b;
	cin >> a >> b;
	
	int ans = 50;
		
	for(int i=0;i<=b.length()-a.length();++i){
		
		int cnt = 0;
		for(int j=0;j<a.length();++j){
			if(a[j]!=b[j+i])
				cnt++;
		}
		
		ans = min(ans, cnt);
	}
	
	cout << ans << endl;
	
		
	return 0;	
}

/*

adaabc aababbc

*/