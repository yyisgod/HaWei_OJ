#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;

class Node{
	public:
		int data;
		Node* l;
		Node* r;
		Node():data(0),l(NULL),r(NULL){};
};
void FindPath(Node* pt,vector<int>& sta,int n1,int n2,int p);
int main() {
	int n;
	cin >> n;
	int num;
	char ch;
	queue<Node*> TreeQ;
	Node* Root = new Node;
	TreeQ.push(Root);
	string str;
	cin >> num;
	getline(cin,str);
	stringstream ss;
	ss << str;
	
	while(ss>>ch) {
		Node* t = TreeQ.front();
		
		t->data = num;
		Node* ld = new Node;
		Node* rd = new Node;
		t->l = ld;
		t->r = rd;
		TreeQ.pop();
		TreeQ.push(ld);
		TreeQ.push(rd);
		ss >> num;
	}
	Node* t = TreeQ.front();
		
		t->data = num;
		Node* ld = new Node;
		Node* rd = new Node;
		t->l = ld;
		t->r = rd;
		TreeQ.pop();
		TreeQ.push(ld);
		TreeQ.push(rd);
	while(!TreeQ.empty())
		TreeQ.pop();

	vector<int> sta;
	FindPath(Root,sta,0,n,0);
	
	
	
	
}
void FindPath(Node* pt,vector<int>& sta,int n1,int n2,int p) {
	n1 += pt->data;
	sta.push_back(pt->data);
	p++;
	bool isLeaf = (pt->l->data == 0 && pt->r->data ==0);
	if((n1 == n2) && isLeaf) {
		for(int i = 0; i < p -1; i ++){
			cout<< sta[i] << ',';
		}
		cout << sta[p-1] << '$';
	}
	if(pt->r && pt->r->data != 0){
		FindPath(pt->l,sta,n1,n2,p);
	}
	if(pt->l && pt->l->data != 0){
		FindPath(pt->r,sta,n1,n2,p);
	}
	sta.pop_back();
	p--;
	
}
	
