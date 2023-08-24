#include <iostream>
#include <map>
#include <string>

int romanToInt(std::string s)
{
    std::map<char, int> romanMap{
    {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int answer = 0;
    int length = s.length();
        for(int i = 0; i < length; i++)
        {
            if(romanMap[s[i]]<romanMap[s[i+1]])           

            {
                    answer = answer + (romanMap[s[i+1]]-romanMap[s[i]]);
                    i++;
            }
            else
            {
                answer += romanMap[s[i]];
            }
        }
    return answer;
} 
bool Valid(std::string s)
{
    bool allValid = true;
    const std::string validChars = "IVXLCDM";
    for (char c : s) 
    {
    if (validChars.find(c) == std::string::npos) 
        {
        allValid = false;
        break;
        }
    }
    return allValid;
}
int main(int argc, const char** argv) {
    std::string s;
    std::cout<<"Enter Roman number: ";
    std::cin>> s;

if (Valid(s)) {
    std::cout<<"Roman number "<<s<<" is equal to "<<romanToInt(s)<<std::endl;
} else {
     std::cout<<"This is not Roman number, program ends";
    return 0;
}
    return 0;
}