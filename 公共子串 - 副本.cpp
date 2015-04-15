#include <iostream>
using namespace std;

const int maxlen = 20;

void changeToLower(char *pInputStr, int &nLen)
{
	int i;
	for(i = 0; pInputStr[i] != '\0'; i++)
	{
		if(pInputStr[i] >= 'A' && pInputStr[i] <= 'Z')
			pInputStr[i] += 32;
	}
	nLen = i;
}

int getCommonStrLength(char *pFirstStr, char *pSecondStr)
{
	
	int nMaxCount;
	int nTempCount;
	int nFirstStrLen;
	int nSecondStrLen;
	int i,j,k;
	
	nMaxCount = 0;
	nTempCount = 0;
	
	changeToLower(pFirstStr, nFirstStrLen);
	changeToLower(pSecondStr, nSecondStrLen);
	
	char *pShortStrTemp = nFirstStrLen < nSecondStrLen ? pFirstStr : pSecondStr;
	char *pLongStrTemp = nFirstStrLen < nSecondStrLen ? pSecondStr : pFirstStr;
	int nShortStrLen = nFirstStrLen < nSecondStrLen ? nFirstStrLen : nSecondStrLen;
	int nLongStrLen = nFirstStrLen < nSecondStrLen ? nSecondStrLen : nFirstStrLen;

	for(i = 0; i < nShortStrLen; i++)
	{
		for(j = 0; j< nLongStrLen; j++)
		{
			nTempCount = 0;
			if(pShortStrTemp[i] == pLongStrTemp[j])
			{
				nTempCount = 1;
				for(k = 1; k < nShortStrLen - i; k++)
				{
					if(pShortStrTemp[i+k] == pLongStrTemp[j+k])
						nTempCount++;
					else
						break;
				}
				j+=(k-1);
			}
			
			if(nTempCount > nMaxCount)
				nMaxCount = nTempCount;
		}
	}
	return nMaxCount;
}

int main()
{
	char firstStr[maxlen];
	char secondStr[maxlen];
	cin>>firstStr>>secondStr;
	cout<<getCommonStrLength(firstStr, secondStr);
	return 0;
}

