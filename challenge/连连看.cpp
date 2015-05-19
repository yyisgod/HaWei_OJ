#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct point {
	int x;
	int y;
};
struct elem {
	int x;
	int y;
	int d;
};

void FindPath(point p1,point p2,int m,int n,vector<vector<int> >& a);
bool judge(stack<elem>& s);

int main() {
	int m,n;
	char ch;
	cin >> m >> ch >> n;
	vector<vector<int> > a(m);
    for(int i=0;i<n;i++)
        a[i].resize(n);
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) {
			cin >> ch >> a[i][j];
		}
	point p1,p2;
	cin >> ch >> p1.x >> ch >> p1.y >> ch >> p2.x >> ch >> p2.y;

	FindPath(p1,p2,m,n,a);
	
}

void FindPath(point p1,point p2,int m,int n,vector<vector<int> >& a) {
	stack<elem> s1;
	elem e;
	int diradd[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0}
	};
	point p,pt;
	e.x = p1.x;
	e.y = p1.y;
	e.d = -1;
	s1.push(e);
	while(!s1.empty()) {
		e = s1.top();
		s1.pop();
		p.x = e.x;
		p.y = e.y;
		int d = e.d + 1;
		while(d < 4 ){
			pt.x = p.x + diradd[d][0];
			pt.y = p.y + diradd[d][1];
			if(pt.x >= m || pt.x < 0 || pt.y >=n || pt.y < 0) {
				d++;
				continue;
			}
			if(pt.x == p2.x && pt.y == p2.y ) {
				e.x = p.x;
				e.y = p.y;
				s1.push(e);
				e.x = pt.x;
				e.y = pt.y;
				e.d = 886;
				s1.push(e);
				if(judge(s1)) {
					cout << s1.size();
					return;
				}else {
					s1.pop();
					s1.pop();
				}
				
			}
			if(a[pt.x][pt.y] == 0) {
				a[pt.x][pt.y] = -1;
				e.x = p.x;
				e.y = p.y;
				e.d = d;
				s1.push(e);
				p.x = pt.x;
				p.y = pt.y;
				d = -1;
			}
			d++;
		}

	}
	cout << '0';

}

bool judge(stack<elem>& s) {
	int len = s.size();
	int d = -1;
	int count = 0;
	stack<elem> s2;
	s2.push(s.top());
	s.pop();
	d = s.top().d;
	for(int i = 1; i < len; i++) {
		if(d != s.top().d){
			d = s.top().d;
			count++;
		}
		s2.push(s.top());
		s.pop();
	}
	for(int i = 0; i < len; i++) {
		s.push(s2.top());
		s2.pop();
	}
	if(count < 3)
	{
		return true;
	}
	return false;

}
