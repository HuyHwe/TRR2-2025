#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a[100][100], vs[100], n, start;

void DFS(int u) {
	vs[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0 && a[u][i] == 1) {
			cout << i << "(" << u << ") ";
			DFS(i);
		}
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
	cout << "Thuc hien thuat toan DFS tu dinh: ";
	cin >> start;
	cout << start << "(0) ";
	DFS(start);
	
}

/**
Test:

5
0 1 1 1 0
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
0 1 1 1 0


13
0 1 1 1 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 0 0 0 0 0 0 0
1 1 0 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 1 1 1 0 0 0 1 0
0 1 0 0 1 0 1 0 0 0 0 1 0
0 0 0 1 1 1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 1 0
0 0 0 0 0 0 0 1 1 0 1 0 1
0 0 0 0 0 0 0 0 1 0 1 1 1
0 0 0 0 0 0 0 1 1 0 0 1 1
0 0 0 0 1 1 0 1 0 1 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0

**/
