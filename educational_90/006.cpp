#include <bits/stdc++.h>

using namespace std;

int nex[100005][26];

int main() {
    string S;
    int K;

    cin >> S;
    cin >> K;

    for (int i = 0; i < 26; i++) nex[S.size()][i] = S.size();
    for (int i = (int)S.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((int)(S[i] - 'a') == j) {
                nex[i][j] = i;
            }
            else {
                nex[i][j] = nex[i + 1][j];
            }
        }
    }

    string ans = "";
    int current_pos = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < 26; j++) {
            int next_pos = nex[current_pos][j];
            int max_possible_length = (int)(S.size() - (next_pos + 1)) + i;
            if (max_possible_length >= K) {
                ans += (char)('a' + j);
                current_pos = next_pos + 1;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}