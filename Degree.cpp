//#include<iostream>
//#include<algorithm>
//#include<vector>
#include<bits/stdc++.h>
using namespace std;
int a[100][100], n;
stack<int> st;
vector<int> ce;

void degVoHuong() {
	for (int i = 1; i <= n; i++) {
		int deg = 0;
		for (int j = 1; j <= n; j++) {
			deg += a[i][j];
		}
		cout << "deg(" << i << ")" << " = " << deg << "\n";
	}
}

void degCoHuong() {
	for (int i = 1; i <= n; i++) {
		int degIn = 0, degOut = 0;
		for (int j = 1; j <= n; j++) {
			degOut += a[i][j];
			degIn += a[j][i];
		}
		cout << "deg+(" << i << ")" << " = " << degOut << "; deg-(" << i << ")" << " = " << degIn << "\n";
	}
}

int main() {
	cout << "So dinh: ";
	cin >> n;
	// Khoi tao ma tran ke
	cout << "Nhap ma tran:\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
//  uncomment de test
//	degVoHuong();
	degCoHuong();
	
	
	
}

/**
Test:

vo huong:
7
0	0	1	0	0	1	0
0	0	0	1	1	1	1
1	0	0	1	0	1	1
0	1	1	0	1	0	1
0	1	0	1	0	0	0
1	1	1	0	0	0	1
0	1	1	1	0	1	0


co huong:
13
0 1 0 0 0 0 0 0 0 0 0 0 0 
0 0 1 0 1 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 1 0 0 0 1 0 0 
0 0 1 0 0 1 0 0 0 0 0 0 0 
1 1 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 1 1 0 0 0 0 0 0 0 
0 0 0 1 0 0 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0 1 0 0 0 
0 0 0 0 0 0 0 1 0 0 0 1 0 
0 0 0 0 0 0 0 0 0 1 0 1 0 
0 0 0 0 0 0 0 0 1 0 0 0 1 
0 0 0 0 0 0 0 0 1 0 0 0 0



**/
