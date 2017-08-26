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
#define ll          long long int
#define SIZE        10000001
///Macro End.

using namespace std;


int main()
{
    int test, n, m;

    cin >> test;

    while( test-- ){
        cin >> n >> m;


        if( n != m && n - m != 2 ){
            printf("No Number\n");
        }
        else if( n % 2 == 1 && m % 2 == 1 ){
            printf("%d\n", (n+m)-1 );
        }
        else if( n % 2 == 0 && m % 2 == 0) {
            printf("%d\n", n + m );
        }

    }
    return 0;
}
