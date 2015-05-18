#include<iostream>
#include<string>
using namespace std;

int main() {
	string str,str1;
	int count = 0;
	getline(cin,str);
	str1 = str;
	int len = str.length();
	for(int i = 0; i < len; i++) {
		if(str[i] <= '9' && str[i] >= '0') {
			int j = i;
			for(j = i; j < len; j++) {
				if(!(str[j] <= '9' && str[j] >= '0'))
					break;
			}
			str1.insert(j+count,"*");
			str1.insert(i+count,"*");
			count += 2;
			i = j;
		}
	}
	cout << str1;
	return 0;
}
