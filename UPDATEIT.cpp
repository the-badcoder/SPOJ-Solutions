#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define res 100005

ll BIT[res], a[res];
int n;

void update( int x, ll val )
{
    ll sum = 0;
    for( ; x <= n; x += x&-x )
    {
        BIT[x] += val;
    }
}

void range_update( int i, int j, ll v )
{
    update( i, v );
    update( j + 1, -v );
}

ll query( int x )
{
    ll sum = 0;
    for( ; x > 0; x -= x&-x )
    {
        sum += BIT[x];
    }
    return sum;
}

int main()
{
    int test, m, loop = 0;

    scanf("%d", &test );

    while( test-- )
    {
        scanf("%lld %lld", &n, &m );
        memset( BIT, 0, sizeof BIT );
        memset( a, 0, sizeof a );

        for( int j = 1; j <= m; j++ )
        {
            int x, y;
            ll v;
            scanf("%d %d %lld", &x, &y, &v );
            range_update( x + 1, y + 1, v );
        }

        int q;
        scanf("%d", &q );

        while( q-- )
        {
            ll x;
            scanf("%lld", &x );
            x++;
            printf("%lld\n", query( x ) );
        }
    }
    return 0;
}
