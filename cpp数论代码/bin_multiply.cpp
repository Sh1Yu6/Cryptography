
/************************************************
#
#      Filename: bin_multiply.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 17:00:00
# Last Modified: 2020-04-12 17:07:06
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <deque>

std::deque<int> func(std::deque<int>&a , std::deque<int>& b)
{
    if(a.size() < b.size())
    {
        a.swap(b);
    }
    
    for(auto i = b.rbegin(); i!= b.rend(); ++i)
    {
        int j = 0;
        int x = 0;
    }
}
int main(int argc, char *argv[])
{
    
    return 0;
}
