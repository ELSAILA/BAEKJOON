#include <iostream>

using namespace std;

int main(){

	int L, A, B, C, D;
	
	cin >> L >> A >> B >> C >> D; 
	
	while(1){
		
		if(A>=0){
			A-=C;
		}
		
		if(B>=0){
			B-=D;
		}
		
		L--;
				
		if( (A<=0 && B<=0) || L == 0)
			break;
			
	}	
	
	cout << L << endl;
	
}

/*

20
25
30
6
8

40
1000
1000
1
1

40
500
1000
50
100

*/