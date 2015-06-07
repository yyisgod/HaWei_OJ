/****************************************
 *	 题目：
 *		浏览器功能
 *	说明:
 *		大多数浏览器都具备后退和前进的功能，实现查看上一个网页或者前一个网页的功能．这个功能可以通过维护两个栈并跟踪浏览历史记录来实
	现．本题中，你需要实现功能支持以下命令：
	BACK:把当前页面置于前向浏览栈的顶部，从后向浏览栈的顶部弹出页面，使之成为新的当前页面．如果后向浏览栈为空，此命令被忽略．
	FORWARD:把当前页面置于后向浏览栈的顶部．从前向浏览栈的顶部弹出页面，并使之成为当前页面．如果前向浏览栈为空，该命令忽略．
	VISIT :把当前页面置于后向浏览栈的顶部，使指定的URL成为新的当前页面．!!!!前向浏览栈置空!!!!．
	QUIT:退出浏览器
	假定浏览器的初始页面的URL为： http://www.acm.org/
	 
*	输入:
	输入是一系列命令．命令关键字包括： BACK, FORWARD, VISIT以及 QUIT.URL不含空格，且长度不超过70个字符．你可以假定实际问题中每一个栈中的元素永远不会超过100．输入的结束以QUIT命令标识．
*	输出:
	除了QUIT命令以外，针对每一条输入命令，需要打印出执行该命令后需要访问的URL,以作为输出．如果命令被忽略，输出”Ignored”．针对每一条命令的输出都应该打印在单独一行上．针对QUIT命令不需要输出
*********************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
enum Operator{
	BACK,FORWARD,VISIT,QUIT
} op; //枚举操作
void opSt(stack<string>& webL, stack<string>& webR, Operator op, string str =" ");
int main() {

	stack<string> webL;//back Stack 
	stack<string> webR;
	string input;
	
	webL.push("http://www.acm.org/");
	getline(cin,input);
	while(input != "QUIT") {
		char cop;
		cop = input[0];
		switch(cop) {
			case 'B':
				opSt(webL,webR,BACK);
				break;
			case 'F':
				opSt(webL,webR,FORWARD);
				break;
			case 'V':
				string str;
				str = input.substr(5,input.length()-5);
				opSt(webL,webR,VISIT,str);
		}
		getline(cin,input);
	}
	return 0;
	

}

void opSt(stack<string>& webL, stack<string>& webR, Operator op, string str) {
	switch(op){
		case BACK:
			if(webL.size() == 1) {
				cout << "Ignored" << endl;
			} else {
				webR.push(webL.top());
				webL.pop();
				cout << webL.top() << endl;
			}
			break;
		case FORWARD:
			if(webR.size()==0) {
				cout << "Ignored" << endl;
			} else {
				webL.push(webR.top());
				webR.pop();
				cout << webL.top() << endl;
			}
			break;
		case VISIT:
			webL.push(str);
			cout << str << endl;
			while(!webR.empty())
				webR.pop();
	}
}
