/*******************
 * 题目：
 *		垃圾短信识别
 * 某人A符合以下条件之一，则认为是垃圾短信发送者：
	üA发送短信的接收者中，没有发过短信给A的人数 > L。
	üA发送的短信数 - A接收的短信数 > M。
	ü如果存在X，A发送给X的短信数-A接收到X的短信数 > N。
	本题中：
	L = 20
	M = 50
	N = 10 
* 输入：
*		查询是否垃圾短信发送者，一行，多个发送者，以空格隔开
	增加短信发送记录，多行，每行一次发送记录，2个非负整数，格式：发送者 接收者，以空格隔开
* 输出：
*		针对查询者，是垃圾短信发送者返回1，否则返回0（!!包括短信发送者无发送记录等情况!!）。样例是查询2位：90909090 20
		其中90909090是垃圾短信发送者，20不是，输出：1 0
		以一个空格隔开。
***************************/
#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

struct client {
	map<int,int> recivers; // ID,counts
	int sends;
	int revs;
};
const int L = 20;
const int M = 50;
const int N = 10;

int main() {
	string str;
	getline(cin,str); //inquire id
	int send,rev;
	map<int,client> table; // Id,Object
	while (cin >> send >> rev) {
		client* ct = &table[send];
		ct->recivers[rev]++;
		ct->sends++;
		ct = &table[rev];
		ct->revs++;
	}
	stringstream ss;
	ss << str;
	int id;
	stringstream sout;
	while (ss >> id) {
		client* ct = &table[id];
		if(ct->sends ==0 && ct->revs ==0) {
			sout << '0' << ' ';//格式需要注意
			continue;
		}
		if((ct->sends - ct->revs) > M) {
			sout << '1' << ' ';
			continue;
		}
		//计算条件1跟3
		bool b1 = false, b3 = false;
		int count1 = 0;
		map<int,int>::iterator it = ct->recivers.begin();
		for(; it != ct->recivers.end(); it++) {
			client* ct2 = &table[it->first];
			if((it->second - ct2->recivers[id]) > N) {
				b3 = true;
				break;
			}
			if(ct2->recivers[id] == 0) {
				count1++;
			}
		}
		if(count1 > L)
			b1 = true;
		if(b1 || b3) {
			sout << '1' << ' ';
			continue;
		}
		sout << '0' << ' ';
	}
	string strout;
	getline(sout,strout);
	strout[strout.length()-1] = '\0';
	cout << strout;
	return 0;

}
