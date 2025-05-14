#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int a[100][100], vs[100], n, start, goal, e[100];

void DFS(int u) {
	vs[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0 && a[u][i] == 1) {
			e[i] = u;
			DFS(i);
		}
	}
}

int demTPLT() {
  	int soTPLT = 0;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0) {
			DFS(i);
			soTPLT++;
		}
	}
    return soTPLT;
}

struct Canh {
  int dau;
  int cuoi;
};

int main() {
  	int soTPLT = 0;
    vector<Canh> canhCau;
	cout << "So dinh: ";
	cin >> n;
	// Khoi tao ma tran ke
	cout << "Nhap ma tran:\n";
	memset(vs, 0, sizeof(vs));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	soTPLT = demTPLT();
	for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          	if (a[i][j]) {
          		memset(vs, 0, sizeof(vs));
        		a[i][j] = 0; a[j][i] = 0;
          		if (demTPLT() > soTPLT) {
                    Canh c;
                    c.dau = i; c.cuoi = j;
          			canhCau.push_back(c);
          		}
                a[i][j] = 1; a[j][i] = 1;
          	}
        }
	}
	cout << "Cac canh cau tim duoc: ";
	for (int i = 0; i < canhCau.size(); i++) {
		cout << "(" << canhCau[i].dau << ", " << canhCau[i].cuoi << ") ";
	}
}

/**
Test:

4
0 0 1 1
0 0 0 0
1 0 0 0
1 0 0 0

13
0	1	1	1	0	0	0	0	0	0	0	0	0
1	0	1	1	0	0	0	0	0	0	0	0	0
1	1	0	1	1	0	0	0	0	0	0	0	0
1	1	1	0	0	0	0	0	0	0	0	0	0
0	0	1	0	0	1	1	1	1	0	0	0	0
0	0	0	0	1	0	1	0	1	0	0	0	0
0	0	0	0	1	1	0	1	0	0	0	0	0
0	0	0	0	1	0	1	0	1	0	0	0	0
0	0	0	0	1	1	0	1	0	1	0	0	0
0	0	0	0	0	0	0	0	1	0	1	1	1
0	0	0	0	0	0	0	0	0	1	0	1	1
0	0	0	0	0	0	0	0	0	1	1	0	1
0	0	0	0	0	0	0	0	0	1	1	1	0

**/
