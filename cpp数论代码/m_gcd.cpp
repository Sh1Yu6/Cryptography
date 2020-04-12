
/************************************************
#
#      Filename: m_gcd.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 18:40:00
# Last Modified: 2020-04-12 19:00:13
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>


int my_gcd(int a, int b)
{
    if(a == 0 && b ==0)
        return -1;
    if(a < b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    int r = 0;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int my_lcm(int a, int b)
{
    return (a*b)/my_gcd(a, b);
}

int main(int argc, char *argv[])
{
    std::cout << "Please enter a b (e.g. 3 5):\n";
    int a, b;
    std::cin >> a >> b;
    std::cout << "最大公约数:" << my_gcd(a, b) << "\n";
    std::cout << "最小公倍数:" << my_lcm(a, b) << "\n";
    return 0;
}
