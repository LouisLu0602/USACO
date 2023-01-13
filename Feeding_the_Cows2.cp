#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+1;
int T;
int n, k;
char s[N];
int ans[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        scanf("%s", s);
        int last[2] = {-1, -1};
        int times = 0;
        memset(ans, 0xff, sizeof ans);
        for (int i = 0; i < n; ++i) {
            int op = 0;
            if (s[i] == 'H') op = 1;
            if (last[op] < i) {
                ++times;
                if (i+k >= n) {
                    if (ans[n-1] == 1-op)
                        ans[n-2] = op;
                    else
                        ans[n-1] = op;
                }
                else
                    ans[i+k] = op;
                last[op] = i+k+k;
            }
            if (ans[i]==-1) ans[i] = 2;
        }
        cout << times << endl;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0)
                putchar('G');
            if (ans[i] == 1)
                putchar('H');
            if (ans[i] == 2)
                putchar('.');
        }
        printf("\n");
    }
}