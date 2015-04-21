#include<iostream>
#include<string>
using namespace std;

string getCommonStrLength(char *pFirstStr, char *pSecondStr){
	int len1 = 0,len2 = 0;
	char* s = pFirstStr;
	char* t = pSecondStr;
	
	len1 = strlen(s);
	len2 = strlen(t);
	int **dp = new int*[len1+1];
	for (int i = 0; i < len1+1; i++)
		dp[i] = new int[len2+1];
		
	for (int i = 0; i < len1; i++){
	    s[i] = tolower(s[i]);
		dp[i][0] = 0;
	}
	dp[len1][0] = 0;
	
	for(int j = 0; j < len2; j++){
		t[j] = tolower(t[j]);
		dp[0][j] = 0;
	}
	dp[0][len2] = 0;
	int label =0;	
	for (int i = 0; i < len1; i++)
		for(int j = 0; j < len2; j++){
			if(s[i] == t[j]) {
				int count = 0;
				for(int k = 0; k < dp[i][j]; k++) 
					if(s[i-k-1] == t[j-k-1])
						count++;
					else break;
				if(count == dp[i][j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
						label = i;
					}
				else {
					dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
				
				}
			}else{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	int  result = dp[len1][len2];
	delete dp;
	string str;
	if(result == 0)
		return "";
	for(int i = (label - result + 1); i <= label; i++)
		str.push_back(pFirstStr[i]);
	return str;
}

int main() {
	string str,str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	//int pos = str.find_first_of(" ",0);
//	str1 = str.substr(0,pos);
//	str2 = str.substr(pos+1,str.length());
	cout << getCommonStrLength(const_cast<char*>(str1.c_str()), const_cast<char*>(str2.c_str()));
	return 0;

}
