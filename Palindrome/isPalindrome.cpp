#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int x) 
{
        if(x != 0)
        {
        std::string number(std::to_string(x));
        std::string a = number;
        reverse(a.begin(), a.end());
        for(int i=0; i<(number.length()/2); i++)
        {
            if(number[i] != a[i])
            {
                return false;
            }
        }
        return true;
        }
    return true;
}
int main(int argc, const char** argv) 
{
    int x;
    std::cout<<"Enter number to check if its palindrome"<<std::endl;
    std::cout<<"Number: ";
    std::cin>>x;
    if(isPalindrome(x)==true)
    {
        std::cout<<"Your number is a Palindrome";
    }
    else
    std::cout<<"Your number is not a Palindrome";

    return 0;
}