
/************************************************
#
#      Filename: modular_exponentiation.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 17:08:30
# Last Modified: 2020-04-12 18:17:17
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

std::deque<int> int_to_bin(long long n, int b)
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
    std::cout << "please enter b n m:\n";
    long long b;
    long long m; 
    long long n;
    std::cin >> b >> n >> m; 

    auto n_bin = int_to_bin(n, 2);

    auto result = func(b, n_bin, m); 

    std::cout << result << "\n";
    return 0;
}
