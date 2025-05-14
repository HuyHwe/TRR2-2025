#include<iostream>
#include<algorithm>
#include<vector>
#include <cstring>
#include<climits>

using namespace std;
int a[100][100], vs[100], n, d[100], truoc[100];
int MAX = 999999;

void dijkstra(int start) {
  d[start] = 0;
  vs[start] = 1;
  for (int i = 1; i <= n; i++) {
    d[i] = a[start][i];
    truoc[i] = start;
  }
  while (true) {
    for (int i = 1; i <= n; i++) cout << d[i] << "|" << truoc[i] << " ";
    cout << endl;
    int u = 0, min = MAX;
    for (int i = 1; i <= n; i++) {
        if (!vs[i] && d[i] < min) {
            u = i;
            min = d[i];
        }
    }
    if (u == 0) break;
    cout << "Tham dinh: " << u << endl;
    vs[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vs[i] && d[i] > d[u] + a[u][i]) {
            d[i] = d[u] + a[u][i];
            truoc[i] = u;
        }
    }
  }
}

int main() {
    cout << "So dinh: ";
    cin >> n;
    // Khoi tao ma tran ke
    cout << "Nhap ma tran:\n";
    memset(vs, 0, sizeof(vs));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0 && i != j) a[i][j] = MAX;

        }
    }
    int start, goal;
    cout << "Bat dau: ";
    cin >> start;
    dijkstra(start);

}

/**
Test:

5
0 7 5 8 2
0 0 0 0 0
0 1 0 1 0
0 1 0 0 0
0 0 0 1 0



5
0 2 0 8 5
2 0 1 3 0
0 1 3 1 0
8 3 1 0 1
5 0 0 1 0


**/
