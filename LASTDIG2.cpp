#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll bigmod( ll b, ll p, ll m )
{
    if( p == 0 ) return 1 % m;

    if( p % 2 == 0 )
    {
        ll y = bigmod( b, p / 2, m );
        return ( y * y ) % m;
    }
    else {
        return ( b * bigmod( b, p - 1, m ) ) % m;
    }
}

int main()
{
    int test;
    ll p , m = 10, sum, b, n;
    string s;

    cin >> test;

    while( test-- ){
        cin >> s >> p;

        b = s[ s.size() - 1 ] - '0';

        sum = bigmod( b, p, m );

        cout << sum << endl;
    }

    return 0;
}

