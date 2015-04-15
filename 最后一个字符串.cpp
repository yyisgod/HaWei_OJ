#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	int pos = 0;
	pos = str.find_last_of(" ",str.length());
	cout<<str.length()-pos-1;
	return 0;
}
