#include <iostream>
#include <algorithm>

using namespace std;

int park[101];
int n;

int main(){
	
	int A, B, C;
	cin >> A >> B >> C;

	for(int i=0;i<3;++i){
		
		int from, to;
		
		cin >> from >> to;
				
		for(int time=from;time<to;++time){
			park[time]+=1;
		}
		
		n = max(n, to);	
	}	
	
	int sum=0;
	for(int i=1;i<=n;++i){
		if(park[i]==1)
			sum+=A;			
		if(park[i]==2)
			sum+=(B*2);
		if(park[i]==3)
			sum+=(C*3);
	}
	
	cout << sum << endl;
	
	return 0;	
}

/*

5 3 1
1 6
3 5
2 8

*/
