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
    int test, i, j, n, m, maxx, minn;

    cin >> test;

    while( test-- )
    {
        cin >> n >> m;
        vector <int> v(n), v1(m);
        maxx = minn = 0;
        for( i = 0; i < n; i++ )
        {
            cin >> v[i];
            if( v[i] > maxx )
                maxx = v[i];
        }
        for( j = 0; j < m; j++ )
        {
            cin >> v1[j];
            if( v1[j] > minn )
                minn = v1[j];
        }
        if( maxx >= minn )
            cout << "Godzilla" << endl;
        else
            cout << "MechaGodzilla" << endl;
    }
    return 0;
}
