#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>

using namespace std;
int n, d, m;
int a[100][100];
int V[100], T[100];
struct Edge{
  int u;
  int v;
  int w;
};
deque<Edge> eT;
void Prim(int start){
    V[start] = 0; T[start] = 1;
    d = 0;
    while (eT.size() < n - 1) {
    	int min = 9999999, u = -1, v = -1;
    	for (int i = 1; i <= n; i++) {
    		if (T[i]) {
    			for (int j = 1; j <= n; j++) {
    				if (a[i][j] < min && a[i][j] != 0 && T[j] == 0) {
    					min = a[i][j]; 
						u = i;
						v = j;
					}
				}
			}
		}
		if (v == -1 || u == -1) {
			cout << "Do thi khong lien thong";
			return;
		}
		T[v] = 1; V[v] = 0; 
		Edge e;
		e.u = u; e.v = v; e.w = a[u][v];
		eT.push_back(e);
		d += a[u][v];
	}
    
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		V[i] = 1;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int start;
	cin >> start;
	Prim(start);
	for (int i = 0; i < eT.size(); i++) {
        cout << eT[i].u << " " << eT[i].v << "\n";
    }
    cout << "Tong trong so: " << d;
}

/**
Test:
13
0   2   1   3   0   0   0   0   0   0   0   0   0
2   0   2   0   0   5   5   0   0   0   0   0   0
1   2   0   4   0   5   0   0   0   0   0   0   0
3   0   4   0   5   5   0   0   0   0   0   0   0
0   0   0   5   0   6   0   0   0   6   0   0   0
0   5   5   5   6   0   6   6   6   6   0   0   0
0   5   0   0   0   6   0   6   0   0   0   0   0
0   0   0   0   0   6   6   0   7   0   0   7   7
0   0   0   0   0   6   0   7   0   7   7   0   0
0   0   0   0   6   6   0   0   7   0   7   7   0
0   0   0   0   0   0   0   0   7   7   0   8   0
0   0   0   0   0   0   0   7   0   7   8   0   8
0   0   0   0   0   0   0   7   0   0   0   8   0

**/
