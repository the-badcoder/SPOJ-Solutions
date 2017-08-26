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
#define mx          100000000
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

int main()
{
    /// I Should Always Be Patient, No Matter My Code Works, Or Not.
    double n, sum;
    int digit;
    while( scanf("%lf", &n) == 1 && n != 0.00 ){
        sum =  digit = 0;
        for( int i = 2; i < 500; i++ ){
            sum += (1.0 / i);
            digit++;
            if( sum >= n )
                break;
        }
        printf("%d card(s)\n", digit);
    }
    return 0;
}
