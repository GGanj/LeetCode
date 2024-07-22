#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    for(auto iter = input.begin(); iter != input.end();) {
        if((*iter) >= 'A' && (*iter) <= 'Z') {
            ++iter;
            continue;
        }
        if((*iter) >= 'a' && (*iter) <= 'z') {
            *iter = *iter - 32;
            ++iter;
            continue;
        }
        iter = input.erase(iter);
    }
    cout << input << endl;
    return 0;
}