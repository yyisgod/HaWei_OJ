#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	int count = 0;
	int maxCount = 0;
	int label = 0;
	int mLabel = 0;
	getline(cin,str);
	if(str.empty()){
		cout<< 0;
		return 0;
	}
	int len = str.length();
	bool isNum = 0;
	for(int i = 0; i <len; i ++) {
		if(str[i] >= '0' && str[i] <= '9'){
			if(!isNum) {
				isNum = 1;
				count++;
				label = i;
			}
			else
				count++;
		}else 
			if(isNum){
				if(maxCount < count){
					maxCount = count;
					mLabel = label;
				}
				label = 0;
				isNum = 0;
				count = 0;
			}

	}
	if(isNum){
		if(maxCount < count){
			maxCount = count;
			mLabel = label;
		}
	}
	
	string subStr;
	if(maxCount == 0){
		cout << 0;
		return 0;
	}
	subStr = str.substr(mLabel,maxCount);
	cout << subStr << ","<< maxCount;
	return 0;
}
