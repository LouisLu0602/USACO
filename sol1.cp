#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
vector<LL> vec;

int main() {
    cin >> n;
    for (LL i = 0; i < n; ++i) {
        LL val;
        cin >> val;
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    LL maxVal = -1, maxIdx = -1;
    for (LL i = 0; i < n; ++i) {
        LL fees = vec[i] * (n - i);
        if (fees > maxVal) {
            maxVal = fees;
            maxIdx = i;
        }
    }
    cout << maxVal << " " << vec[maxIdx] << endl;
    return 0;    
}