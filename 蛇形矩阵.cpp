#include<iostream>
using namespace std;

//void GetResult(int Num, char * pResult);

int main() {
	int n;
	cin >> n;
	int count = 1;
	int** a = new int*[n];
	for(int k = 0; k < n; k++)
		a[k] = new int[n];
	for(int k = 0; k < n; k++)
	{	
		for(int i = k; i >=0; i--)
		{
			int j = k - i;
			a[i][j] = count++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
			cout << a[i][j]<< " ";
		cout << a[i][n-i-1];	
		cout << endl;
	}
	return 0;		
}
