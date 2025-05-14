#include<bits/stdc++.h>

using namespace std;
int a[100][100], vs[100], n;
queue<int> q;
void BFS(int start) {
	cout << start << "(0) ";
	vs[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		for (int i = 1; i <= n; i++) {
			if (a[u][i] == 1 && vs[i] == 0) {
				vs[i] = 1;
				cout << i << "(" << u << ") ";
				q.push(i);
			}
		}
		q.pop();
	}
}

int main() {
    cout << "So dinh: ";
    cin >> n;
    // Khoi tao ma tran ke
    cout << "Nhap ma tran:\n";
    memset(vs, 0, 100);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Thuc hien thuat toan BFS tu dinh: ";
    int start;
    cin >> start;
    BFS(start);
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
