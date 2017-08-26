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
    LL test, n, sum;

    cin >> test;

    while( test-- ){
        cin >> n;

        sum =  (n* ( 3 * n + 1 ) / 2) % 1000007;

        printf("%lld\n", sum);
    }
    return 0;
}
