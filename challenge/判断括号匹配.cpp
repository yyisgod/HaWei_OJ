/***************************************************
 * 题目：
 *		判断字符串中的括号是否匹配
 * 描述：
 *		一个字符串中包含()，[]，{}三种类型的括号，编写一个函数判断输入字符串中的括号是否配对。
 * 输入：
 *		一个字符串
 * 输出：
 *		true或false
 *******************************************************/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string str;
	stack<char> st;

	getline(cin,str);
	int len = str.length();
	for(int i = 0; i < len; i++) {
		switch(str[i]) {
			case '(':
				st.push('(');
				break;
			case '[':
				st.push('[');
				break;
			case '{':
				st.push('{');
				break;
			case ')':
				if(st.empty()) {
					cout << "false";
					return 0;
				}
				if(st.top() == '(') {
					st.pop();
				} else {
					cout << "false";
					return 0;
				}
				break;
			case ']':
				if(st.empty()) {
					cout << "false";
					return 0;
				}
				if(st.top() == '[') {
					st.pop();
				} else {
					cout << "false";
					return 0;
				}
				break;
			case '}':
				if(st.empty()) {
					cout << "false";
					return 0;
				}
				if(st.top() == '{') {
					st.pop();
				} else {
					cout << "false";
					return 0;
				}
				break;
			}
	}
	if(st.empty())
		cout << "true";
	else
		cout << "false";

	return 0;
}

