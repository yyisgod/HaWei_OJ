#include<iostream>
#include<string>
using namespace std;

int main(){
	int high;
	cin >> high;
	double d_high = static_cast<double>(high);
	double total;
	total = d_high * (1.0 - 1.0/32.0) * 2 * 2 - d_high;
	double high_6 = d_high / 32.0;
	cout << total << endl;
	cout << high_6 ;
}
