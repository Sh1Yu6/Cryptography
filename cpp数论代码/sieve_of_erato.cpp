
/************************************************
#
#      Filename: sieve_of_erato.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-04-12 17:25:10
# Last Modified: 2020-04-12 17:43:15
#***********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

void func(int n)
{
    std::vector<char> v(2000000000);

    //筛选素数
    for(int i= 2; i <= sqrt(n); ++i)  
    {
        if(v[i] == 0)
        {
            for(int j = i * 2; j <= n; j += i)
            {
                v[j] = '1';            
            }
        }
    }

    for(int i = 2; i <= n ; ++i)
    {
        if(v[i] == 0)
            std::cout << i << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    std::cout << "Please enter a integer:\n";
    int n;
    std::cin >> n;
    func(n);
    return 0;
}
