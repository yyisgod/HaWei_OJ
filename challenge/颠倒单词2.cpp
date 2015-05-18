#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

string disorder(const string& str);

int main() {
	string str;
	getline(cin,str);
	string str1;
	int len = str.length();

	for(int i = 0; i < len; i++) {
		if(!(tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z')) {
			if(str[i] == '-' && str[i+1] != '-') {
				str1.push_back(str[i]);
				continue;
			}
			char ch = str[++i];
			while(!(ch >= 'a' && ch <= 'z') && i < len)
				ch = str[++i];
			--i;
			str1.push_back(' ');
			continue;
		}else {
			str1.push_back(str[i]);
		}

	}
	//cout<< str1;
	stringstream sstr;
	//str1 += " a";
	sstr << str1;
	//cout << str1;
	vector<string> cstr;
	while(sstr >> str)
		cstr.push_back(str);
	
	vector<string>::iterator it = cstr.end()-1;
	for(;it > cstr.begin();it--)
		cout << *it << ' ';
	cout << *(it);
	
}


