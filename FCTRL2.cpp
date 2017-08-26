/*
    Bismillah Hir Rahmanir Rahim

    *MAY ALLAH HELP ME*
*/

///Containers Start..
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
///Container End.

/// **** So be patient. Indeed, the promise of ALLAH is truth - QURAN - 30:60 ****

///Macro Start..
#define PI          acos(-1.0)
#define LL          long long
#define pii         pair <int, int>
#define ppi         pair <pii, int>
#define ff          first
#define ss          second
#define sz(a)       int((a).size())
#define pb          push_back
#define mp          make_pair
#define nn          '\n'
#define all(c)      (c).begin(), (c).end()
#define tr(c, i)    for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define prsnt(c,x)  ((c).find(x) != (c).end())
#define cprsnt(c,x)  (find(all(c), x) != (c).end())
///Macro End.


using namespace std;

int a[1000001];

int main()
{
    /// I May Not Be Able To Solve Today's Problems, But I Will Learn, And Obiviously I Can Solve Every Problems One Day :)
    int t, a[500], n, i, j, temp, m, x, flag;

    cin >> t;

    while( t-- )
    {
        cin >> n;

        a[0] = 1;
        m = 1;
        temp = 0;

        for( i = 1; i<= n; i++ )
        {
            for( j = 0; j < m; j++ )
            {
                x = a[j] * i + temp;
                a[j] = x % 10;
                temp = x / 10;
            }

            while( temp > 0 )
            {
                a[m] = temp % 10;
                temp = temp / 10;
                m++;
            }
        }

        for( i = m - 1; i >= 0; i-- )
        {
            printf("%d", a[i] );
        }
        cout << endl;
    }
    return 0;
}

