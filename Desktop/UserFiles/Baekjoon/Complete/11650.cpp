#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100001

int N;

struct DOT{
	int x, y;
};

DOT dot[MAX];

bool compare(DOT &a, DOT &b){
	
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(){
	
	scanf("%d", &N);
	
	for(int i=0;i<N;++i){
		scanf("%d%d", &dot[i].x, &dot[i].y);
	}

	sort(dot, dot+N, compare);

	for(int i=0;i<N;++i){
		printf("%d %d\n", dot[i].x, dot[i].y);		
	}
		
	
	return 0;	
}

/*

5
3 4
1 1
1 -1
2 2
3 3

*/