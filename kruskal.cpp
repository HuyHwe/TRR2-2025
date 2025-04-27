#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>

using namespace std;
int n, d, m;
struct Edge{
  int u;
  int v;
  int w;
};

deque<Edge> V, T;


int cmp(Edge e1, Edge e2) {
	if (e1.w == e2.w) {
		if (e1.u == e2.u) return e1.v < e2.v;
		return e1.u < e2.u;
	}
    return e1.w < e2.w;
}

int chuTrinh() {
	int arr[100] = {0};
    for (int i = 0; i < T.size(); i++) {
        arr[T[i].u] = 1;
        arr[T[i].v] = 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += arr[i];
    }
    if (count == T.size() + 1) return 0;
    else return 1;
}

void Kruskal(){
    d = 0; T.clear();
    sort(V.begin(), V.end(), cmp);
    while (T.size() < n - 1) {
        Edge e = V.front();
        V.pop_front();
        T.push_back(e);
        if (chuTrinh()) {
            T.pop_back();
        } else {
        	d += e.w;
		}
    }
}

int main() {
	V.clear(); T.clear();
    cout << "So dinh: ";
    cin >> n;
    cout << "So canh: ";
    cin >> m;
    // Khoi tao danh sach canh
    cout << "Nhap cac canh:\n";
    for (int i = 0; i < m; i++) {
      Edge e;
      cin >> e.u >> e.v >> e.w;
      V.push_back(e);
    }
    Kruskal();
    cout << "Cay khung xay dung duoc:\n";
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].u << " " << T[i].v << "\n";
    }
    cout << "Tong trong so: " << d;

}

/**
Test:

13 27
1 2 2
1 3 1
1 4 3
2 3 2
2 6 5
2 7 5
3 4 4
3 6 5
4 5 5
4 6 5
5 6 6
5 10 6
6 7 6
6 8 6
6 9 6
6 10 6
7 8 6
8 9 7
8 12 7
8 13 7
9 10 7
9 11 7
10 11 7
10 12 7
11 12 7
11 13 8
12 13 8

13 28
1 2 2
1 3 1
1 4 3
1 7 5
1 8 5
2 3 2
2 6 5
2 7 5
3 4 4
3 6 5
4 5 5
4 6 5
5 6 6
5 10 6
6 7 6
6 8 6
6 9 6
6 10 6
7 8 6
8 9 7
8 12 7
8 13 7
9 10 7
9 11 7
10 11 7
10 12 7
11 12 8
12 13 8

**/
