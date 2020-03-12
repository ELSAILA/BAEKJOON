#include <iostream>
#include <string>
#include <vector>

using namespace std;

string word;
int alpha[26];
char ans;

int main(){
	
	cin >> word;	
	
	for(int i=0;i<word.length();++i){
		
		int tmp;
		
		if(word[i]>'Z'){
			tmp = (int)(word[i] - 'a');
		}
		else{
			tmp = (int)(word[i] - 'A');			
		}
		
		alpha[tmp]++;
		
	}
	
	int maxi = -1;
	int index = 0;
	bool flag = false;
	
	for(int i=0;i<26;++i){
		if(maxi < alpha[i]){
			maxi = alpha[i];
			index = i;
			flag = false;
		}
		else if(alpha[i] != 0 && alpha[i] == maxi){
			flag = true;
		}
		
		
	}
	
	if(!flag){
		ans = (char)('A'+index);
	}
	else{
		ans = '?';	
	}
	
	cout << ans << endl;
	
	return 0;	
}


/*

abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV


*/
