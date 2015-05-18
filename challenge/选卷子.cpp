#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int *t = new int[n];
	int *v = new int[n];
	for(int i = 0; i < n; i++)
		cin >> t[i] >> v[i];
	int k;
	cin >> k;

	int *a = new int[k+1];
	for(int i = 0; i < k + 1; i++)
		a[i] = 0;

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= k; j++ ){
				a[j] = max(a[j],a[j-t[i]]+v[i]);
		}
	}
	cout << a[k];
}
