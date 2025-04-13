#include<iostream>
#include<algorithm>
#include<vector>

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
	cout << "Start: ";
	cin >> start;
	e[start] = 0;
	cout << "Goal: ";
	cin >> goal;
	DFS(start);
	if (vs[goal]) {
		int temp = goal;
		while (true) {
			cout << temp;
			temp = e[temp];
			if (temp == 0) break;
			else cout << " <- ";
		}
	}
}

/**
Test:
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
