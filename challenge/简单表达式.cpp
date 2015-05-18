#include<iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	if(x < 1)
		cout << x;
	if(x >= 1 && x < 10)
		cout << 2 * x - 1;
	if(x >= 10)
		cout << 3 * x -11;

}
