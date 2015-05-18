#include<iostream>
#include<string>
using namespace std;

string disorder(const string& str);

int main() {
	string str;
	getline(cin,str);
	string str1;
	int len = str.length();

	for(int i = 0; i < len; i++) {
		if(!(tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z')) {
			str1.push_back(str[i]);
			continue;
		}

		int start = i;
		char ch = tolower(str[++i]);
		while(ch >= 'a' && ch <= 'z' && i < len)
			ch = tolower(str[++i]);
		int en = --i;
		str1 += disorder(str.substr(start,en - start + 1));

	}
	cout<< str1;
}

string disorder(const string& str){
	int len = str.length();
	string str1;
	for(int i = len - 1; i >= 0; i--) {
		str1.push_back(str[i]);
	}
	return str1;
}
