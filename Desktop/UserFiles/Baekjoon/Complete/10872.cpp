#include <iostream>
using namespace std;

int N;
int sum=1;

void print(){
	cout << sum << endl;	
}

void Recursion(int num, int depth){
	
	if(N==depth){
		print();
	}
	else{
		sum*=num;
		Recursion(num+1, depth+1);
	}
}

int main(){
	
	cin >> N;
	Recursion(1, 0);
	
	return 0;	
}