#include<iostream>
using namespace std;
int a[101][101];

// Khoi tao ma tran im (ma tran lien thuoc) co 100 hang va 10000 cot (100 dinh va 10000 canh)
int im[101][10000], m, n;

void IncMat() {
  int u, v, t;
  // Trong code cua thay, u, v la cac dinh
  m = 0;
  for (u = 1; u <= n-1; u++) {
    for (v = u + 1; v <= n; v++) {
    // Chay v tu u+1 de tranh xay ra tinh trang lap canh, vi du: them canh 1 (1, 2) xong lai them canh 2 (2, 1)
      if (a[u][v] == 1) {
        // Neu u va v ke nhau, khoi tao mot canh moi
        m++; // So canh + 1
        im[u][m] = 1; im[v][m] = 1; // Cho canh m lien thuoc voi dinh u va v trong ma tran "im[][]"
      }
    }
  }

  // in ra man hinh ma tran "im[][]"
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << im[i][j] << " ";
    }
    cout << endl;
  }


}

int main() {
  // Nhap du lieu
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  IncMat();

}



/**
Test:
10
0	0	0	1	1	0	1	1	0	0
0	0	1	1	0	1	0	0	0	0
0	1	0	1	0	1	1	1	0	0
1	1	1	0	1	1	1	1	0	0
1	0	0	1	0	1	1	1	0	0
0	1	1	1	1	0	0	1	0	0
1	0	1	1	1	0	0	1	0	0
1	0	1	1	1	1	1	0	0	0
0	0	0	0	0	0	0	0	0	1
0	0	0	0	0	0	0	0	1	0

**/
