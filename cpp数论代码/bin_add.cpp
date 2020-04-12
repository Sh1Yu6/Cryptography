
/************************************************
#
#      Filename: bin_add.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 16:28:37
# Last Modified: 2020-04-12 16:59:17
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <deque>

//计算无符号二进制加法
std::deque<int> func(const std::deque<int>& a, const std::deque<int>& b)
{
    std::deque<int> sum;
    
    int c = 0;  // 进位
    int s = 0;   // 和

    auto max_n = std::max(a.size(), b.size());

    for(int  i = max_n - 1 ; i >= 0; --i)
    {
        int d = (a[i] + b[i] + c) / 2;
        s = a[i] + b[i] + c - 2 * d;    
        c = d;
        sum.push_front(s);
    }

    return sum;

}

int main(int argc, char *argv[])
{

    std::deque<int> a{1, 0, 1, 0};
    std::deque<int> b{0, 1, 1, 1};
    
    auto sum = func(a, b);

    for(auto i = sum.begin(); i!= sum.end(); ++i)
    {
        std::cout << *i;
    }
    std::cout << "\n";
    return 0;
}

