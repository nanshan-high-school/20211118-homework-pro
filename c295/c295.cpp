#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int num[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }

    int max[n];
    for (int i = 0; i < n; i++) {
        max[i] = num[i][0];
        for (int j = 0; j < m; j++) {
            if (num[i][j] > max[i]) {
                max[i] = num[i][j];
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max[i];
    }

    cout << sum << endl;

    bool tf = false;
    for (int i = 0; i < n; i++) {
        if (sum % max[i] == 0) {
            if (tf == false) {
                cout << max[i];
                tf = true;
            } else {
                cout << " " << max[i];
            }
        }
    }

    if (tf == false) {
        cout << "-1";
    }
}
