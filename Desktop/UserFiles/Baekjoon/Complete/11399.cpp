#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue< int, vector<int>, greater<int> > pq;
vector<int> arr;

int main(){
	
	cin >> N;
	
	for(int i=0;i<N;++i){
		int tmp;
		cin >> tmp;

		pq.push(tmp);		
	}
	
	while(!pq.empty()){
		int tmp2 = pq.top();	
		arr.push_back(tmp2);
		pq.pop();
	}
	
	int ans=0;
	for(int i=0;i<arr.size();++i){
		for(int j=0;j<=i;++j){
		
//			cout << i <<", "<<j<<endl;
			ans+=arr[j];
				
		}
	}
	
	cout << ans << endl;
	
	return 0;	
}

/*

5
3 1 4 3 2

0 0
1 0
1 1
2 0
2 1
2 2
3 0
3 1
3 2
3 3

*/