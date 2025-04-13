#include<iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
int a[100][100], vs[100], n, start, goal, e[100], loaiTru = -1;

void DFS(int u) {
	vs[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0 && a[u][i] == 1 && i != loaiTru) {
			e[i] = u;
			DFS(i);
		}
	}
}

int demTPLT() {
  	int soTPLT = 0;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0 && i != loaiTru) {
			DFS(i);
			soTPLT++;
		}
	}
    return soTPLT;
}

int main() {
  	int soTPLT = 0;
    vector<int> dinhTru;
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
        memset(vs, 0, sizeof(vs));
        loaiTru = i;
        if (demTPLT() > soTPLT) {
        	dinhTru.push_back(i);
        }
	}
	cout << "Cac dinh tru tim duoc: ";
	for (int i = 0; i < dinhTru.size(); i++) {
		cout << dinhTru[i] << " ";
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
