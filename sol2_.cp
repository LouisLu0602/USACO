#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        vector<string> vec_s(m), vec_o(m);
        vector<int> total_record(m);
        fill(total_record.begin(), total_record.end(), 0);
        int flag = 0;
        for (int j = 0; j < m; ++j) {
            cin >> vec_s[j] >> vec_o[j];
        }
        for (int j = 0; j < n; ++j) {
            char target = '0';
            vector<int> record; 
            if (target == '0') {
                for (int k = 0; k < m; ++k) {
                    if (total_record[k] == 1)
                        continue;
                    if (vec_s[k][j] == '0' && vec_o[k][0] == '0') {
                        record.push_back(k);
                        continue;
                    }
                    else if (vec_s[k][j] == '0' && vec_o[k][0] == '1') {
                        target = '1';
                        record.clear();
                        break;
                    }
                    else if (vec_s[k][j] != '0' && j == n - 1) {
                        if (vec_s[k][j] == vec_o[k][0]) {
                            record.push_back(k);
                            continue;
                        }
                        else {
                            target = '1';
                            record.clear();
                            break;
                        }
                    }
                }
            }
            if (target == '1') {
                for (int k = 0; k < m; ++k) {
                    if (total_record[k] == 1)
                        continue;
                    if (vec_s[k][j] == '1' && vec_o[k][0] == '1') {
                        record.push_back(k);
                        continue;
                    }
                    else if (vec_s[k][j] == '1' && vec_o[k][0] == '0') {
                        flag = 1;
                        break;
                    }
                    else if (vec_s[k][j] != '1' && j == n - 1) {
                        if (vec_s[k][j] == vec_o[k][0]) {
                            record.push_back(k);
                            continue;
                        }
                        else {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (flag == 1)
                break;
            else {
                for (int w = 0; w < record.size(); ++w)
                    total_record[record[w]] = 1;
            }
        }
        if (flag == 0) {
            cout << "OK" << endl;
        }
        else
            cout << "LIE" << endl;
    }
    return 0;
}