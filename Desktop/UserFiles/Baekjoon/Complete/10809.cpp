#include <iostream>
#include <string>
#include <vector>

using namespace std;

int alpha[26];
string word;
vector<int> chk;

int main(){
	
	for(int i=0;i<26;++i){
		alpha[i] = -1;
	}
	
	cin >> word;
		
	for(int i=0;i<word.length();++i){
		
		int tmp = (int)(word[i] - 'a');
		
		if(alpha[tmp]==-1)
			alpha[tmp] = i;
	}

	for(int i=0;i<26;++i){
		cout << alpha[i] << " ";
	}
	cout << endl;
	
			
	return 0;	
}