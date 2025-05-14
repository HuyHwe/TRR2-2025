//#include<iostream>
//#include<algorithm>
//#include<vector>

#include <bits/stdc++.h>
using namespace std;

int a[100][100], n, start;
int h[100], vs[100];

void xuat() {
    for (int i = 0; i < n; i++) {
        cout << h[i] << (i < n-1 ? ", " : "");
    }
    cout << ", " << start << "\n";
}


void hamilton(int k) {

    for (int i = 1; i <= n; i++) {

        if (a[h[k-1]][i] == 1) {
 
            if (k == n && i == start) {
                xuat();
            } else if (!vs[i]) {
                h[k] = i;
                vs[i] = true;
                hamilton(k + 1);
                vs[i] = false; 
            }
        }
    }
}

int main() {
    memset(vs, 0, sizeof(vs));
    cout << "So dinh: ";
    cin >> n;
    cout << "Nhap ma tran:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Dinh bat dau chu trinh Hamilton: ";
    cin >> start;

 
    h[0] = start;
    vs[start] = true;
    hamilton(1);

    return 0;
}

/**
Test:

5
0 1 0 1 0
1 0 1 0 1
0 1 0 1 1
1 0 1 0 1
0 1 1 1 0



**/
