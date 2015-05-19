#include<iostream>
#include<string>
using namespace std;

void sort(string& str,int start,int en,bool small = 0);

int main() {
	string str;
	getline(cin,str);
	int len = str.length();
	int s1,e1,s2,e2;
	if(len % 2) {
		s1 = 0;
		e1 = len / 2 - 1;
		s2 = len / 2 + 1;
		e2 = len - 1;
	} else {
		s1 = 0;
		e1 = len / 2 - 1;
		s2 = len / 2;
		e2 = len - 1;
	}
	sort(str,s1,e1);
	sort(str,s2,e2,1);
	cout << str;

}

void sort(string& str,int start,int en,bool small) {
	int len = en - start + 1;
	for (int i = 0; i < len - 1; i++) {
		for (int j = start; j < en - i; j++) {
			if(small) {
				if(str[j] < str[j+1]) {
					char temp = str[j];
					str[j] = str[j+1];
					str[j+1] = temp;
				}
			}else {
				if(str[j] > str[j+1]) {
					char temp = str[j];
					str[j] = str[j+1];
					str[j+1] = temp;
				}
			}
		}
		
	}
}
