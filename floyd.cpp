#include<iostream>
#include<algorithm>
#include<vector>
#include <cstring>
#include<climits>

using namespace std;
int a[100][100], d[100][100], tiep[100][100], n;
int MAX = 999999;

void floyd(){
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
            tiep[i][j] = k;
          }
        }
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
            if (a[i][j] == 0 && i != j) a[i][j] = MAX;
            d[i][j] = a[i][j];
            if (a[i][j] != MAX) tiep[i][j] = j;
            
        }
    }
    floyd();
    
    int start, end;
    cout << "Bat dau: ";
    cin >> start;
    cout << "Ket thuc: ";
    cin >> end;
    int u = start;
    cout << "Chieu dai duong di ngan nhat: " << d[start][end] << "\n";
    while (u != end) {
    	cout << u << ", ";
    	u = tiep[u][end];
	}
	cout << end;



}

/**
Test:

5
0 7 5 8 2
0 0 0 0 0
0 1 0 1 0
0 1 0 0 0
0 0 0 1 0

4
0 4 3 0
0 0 -2 0
0 0 0 2
-1 0 0 0

**/
