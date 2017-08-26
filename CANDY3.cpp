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
    LL int test, n, sum;

    cin >> test;

    while( test-- ){
        scanf("%lld", &n);
        vector < LL > v(n);
        sum = 0;
        for( LL i = 0; i < n; i++ ){
            cin >> v[i];
            sum = ( sum + v[i]) % n;
        }
        if( sum )
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
