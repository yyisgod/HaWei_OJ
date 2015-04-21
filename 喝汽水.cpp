#include<iostream>
using namespace std;

int main() {
	for(int i = 0 ; i < 10; i++){
		int np;
		cin >> np;
		if(!np)
			return 0;
		int nh = 0;
		while(np/3){
			nh += np / 3;
			np = np/3 + np % 3;
		}
		if(np == 2)
			nh++;
		cout << nh << endl;
	}
	return 0;
}
