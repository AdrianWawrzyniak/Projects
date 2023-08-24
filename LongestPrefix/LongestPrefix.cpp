#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::string longestCommonPrefix(std::vector<std::string>& strs) 
{   
    if (strs.empty()) {
        return "";
    }

    sort(strs.begin(), strs.end(), [](const std::string &a, const std::string &b)
    {
        return a.length() < b.length();
    });

    int commonLength = 0;
    for (int i = 0; i < strs[0].length(); i++) {
        char currentChar = strs[0][i];

        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != currentChar) {
                return strs[0].substr(0, commonLength);
            }
        }

        commonLength++;
    }
    
    return strs[0].substr(0, commonLength);
}
int main(int argc, const char** argv) 
{
    std::vector<std::string> strs;
    strs = {"floor", "flower", "flawless"};
    std::cout<<longestCommonPrefix(strs);
    return 0;
}