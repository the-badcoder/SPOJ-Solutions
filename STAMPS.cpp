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
    LL int test, stamps, friends, sum, total, digit;
    int loop = 0;
    cin >> test;

    while( test-- )
    {
        cin >> stamps >> friends;
        vector < LL > v(friends);

        for( int i = 0; i < friends; i++ )
        {
            cin >> v[i];
        }
        sort( v.begin(), v.end(), greater<LL>() );

        sum = digit = 0;
        for( int i = 0; i < friends; i++ )
        {
            sum += v[i];
            digit++;
            if( sum >= stamps)
                break;
        }

        if( sum >= stamps )
        {
            printf("Scenario #%d:\n", ++loop);
            printf("%lld\n", digit);
        }
        else
        {
            printf("Scenario #%d:\n", ++loop);
            printf("impossible\n");
        }
    }
    return 0;
}
