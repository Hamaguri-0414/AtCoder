#include <bits/stdc++.h>

using namespace std;

void search(bool derection, int count, int c_h, int N, string str, vector<string>& vec) {
    bool left = true;
    bool right = false;

    if (derection == left) {
        str += "(";
    } else if (derection == right) {
        str += ")";
    }
    if (c_h == N) {
        if (count == 0) {
            vec.push_back(str);
       }
    } else if (count >= 0) {
        search(left, count + 1, c_h + 1, N, str, vec);
        search(right, count - 1, c_h + 1, N, str, vec);
    }

    return;
}

int main() {
    int N;
    cin >> N;

    int count = 1;
    vector<string> vec;
    string str = "";
    search(true, count, 1, N, str, vec);

    int vec_size = vec.size();
    for (int i = 0;i < vec_size; ++i) {
        cout << vec[i] << endl;
    }

    return 0;
}