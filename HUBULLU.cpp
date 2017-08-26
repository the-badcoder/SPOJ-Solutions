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
    long long int test, n, m;

    cin >> test;

    while( test-- ){
        scanf("%lld %lld", &n, &m);

        if( m ==  0 ) {
            printf("Airborne wins.\n");
        }
        else {
            printf("Pagfloyd wins.\n");
        }
    }
    return 0;
}
