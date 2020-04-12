
/************************************************
#
#      Filename: base_b_expansion.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 16:11:25
# Last Modified: 2020-04-12 16:33:19
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <deque>

// 十进制整数n 转化为b进制
// b进制, n整数
std::deque<int> func(long long n, int b)
{
    if(b <= 1 || n < 0)
        return {};

    std::deque<int> v;
    while(n != 0)
    {
        v.push_front(n%b);
        n = n / b;
    }
    return v;
}

int main(int argc, char *argv[])
{

    std::cout << "Please enter a integers and bjinzhi\n";
    long long n = 0;
    int b = 0;
    std::cin >> n >> b;
    
    auto v = func(n, b);
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i ;
    }
    std::cout << "\n";
    return 0;
}
