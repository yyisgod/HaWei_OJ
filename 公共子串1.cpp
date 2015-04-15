#include<iostream>
#include<string>
using namespace std;

const int maxlen = 20;

int getCommonStrLength(char *pFirstStr, char *pSecondStr){
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
		
	for (int i = 0; i < len1; i++)
		for(int j = 0; j < len2; j++){
			if(s[i] == t[j]) {
				int count = 0;
				for(int k = 0; k < dp[i][j]; k++) 
					if(s[i-k-1] == t[j-k-1])
						count++;
					else break;
				if(count == dp[i][j])
					dp[i+1][j+1] = dp[i][j] + 1;
				else
					dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}else{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	int  result = dp[len1][len2];
	delete dp;
	return result;
}

int main() {
	char firstStr[maxlen];
	char secondStr[maxlen];
	cin>>firstStr>>secondStr;
	cout<<getCommonStrLength(firstStr, secondStr);
	return 0;

}
