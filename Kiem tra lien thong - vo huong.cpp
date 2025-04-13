#include<bits/stdc++.h>

using namespace std;
int a[100][100], vs[100], n, k;

void DFS(int u) {
	vs[u] = 1;
	k++;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0 && a[u][i] == 1) {
			DFS(i);
		}
	}
}

int main() {
	memset(vs, 0, sizeof(vs));
	cout << "So dinh: ";
	cin >> n;
	// Khoi tao ma tran ke
	cout << "Nhap ma tran:\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	k = 0;
	DFS(1);
	if (k == n) cout << "Do thi vo huong lien thong";
	else cout << "Do thi vo huong khong lien thong";
}

/**
Test:
4
0 0 1 1 
0 0 1 1 
1 1 0 0 
1 1 0 0 
=> lien thong

5
0 1 1 0 0
1 0 1 0 0
1 1 0 0 0
0 0 0 0 1
0 0 0 1 0
=> khong lien thong
**/
