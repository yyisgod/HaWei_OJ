#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	map<char,int> chars;

	string::iterator it = str.begin();
	for(;it != str.end();it++){
		chars[*it]++;
	}
	int minc = 21;
	map<char,int>::iterator itm = chars.begin();
	for(; itm != chars.end(); itm++) {
		if(itm->second < minc)
			minc = itm->second;
	}
	
	it = str.begin();
	for(;it != str.end(); it++){
		if(chars[*it] == minc)
			*it = 'A';
	}

	it = str.begin();
	for(;it != str.end(); it++){
		if(*it != 'A')
			cout << *it;	
	}
}
