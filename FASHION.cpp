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
    int test, n, sum;

    cin >> test;

    while( test-- )
    {
        cin >> n;
        vector <int> v(n), v1(n);
        sum = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> v[i];
        }
        for( int j = 0; j < n; j++ )
        {
            cin >> v1[j];
        }

        sort( v.begin(), v.end() );
        sort( v1.begin(), v1.end() );

        for( int i = 0; i < n; i++ )
        {
            sum += v[i] * v1[i];
        }

        cout << sum << endl;
    }
    return 0;
}
