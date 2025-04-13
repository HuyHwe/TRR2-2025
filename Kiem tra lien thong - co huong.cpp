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
	
	bool checkLienThongManh = true;
	for (int i = 1; i <= n; i++) {
		memset(vs, 0, sizeof(vs));
		k = 0;
		DFS(i);
		if (k < n) {
			checkLienThongManh = false;
			break;
		}
	}
	if (checkLienThongManh) cout << "Do thi co huong lien thong manh"; 
	else {
		// Check lien thong yeu
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 1) a[j][i] = 1; // Chuyen thanh do thi vo huong nen
			}
		}
		k = 0; memset(vs, 0, sizeof(vs));
		DFS(1);
		if (k == n) cout << "Do thi co huong lien thong yeu";
		else cout << "Do thi co huong khong lien thong";
	}
	

}

/**
Test:
4
0 0 1 0 
0 0 0 1 
0 1 0 0 
1 0 0 0 

5
0 1 1 0 0
0 0 0 0 1
0 0 0 0 1
1 0 0 0 0 
0 0 0 1 0

=> lien thong manh

4
0 0 1 0 
0 0 0 1 
0 1 0 0
0 0 1 0 
=> lien thong yeu

5
0 1 1 0 0
1 0 1 0 0
1 1 0 0 0
0 0 0 0 1
0 0 0 1 0
=> khong lien thong
**/
