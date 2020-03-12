#include <iostream>

using namespace std;

int T, cycle;
string word;

int main(){
	
	cin >> T;

	while(T!=0){
		
		cin >> cycle >> word;
		
		for(int i=0;i<word.length();++i){
			for(int j=0;j<cycle;++j){
				cout << word[i];
			}		
		}
		
		cout << endl;
		T--;
	}	
	
	return 0;	
}

/*

2
3 ABC
5 /HTP

*/