#include<bits/stdc++.h>


using namespace std;
int a[100][100], vs[100], n;
stack<int> st;
void DFS(int start) {
	st.push(start);
	vs[start] = 1;
	cout << start << "(0) ";
	while (!st.empty()) {
		int u = st.top();
		bool check = true;
		for (int i = 1; i <= n; i++) {
			if (a[u][i] && vs[i] == 0) {
				vs[i] = 1;
				st.push(i);
				check = false;
				cout << i << "(" << u << ") ";
				break;
			}
		}
		if (check) st.pop();
	}
}

void DFS2(int start) {
	st.push(start);
	vs[start] = 1;
	int prev = 0;
	cout << start << "(" << prev << ") ";

	while (!st.empty()) {
		int u = st.top();
		st.pop();
		prev = u;
		for (int i = 1; i <= n; i++) {
			if (a[u][i] && vs[i] == 0) {
				cout << i << "(" << prev << ") ";
				vs[i] = 1;
				st.push(u);
				st.push(i);
				break;
			}
		}
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
    // DFS(start);
	DFS2(start);
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
