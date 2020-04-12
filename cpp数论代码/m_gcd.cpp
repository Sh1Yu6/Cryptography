
/************************************************
#
#      Filename: m_gcd.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 18:40:00
# Last Modified: 2020-04-12 21:20:09
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

void ex_gcd(int a, int b, int& x, int& y)
{
    
    x = 0;
    int x1 = 0;
    int x2 = 1;

    y = 1;
    int y1 = 1;
    int y2 = 0;
    
    int r = a % b;
    int q = a / b;
    while(r)
    {
        x = x2 - q * x1;
        y = y2 - q * y1;

        x2 = x1;
        y2 = y1;

        x1 = x;
        y1 = y;

        a = b;
        b = r;
        r = a % b;
        q = a / b;
    }

}
int main(int argc, char *argv[])
{
    std::cout << "Please enter a b (e.g. 3 5):\n";
    int a, b;
    std::cin >> a >> b;
    std::cout << "最大公约数:" << my_gcd(a, b) << "\n";
    std::cout << "最小公倍数:" << my_lcm(a, b) << "\n";
    int x, y;
    ex_gcd(a, b, x, y);
    std::cout << "x: "<<x << " y: " << y; 
    std::cout << "\n";
    return 0;
}
