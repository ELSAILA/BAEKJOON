#include <iostream>
#include <stack>
#include <string>

using namespace std;

string blank;

bool check(string blank){

	stack<char> l;
	int cnt=0;
		
	for(int i=0;i<blank.length();++i){
		
		char tmp = blank[i];
		
		if(tmp == '(')
			l.push(tmp);
		else{
			
			if(!l.empty()){
				l.pop();
			}
			else
				cnt++;	
		}
	}
		
	if( l.empty() && cnt==0 )
		return true;
	else
		return false;
	
}

int main(){
	
	int T;
	cin >> T;
	
	for(int i=0;i<T;++i){
	
		cin >> blank;
		
		if(check(blank))	
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	
	}
	
	return 0;	
}

/*

6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(

*/