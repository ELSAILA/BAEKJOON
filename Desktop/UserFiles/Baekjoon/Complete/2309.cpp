#include <iostream>
#include <algorithm>

using namespace std;

int small[9];
int sum;

void swap(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	
	for(int i=0;i<9;++i){
		cin >> small[i];	
		sum+=small[i];
	}	
	
	int fake=0;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			if(i!=j){
				fake = small[i] + small[j];
				
				if(sum-fake == 100){
										
//					cout << i <<", "<<j<<endl;
//					cout << small[i] <<", "<<small[j]<<endl;
					
					small[i] = 0;
					small[j] = 0;
					break;	
				}
			}
		}	
		
		if(sum-fake==100)
			break;
	}

	sort(small, small+9);
	
//	cout << endl;	
	for(int i=2;i<9;++i){	
		cout << small[i] << endl;
	}
				
	return 0;	
}


/*

5
1
2
3
4
15
20
25
70

13
11
9
7
17
19
21
23
10



1
2
4
5
6
7
8
9
75

20
7
23
19
10
15
25
8
13

*/
