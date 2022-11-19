#include <iostream>

#include "first-unique-character-in-a-string.cpp"

int main() {
    Solution mySol;
    std::string s = "itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb";
    int res = mySol.firstUniqChar(s);
    std::cout << res << std::endl;
    return 0;
}