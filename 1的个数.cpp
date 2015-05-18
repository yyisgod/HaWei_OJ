#include<iostream>
#include<bitset>
using namespace std;
int main()
{
int n;
cin >> n;
bitset<32> s(n);
cout << s.count() << endl;

}
