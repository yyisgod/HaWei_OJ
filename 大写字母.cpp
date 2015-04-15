#include<iostream>
#include<string>
using namespace std;

int CalcCapital(string str);

int main() {
	string str;
	getline(cin,str);
	cout << CalcCapital(str);
	return 0;
}

int CalcCapital(string str)
{
	if(str == "")
		return 0;
	int count = 0;
	int length = str.length();
	for(int i = 0; i < length; i ++) {
		if(str[i] >= 'A' && str[i] <= 'Z')
			count++;
	}
	return count;
}
