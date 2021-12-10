#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int a;
    cin >> a;
    for(int z = 0; z < a; z++){
        int b, total = 0, max = 0;
        cin >> b;
        int c[b];
        for(int i = 0; i < b; i++){
            cin >> c[i];
            total += c[i];
        }
        int cap[total / 2 + 1];
        memset(cap, 0, sizeof(cap));
        for(int i = 0; i < b; i++){
            for(int j = total / 2; j > c[i] - 1; j--){
                int d = j - c[i];
                if(cap[d] + c[i] > cap[j])
                cap[j] = cap[d] + c[i];
            }
        }
        for(int i = 0; i < total / 2 + 1; i++){
            if(cap[i] > max) max = cap[i];
        }
        int max2 = total - max;
        cout << abs(max - max2) << "\n";
    }
}
