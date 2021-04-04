#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<int> sum_H(H, 0);
    vector<int> sum_W(W, 0);
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            sum_H[i] += A[i][j];
            sum_W[j] += A[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << sum_H[i] + sum_W[j] - A[i][j];
            if (j != W - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}