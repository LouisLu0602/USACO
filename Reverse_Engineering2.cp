#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll;
const int N = 100, M = 101;
int T;
int n, m;
char s[M][N];
int y[M];

bool dfs(lll ns, lll ms) {
    if (ns == 0 || ms == 0) {
        return true;
    }
    bool ret = false;
    for (int i = 0; i < n; ++i) {
        if (ns&(lll(1)<<i)) {
            bool vis[2][2];
            lll tms[2][2];
            tms[0][0] = tms[0][1] = tms[1][0] = tms[1][1] = ms;
            memset(vis, 0, sizeof vis);
            for (int j = 0; j < m; ++j) {
                if (ms&(lll(1)<<j)) {
                    vis[y[j]][s[j][i]] = true;
                    tms[y[j]][s[j][i]] ^= (lll(1)<<j);
                }
            }
            if (!ret && vis[0][0] && !vis[1][0])
                ret |= dfs(ns^(lll(1)<<i), tms[0][0]);
            if (!ret && vis[0][1] && !vis[1][1])
                ret |= dfs(ns^(lll(1)<<i), tms[0][1]);
            if (!ret && vis[1][0] && !vis[0][0]) 
                ret |= dfs(ns^(lll(1)<<i), tms[1][0]);
            if (!ret && vis[1][1] && !vis[0][1]) 
                ret |= dfs(ns^(lll(1)<<i), tms[1][1]);
        }
    }
    return ret;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            scanf("%s%d", s[i], y+i);
            for (int j = 0; j < n; ++j) {
                s[i][j] -= '0';
            }
        }
        if (dfs((lll(1)<<n)-1, (lll(1)<<m)-1))
            cout << "OK" << endl;
        else 
            cout << "LIE" << endl;
    }
}