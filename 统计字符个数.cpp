#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	set<char> charSet(str.begin(),str.end());
	cout << charSet.size();
}
