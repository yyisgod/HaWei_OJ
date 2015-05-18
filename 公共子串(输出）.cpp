#include <iostream>
#include <string>

using namespace std;

void extractCommStr(string&,string&);

int main()
{
	string str1,str2;
	string strOut;
	getline(cin,str1);
	getline(cin,str2);
	extractCommStr(str1,str2);
	system("pause");
	return 0;
}

void extractCommStr(string& str1,string& str2)
{
	string tempStr;
	string strOut;
	int len1=str1.size();
	int len2=str2.size();
	int maxLen=0;

	//??????????????,??
	if(len1<len2)
	{
		tempStr=str1;
		str1=str2;
		str2=tempStr;
		len1=len1^len2;
		len2=len1^len2;
		len1=len1^len2;
	}

	//???????????,????????????????
	for(int i=0;i<=len2-1;i++)
	{
		for(int j=1;j<=len2-i;j++)
		{
			for(int k=0;k<=len1-j;k++)
			{
				if(str2.substr(i,j)==str1.substr(k,j))
				{
					if(j>maxLen)
					{
						maxLen=j;
						strOut=str1.substr(k,j);
					}
				}
			}
		}
	}
	cout<<strOut<<endl;
}
