#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	char ch;
	getline(cin,str);
	cin >> ch;
	int len = str.length();
	int count = 0;
	for(int i = 0; i < len; i++) {
		if(str[i] == ch)
			count++;
		else {
			if(ch >= 'a' && ch <= 'z')
				ch = ch - 'a' + 'A';
			if(str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
			if(str[i] == ch)
				count++;
		}
	}
	cout << count;
	return 0;
}
