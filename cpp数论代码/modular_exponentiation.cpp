
/************************************************
#
#      Filename: modular_exponentiation.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 17:08:30
# Last Modified: 2020-04-12 17:22:28
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <deque>
//b的n次方模m
//n为n次方的二进制数
long long func(const long long& b, const std::deque<int>& n, const long long& m)
{
    long long x = 1;
    long long power = b % m;
    for(auto i = n.rbegin(); i != n.rend(); ++i)
    {
        if(*i == 1)
        {
            x = (x * power) % m;
        }
        power = (power * power) % m;
    }
    return x;
}

int main(int argc, char *argv[])
{
    long long b = 5;
    std::deque<int> n{1, 0, 1, 0, 0, 0, 0, 1, 0, 0};
    long long m = 645;
    auto result = func(b, n, m); 

    std::cout << result << "\n";
    return 0;
}
