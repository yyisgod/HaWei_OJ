#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	int n;
	cin >> str >> n;
	int len = str.length();
	int label = 0;
	int maxRatio = 0;
	if( n > len)
		return 0;
	for(int i = 0; i < len - n; i++) {
		int ratio = 0;
		for(int j = i; j < i+n; j++){
			if(str[j] == 'G' || str[j] == 'C'){
				ratio++;
			}
		}
		if(ratio > maxRatio) {
			maxRatio = ratio;
			label = i;
		}
	}
	cout << str.substr(label,n);
	return 0;
}
