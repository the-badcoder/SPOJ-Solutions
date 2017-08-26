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
    LL int test, a[100005], avg, digit, sum , n;

    while( cin >> n ){
        if( n == -1 ) break;
        sum = 0;
        for( int i = 0; i < n; i++ ){
            cin >> a[i];
            sum += a[i];
        }
        //cout << sum << endl;
        if( sum % n != 0 ){
            printf("-1\n");
        }
        else {
            avg = sum / n;
             digit = 0;
        for( int i = 0; i < n; i++ ){
            if( a[i] > avg ){
                digit += (a[i] - avg);
            }
        }
        printf("%lld\n", digit);
    }
    }
    return 0;
}
