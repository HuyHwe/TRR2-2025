#include<iostream>
#include<algorithm>
#include<vector>
#include <cstring>
#include<climits>

using namespace std;
int a[100][100], vs[100], n, d[100], truoc[100];
int MAX = 999999;

void bellmanFord(int start){
    d[start] = 0;
    vs[start] = 1;
    for (int i = 1; i <= n; i++) {
        d[i] = a[start][i];
        truoc[i] = start;
        cout << d[i] << "|" << truoc[i] << " ";
    }
    cout << endl;

    int k = 1;
    bool done = true;
    while (k <= n-2) {
        done = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i] > d[j] + a[j][i]) {
                    d[i] = d[j] + a[j][i];
                    truoc[i] = j;
                    done = false;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << d[i] << "|" << truoc[i] << " ";
        }
        cout << endl;
        k++;
    }
    if (!done) cout << "Do thi co chu trinh am";
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
    bellmanFord(start);



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
