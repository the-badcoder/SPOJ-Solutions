#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
const int res = 1e3 + 10;
const int sz = 17;

vector <ll> graph[res];
ll depth[res], pa[sz][res];

void dfs( int u, int parent, int ret )
{
    depth[u] = ret;
    pa[0][u] = parent;

    for( ll i = 0; i < graph[u].size(); i++ )
    {
        ll v = graph[u][i];
        if( depth[ v ] == -1 )
        {
            dfs( v, u, ret + 1 );
        }

    }
}

ll LCA( ll u, ll v )
{
    if( depth[u] < depth[v] )
    {
        swap( u, v );
    }

    for( ll i = sz - 1; i >= 0; i-- )
    {
        if( depth[u] - ( 1 << i ) >= depth[v] )
        {
            u = pa[i][u];
        }
    }

    if( u == v ) return u;

    for( ll i = sz - 1; i >= 0; --i )
    {
        if( pa[i][u] != -1 and pa[i][u] != pa[i][v] )
        {
            u = pa[i][u];
            v = pa[i][v];
        }
    }

    return pa[0][u];
}

int main()
{
    int n, q, test, loop = 0;

    scanf("%d", &test );

    while( test-- )
    {
        memset( depth, -1, sizeof depth );
        memset( pa, -1, sizeof pa );

        scanf("%d", &n );

        for( int i = 0; i < n; i++ )
        {
            ll m, x;
            scanf("%lld", &m );
            while( m-- )
            {
                scanf("%lld", &x );
                x--;
                graph[i].push_back( x );
                graph[x].push_back( i );
            }
        }

        dfs( 0, -1 , 0 );

        for( ll i = 1; i < sz - 1; i++ )
        {
            for( ll j = 0; j < n; j++ )
            {
                if( pa[i-1][j] != -1 )
                {
                    pa[i][j] = pa[ i - 1 ][ pa[i-1][j] ];
                }
            }
        }

        scanf("%d", &q );
        printf("Case %d:\n", ++loop );

        for( ll i = 0; i < q; i++ )
        {
            ll u, v;
            scanf("%lld %lld", &u, &v );
            u--, v--;

            printf("%lld\n", LCA( u, v ) + 1 );
        }

    }
    return 0;
}
