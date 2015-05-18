#include<iostream>
#include<string>
using namespace std;

int main() {
	string str,str1,str2;
	getline(cin,str);
	int len = str.length();
	for(int i = 0; i < len; i++){
		str1[i] = tolower(str[i]);
	}

	for(int i = 0; i < len; i++) {
		int  minIndex = 0;
		while(!(str1[minIndex] >= 'a' && str1[minIndex] <= 'z'))
			minIndex++;
		for(int j = minIndex + 1; j < len; j++) {
			if (!(str1[j] >= 'a' && str1[j] <= 'z'))
				continue;
			if(str1[j] < str1[minIndex]) {
				minIndex = j;
			}
		}
		str2.push_back(str[minIndex]);
		str1[minIndex] = ' ';
	}
	for(int i = 0; i < len; i++){
		str1[i] = tolower(str[i]);
	}
	int count = 0;
	for(int i = 0; i < len; i++) {
	
		if (!(str1[i] >= 'a' && str1[i] <= 'z')){	
			cout<< str[i];
		}
		else
			cout<<str2[count++];
	}
	return 0;
}
