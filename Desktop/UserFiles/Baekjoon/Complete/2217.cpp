#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, ans, cmp;


vector<int> arr;
priority_queue<int> pq;

void check(){
	
	int tmp = 0;
	for(int i=0;i<N;++i){
		tmp = max(tmp, arr[i]);		
	}
	
	cout << tmp << endl;
}

int main(){
	
	cin >> N;
	
	for(int i=0;i<N;++i){
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	
	int i=1;
	while(!pq.empty()){
		arr.push_back(pq.top()*i);
		pq.pop();
		++i;
	}
		
	check();
		
	return 0;	
}
/*

7
30 20 70 10 50 80 0

5
5 5 5 5 5

7
10 20 30 50 70 80 90

*/
