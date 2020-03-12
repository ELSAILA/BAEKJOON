#include<iostream>
#include<vector>

using namespace std;

vector<int> num;

void check(){

	int cnt = 0;
			
	for(int i=0;i<num.size();++i){
		
		int chk = num[i]*2;
		
		for(int j=0;j<num.size();++j){
		 	
		 	if(chk == num[j])
		 		cnt++;
		 	
		}
	}

	cout << cnt << endl;
	
}	


int main(){
	
	while(1){
		int tmp;
		
		cin >> tmp;
		
		if(tmp == -1)
			break;			
		
		if(tmp == 0){
			check();
			num.clear();			
		}
		else{
			num.push_back(tmp);
		}
		
	}
			
	
	return 0;	
}

/*

1 4 3 2 9 7 18 22 0
2 4 8 10 0
7 5 11 13 1 3 0
-1

3
2
0


1 4 3 2 9 7 18 22

3

*/