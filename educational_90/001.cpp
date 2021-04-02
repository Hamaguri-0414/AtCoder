#include <bits/stdc++.h>

using namespace std;

bool is_solve(vector<int> A, int N, int L, int K, int ans) {
    int split_value = ans;
    int can_split = K;

    for (int i = 0; i < N; ++i) {
        if (A[i] >= split_value) {
            split_value += ans + A[i] - split_value;
            can_split--;
        }

        if (i == N - 1 && can_split > 0) {
            break;
        }

        if (can_split == 0) {
            if (L - A[i] >= ans) {
                return true;
            } else {
                break;
            }
        }
    }

    return false;
}

int main() {
    int N, L;
    cin >> N >> L;

    int K;
    cin >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }


    int ng = -1, ok = L + 1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        (is_solve(A, N, L, K, mid) ? ng : ok) = mid;
    }

    cout << ok - 1 << endl;

    return 0;
}