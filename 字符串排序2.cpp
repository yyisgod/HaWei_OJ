#include<iostream>
#include<string>
#include<map>
using namespace std;

void strsort(string& str)
{
map<size_t, char> m;
string str2;	
for (size_t i = 0; i < str.size();++i)
{
if (isalpha(str[i]))
{
char temp = str[i];
str2.push_back(str[i]);
int j = str2.size() - 2;
while (j>=0&&toupper(temp)<toupper(str2[j]))
{
str2[j + 1] = str2[j];
--j;
}
str2[j + 1] = temp;	
}
else
{
m[i] = str[i];
}
}
map<size_t, char>::iterator cit = m.begin();
for (; cit != m.end();++cit)
{
str2.insert(cit->first,1, cit->second);
}
str = str2;
}

int main() {
	string str;
	getline(cin,str);
	strsort(str);
	cout << str;
	return 1;
}
