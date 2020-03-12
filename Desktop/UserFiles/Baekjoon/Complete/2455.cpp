#include <iostream>

using namespace std;

int main(){
	
	int maxi=0, num=0;
	for(int i=0;i<4;++i){
		int in, out;
		cin >> out >> in;
		
		num+=in-out;
		
		if(num>maxi)
			maxi=num;
	}
	
	cout << maxi << endl;
	
	return 0;	
}
/*

0 32
3 13
28 25
39 0

*/
