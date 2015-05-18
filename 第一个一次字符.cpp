#include<iostream>
#include<string>
#include<map>
using namespace std;

typedef struct {
	char ch;
	int count;
} tp;

int main() {
	map<char,int> chs;
	string str;
	getline(cin,str);
	//chs.insert(str.begin(),str.end());
	int len = str.length();
	int i = 0;
	for(i = 0; i < len; i++) {
			chs[str[i]]++;
	}
	for(i = 0; i < len; i++) {
		if(chs[str[i]] == 1){
			cout << str[i];
			return 1;
		}
	}
	cout << '.';
	return 0;
}
