#include <iostream>

using namespace std;

int cal[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
string s[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

void check(int month, int date){

		int d = 0;
		for(int i=1;i<month;++i){
			d+=cal[i];
		}
		
		d+=date;

		int ans = d%7;
		
		cout << s[ans] << endl;				

}

int main(){
	
	int x=0, y=0;	
	cin >> x >> y;
	check(x, y);	
	
	return 0;	
}
