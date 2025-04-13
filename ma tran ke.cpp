#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a[100][100];


int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cin>>a[i][j];
      }
    }
    cout << "Ma tran ban vua nhap:\n";
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }

}

/**
Test:
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
