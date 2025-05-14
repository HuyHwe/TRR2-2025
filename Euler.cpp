//#include<iostream>
//#include<algorithm>
//#include<vector>
#include<bits/stdc++.h>
using namespace std;
int a[100][100], n;
stack<int> st;
vector<int> ce;

bool lienThong() {
	stack<int> dinh;
	int vs[100];
	memset(vs, 0, sizeof(vs));
	dinh.push(1);
	while (!dinh.empty()) {
		int v = dinh.top();
		vs[v] = 1;
		dinh.pop();
		for (int i = 1; i <= n; i++) {
			if (a[v][i] && vs[i] == 0) {
				dinh.push(v);
				dinh.push(i);
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0) return false;
	}
	return true;
}

void eulerCycleVoHuong(int start) {
	st.push(start);
	while (!st.empty()) {
		int u = st.top();
		bool check = false;
		for (int i = 1; i <= n; i++) {
			if (a[u][i]) {
				check = true;
				st.push(i);
				a[u][i] = 0; a[i][u] = 0;
				break;
			}
		}
		if (!check) {
			st.pop();
			ce.push_back(u);
		}
	}
}


void eulerCycleCoHuong(int start) {
	st.push(start);
	while (!st.empty()) {
		int u = st.top();
		bool check = false;
		for (int i = 1; i <= n; i++) {
			if (a[u][i]) {
				check = true;
				st.push(i);
				a[u][i] = 0;
				break;
			}
		}
		if (!check) {
			st.pop();
			ce.push_back(u);
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
	
	int start;
	cout << "Bat dau tu dinh: ";
	cin >> start;
	
	// uncomment de test thuat toan
	
	eulerCycleCoHuong(start);
//	eulerCycleVoHuong(start);
	for (int i = ce.size()-1; i >= 0; i--) {
		cout << ce[i] << " ";
	}
	
	
	
	
}

/**
Test:

vo huong:
(0, 2) (0, 5) (1, 3) (1, 4) (1, 5) (1, 6) (2, 3) (2, 5) (2, 6) (3, 4) (3, 6) (5, 6)

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
