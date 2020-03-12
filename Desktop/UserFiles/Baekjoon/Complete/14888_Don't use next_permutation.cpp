#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[12];
int maxi = -1000000000;
int mini = 1000000000;
vector<char> oper;

int main(){
	
	cin >> N;	
	
	for(int i=0;i<N;++i){
		cin >> num[i];
	}

	for(int i=0;i<4;++i){
		int tmp;
		cin >> tmp;

		while(tmp!=0){
			
			if(i==0){
				oper.push_back('+');	
			}
			else if(i==1){
				oper.push_back('-');					
			}
			else if(i==2){
				oper.push_back('*');					
			}
			else{
				oper.push_back('/');					
			}
				
			tmp--;
		}	
	}

	sort(oper.begin(), oper.end());
			
	do{
	
//		for(int i=0;i<oper.size();++i){
//			cout << oper[i] << " ";
//		}
//		cout << endl;
					
		int sum = num[0];
		for(int i=0;i<N-1;++i){
					
//			cout << sum<< " " <<oper[i] << " " << num[i+1];		
					
			if(oper[i] == '+'){
				sum = sum + num[i+1];
			}	
			else if(oper[i] == '-'){
				sum = sum - num[i+1];		
			}	
			else if(oper[i] == '*'){
				sum = sum * num[i+1];
			}
			else{
				
				if(sum<0){
					sum = -( (-sum) / num[i+1] );		
				}
				else{
					sum = sum / num[i+1];	
				}
			}
			
//			cout <<" = "<<sum<<endl; 									
		}
		
			if(sum > maxi)
				maxi = sum;
			if(sum < mini)
				mini = sum;
				
	}while( next_permutation(oper.begin(), oper.end()) );

	cout << maxi << endl << mini << endl;	
	
	return 0;	
}

/*

6
1 2 3 4 5 6
2 1 1 1

3
3 4 5
1 0 1 0

4
1 2 3 4
0 2 1 0

5
1 2 3 4 5
0 2 2 0

2
1 2
0 1 0 0

*/
