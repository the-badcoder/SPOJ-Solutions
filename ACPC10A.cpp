/*
    Bismillah Hir Rahmanir Rahim

    *MAY ALLAH HELP ME*
*/
/// Author: Tareq Aziz Khan

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <string>
#define PI 2 * acos(0.0)
#define LL long long

using namespace std;



int main()
{
    int a, b, c, sum ,total, value;

    while( cin >> a >> b >> c ){
        if( a == 0 && b == 0 && c == 0 ){
            break;
        }
        sum = b - a;
        total = b / a;
        if( c - b == sum ){
            printf("AP %d\n", c + sum);
        }
        else if( c / b == total ){
            printf("GP %d\n", c * total);
        }
    }
    return 0;
}
