#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t , m;
    vector<pair<int, int>> material;
    cin >> t >> m;
    for(int i = 0; i < m; ++i) {
        int size, value;
        cin >> size >> value;
        material.push_back({size, value});
    }

    vector<vector<int>> maxValue(m, vector<int>(t + 1));

    for(int i = 0; i <m; ++i) {
        for(int j = 0; j <=t; ++j) {
            int notSel = i == 0 ? 0 : maxValue[i-1][j];
            if(material[i].first > j) {
                maxValue[i][j] = notSel;
            } else {
                int sel = ((i == 0 || j < material[i].first ) ? 0 : maxValue[i-1][j-material[i].first]) + material[i].second;
                maxValue[i][j] = notSel > sel ? notSel : sel;
            }
        }
    }
    cout << maxValue[m - 1][t] << endl;
    return 0;
}