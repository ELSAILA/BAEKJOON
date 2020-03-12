#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct REG{
	int age;
	string name;
};

int N, ans;
REG reg[100000];

int compare(const void *A, const void *B){
	
 	REG *ptA = (REG*)A;
 	REG *ptB = (REG*)B;
	
	if(ptA->age < ptB->age)
		return -1;
	else if(ptA->age == ptB->age)
		return 0;
	else
		return 1;
	
}

bool cmp(const REG &a, const REG &b){
	return (a.age <b.age);
}

int main(){
	
	cin >> N;
	
	for(int i=0;i<N;++i){
		cin >> reg[i].age >> reg[i].name;
	}
	
	stable_sort(reg, reg + N, cmp);

	for(int i=0;i<N;++i){
		printf("%d %s\n", reg[i].age, reg[i].name.c_str());
	}
	
	return 0;	
}

/*

5
21 Junkyu
21 Dohyun
20 Sunyoung
21 DDD
19 AAA
*/
