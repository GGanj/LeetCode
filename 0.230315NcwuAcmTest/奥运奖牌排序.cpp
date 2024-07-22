#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

#define INT_MAX 9999;

template<class T1, class T2, class T3>
void compaire(T1& rankMap, T2& result, const T3& countryIndex, int type) {
    auto mapIter = rankMap.rbegin();
    int rank = 1;
    while(mapIter != rankMap.rend()) {
        for(auto vecIter : (*mapIter).second) {
            if(countryIndex.find(vecIter) != countryIndex.end()) {

            }
            if(rank < result[vecIter].first) {
                result[vecIter].first = rank;
                result[vecIter].second = type;
            }
        }
        rank += (*mapIter).second.size();
        ++mapIter;
    }
}

int main() {
    int n = 0, m = 0;
    while(cin >> n >> m) {
        map<int, vector<int>> goldRank, allRank;
        map<float, vector<int>> gPopuRank, aPopuRank;
        unordered_set<int> countryIndex;
        map<int, std::pair<int, int>> result;

        for(int i = 0; i < n; ++i) {
            int goldMedal, allMedal, population;
            cin >> goldMedal >> allMedal >> population;
            goldRank[goldMedal].push_back(i);
            allRank[allMedal].push_back(i);
            gPopuRank[goldMedal / population].push_back(i);
            aPopuRank[allMedal / population].push_back(i);
            result[i].first = INT_MAX;
        }

        for(int i = 0; i < m; ++i) {
            int index;
            cin >> index;
            countryIndex.insert(index);
        }
    
        compaire(goldRank, result, countryIndex, 1);
        compaire(allRank, result, countryIndex, 2);
        compaire(gPopuRank, result, countryIndex, 3);
        compaire(goldRank, result, countryIndex, 4);

        for(int i = 0; i < n; ++i) {
            if(countryIndex.find(i) != countryIndex.end()) {
                cout << result[i].first << ":" << result[i].second << endl;
            }
        }

        cout << endl;
    }

    return 0;
}