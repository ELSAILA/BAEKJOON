#include <iostream>
#include <string>

using namespace std;

string str;
int ans;

void print(){
	
	for(int i=0;i<str.length();++i){
		cout << str[i] << endl;
	}
		
}

int main(){

	getline(cin, str);	
	
	
	for(int i=0;i<str.length();++i){
		if(str[i]> 'z' || str[i] < 'A')
			str[i] = '@';
	}	
	
	
	for(int i=0;i<str.length()-1;++i){

		if(i==0 && str[i] != '@'){
			
//			cout << "first!" << endl;
//			cout << str[i] << " ";
			
			ans++;
		}
		else if( str[i] == '@' && str[i+1] != '@' ){
			ans++;
			
//			cout << str[i+1] << " ";
		}
	}	

	cout << ans << endl;
				
	return 0;	
}

/*

The Curious Case of Benjamin Button
Mazatneunde Wae Teullyeoyo	
 Teullinika Teullyeotzi 
*/
