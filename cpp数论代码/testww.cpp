
/************************************************
#
#      Filename: test2.cpp
#
#        Author: Sh1Yu6
#   Description: ---
#        Create: 2020-05-10 11:37:23
# Last Modified: 2020-05-13 06:37:15
#***********************************************/
#include <NTL/vec_ZZ_p.h>
#include <NTL/vec_lzz_p.h>
#include <atomic>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include <NTL/ZZ.h>
#include <NTL/mat_ZZ.h>
#include <NTL/LLL.h>
#include <NTL/vec_ZZ.h>
#include <sstream>
#include <NTL/BasicThreadPool.h>
using namespace NTL;
using namespace std;

ZZ my_qq[10][4] = {
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
	{ZZ{1000}, ZZ{1000}, ZZ{1000}, ZZ{1000}},
};

bool thread_flag = true;
template<typename T>
void func(T& B, int matrix_length, vector<ZZ>& v, int i)
{
    ZZ a;
    int ss = 0;
    for(int outer_loop_index = 0; outer_loop_index < matrix_length; ++outer_loop_index)
    {
        for(int inner_loop_index = 0; inner_loop_index < matrix_length; ++inner_loop_index)
        {
            if(inner_loop_index == matrix_length - 1)
            {
                B[outer_loop_index][inner_loop_index] = -v[outer_loop_index] * i;
            }
            else if(outer_loop_index == matrix_length - 1)
            {
                B[outer_loop_index][inner_loop_index] = 0;
            }
            else if(outer_loop_index == inner_loop_index)
            {
                B[outer_loop_index][inner_loop_index] = 1;
            }
            else
            {
                B[outer_loop_index][inner_loop_index] = 0;
            }
        }
    }

    B[matrix_length-1][matrix_length-1] = v[matrix_length-1];

}


template<typename T>
bool print_2(T& B, int matrix_length, vector<ZZ>& v, int bol, int k, int pure, int i, bool& fff, int row, int col)
{
    
    ZZ sum{0};
    bool flag = true;
    int k_c = 0;  // 汉明重量
    int k_z = 0; // 0的数量
    int k_cc = 0;
    ZZ sq{0};
    ZZ mm{1000000};
    

    for(int outer_loop_index = 0; outer_loop_index < matrix_length ; ++outer_loop_index)
    {
        flag = true;
        if(B[outer_loop_index][matrix_length - 1] != 0)
            continue;
        sum = 0;
        sq = 0;
        k_c = 0;
        k_z = 0;
	    k_cc =0;

        // 计算某行是否等于S
        for(int inner_loop_index = 0; inner_loop_index < matrix_length - 1; ++inner_loop_index) 
        {
            sum += B[outer_loop_index][inner_loop_index] * v[inner_loop_index];

            if(B[outer_loop_index][inner_loop_index] == 1)  // 汉明重量
            {
                ++k_c;
            }
            if(B[outer_loop_index][inner_loop_index] == 0)
            {
                ++k_z;
            }
	    if(B[outer_loop_index][inner_loop_index] == -1)
		    ++k_cc;
        }

        // 如果存在子集和等于s
        if(sum == v[matrix_length-1] || sum == -v[matrix_length-1])
        {
            // 计算||x||^2 
            for(int i = 0; i < matrix_length -1; ++i)
            {
                auto m = B[outer_loop_index][i];
                sq += m*m;
            }

            // 计算模长读是不是较小的
            if(sq < mm)
            {
                mm = sq;

                if(sq < my_qq[row][col-1])
                {
                    //cout << B[outer_loop_index] << endl;
                    cout << "倍数C: " << i;
                    cout << " bol: " << bol << " pure:" << pure;
                    cout << "维度较小:score is: " << sq << "  k is : " << k_c;
                    cout << "  -k is : " << k_cc << endl;
                    my_qq[row][col-1] = sq;	
                    if(fff == true && (k_c==sq || k_cc == sq))
                    {
                        fff = false;
                        cout << "倍数C: " << i;
                        cout << " 最小值:" << sq << " === " << " k :" << k_c;
                        cout << " bol: " << bol << " pure:" << pure << endl;
                        cout << B[outer_loop_index] << endl;
                    }
		            return true;
                }
                if( k == k_c && k_c == matrix_length-1-k_z || k == k_cc && k_cc == matrix_length-1-k_z)
                {
                    if(fff == true)
                    {
                        fff = false;
                        cout << "倍数C: " << i;
                        cout << " 最小值:" << sq << " === " << " k :" << k_c;
                        cout << " bol: " << bol << " pure:" << pure << endl;
                        cout << B[outer_loop_index] << endl;
                    }
                    return true;
                }

            }
        }

    }
    return false;
}


//bool test(mat_ZZ& B, vector<ZZ>& v, int row, int k, int i, bool& fff, int row2, int col)
//{

    //bool s;
    //for(int bol = first+10; bol < last; ++bol)
    //{

        //for(int pure = first+10; pure < last; ++pure)
        //{
			//G_BKZ_XD(B, 0.99, bol, pure);
            //s = print_2(B, row, v, bol, k, pure, i, fff, row2, col);
            //if(!fff)
                //break;
        //}
        //if(!fff)
            //break;
        
    //}
    //return s;
//}

void input(int i, int arg1, int arg2, int score, int row2, int col)
{
    ZZ a;
    vector<ZZ> v;
    vec_ZZ D;
    int row = arg1;
    int k = arg2;

    string b{"data"};
    b = b + to_string(i);
    b = b + ".txt";
    ifstream in{b};
    string ns;
    int index = 0;
    for(string s; in >> s;)
    {
        auto i = s.find('=');
        ns = s.substr(i+1, 150);
        auto nn = conv<ZZ> (ns.c_str());
        v.push_back(nn);
    }
    in.close();


    mat_ZZ BB[10];

    NTL_EXEC_RANGE(10, first, last);
    for(int i = first; i < last; ++i)
    {
        BB[i].SetDims(row, row);
        func(BB[i], row, v, i);
        G_LLL_XD(BB[i]);
    }
    NTL_EXEC_RANGE_END;


    bool fff = true;
    NTL_EXEC_RANGE(10, first, last);
    for(int i = first; i < last; ++i)
    {

        for(int bol = 10; bol < 20; ++bol)
        {

            for(int pure = 0; pure < 16; ++pure)
            {
                G_BKZ_XD(BB[i], 0.99, bol, pure);
                print_2(BB[i], row, v, bol, k, pure, i, fff, row2, col);
                if(!fff)
                    break;
            }
            if(!fff)
                break;
        }
        //auto s = test(BB[i], v, row, k, i, fff, row2, col);
        if(!fff)
            break;
    }
    NTL_EXEC_RANGE_END;

}

int main(int argc, char *argv[])
{

    SetNumThreads(48);

    int row;
    int col;
    
    
    vector<int> score{200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800};
    vector<int> k{5, 7, 10, 12, 15, 17, 20, 22, 25};
    int k_j = 0;

    //cin >> k_j >> row >> col;
    for(int i = 40; i <= 200; i += 20)
    {
        for(int j = 1; j <= 4; ++j)
        {
            cout << "\n维数: " << i << " 题目: " << j << endl;
            input(i+j, i+1, k[k_j], score[k_j], k_j, j);
        }
        ++k_j;
    } 
    
    return 0;
}
