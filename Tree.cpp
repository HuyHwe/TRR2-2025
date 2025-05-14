#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
int a[100][100], vs[100], n, start;

struct Edge{
  int u;
  int v;
};
vector<Edge> T;

void TreeDFS(int u) {
	vs[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (vs[i] == 0 && a[u][i] == 1) {
			Edge e;
			if (u < i) {
				e.u = u; e.v = i;
			} else {
				e.u = i; e.v = u;
			}
			T.push_back(e);
			TreeDFS(i);
		}
	}
}

void TreeBFS(int start) {
	queue<int> q;
	vs[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		for (int i = 1; i <= n; i++) {
			if (a[u][i] == 1 && vs[i] == 0) {
				vs[i] = 1;
				Edge e;
				if (u < i) {
					e.u = u; e.v = i;
				} else {
					e.u = i; e.v = u;
				}
				T.push_back(e);
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
    cout << "Thuc hien tim cay khung tu dinh: ";
    int start;
    cin >> start;
    // TreeDFS(start);
    TreeBFS(start);
    for (int i = 0; i < T.size(); i++) {
    	cout << T[i].u << " " << T[i].v << "\n";
	}
    
}


/*
Test
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 1 0 0
0 1 1 0 1 1
0 1 0 1 0 1
0 0 0 1 1 0



*/
