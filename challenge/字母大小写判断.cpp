/***************************************
 * 题目：
 *		字母大小写判断
 * 描述：
 *		判断一个字符串是否是首字母大写且非首字母小写。
 * 输入:	 
 *		一个任意字符串，长度不超过128个字符
 * 输出：
 *		如果输入字符串首字符为大写字母且其他字符非大写字母，返回true
 *		其他情况（空字符串、首字符非字母、首字母为小写、首字母大写但其他字符非字母等）均返回false
 ****************************************************/
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	if(str[0] < 'A' || str[0] > 'Z' || str.length() == 1){
		cout << "false";
		return 0;
	}
	bool lower = 0;//have lower?
	bool upper = 0;//have upper?
	for(int i = 1; i < str.length(); i++) {
		if(str[i]>= 'a' && str[i] <= 'z')
			lower = 1;
		if(str[i]>= 'A' && str[i] <= 'Z')
			upper = 1;
	}
	if(lower && !upper)
		cout << "true";//妈的之前写错了ture 
	else 
		cout << "false";

	return 0;
}
