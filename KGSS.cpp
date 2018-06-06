#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, 0, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)

template<class T1> void deb(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << space << e2 << endl;
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << space << e2 << space << e3 << endl;
}

#define ll long long
const int res = 1e5 + 10;

void reset();

int a[1000005];

struct info
{
   int firstMaxi, secondMaxi;
}tree[ res * 4 ];

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[ node ].firstMaxi = a[ b ];
        tree[ node ].secondMaxi = INT_MIN;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2;

    build( left, b, mid );
    build( right, mid + 1, e );

    tree[ node ].firstMaxi = max( tree[ left ].firstMaxi, tree[ right ].firstMaxi );
    tree[ node ].secondMaxi = min( max( tree[ left ].firstMaxi, tree[ right ].secondMaxi ), max( tree[ right ].firstMaxi, tree[ left ].secondMaxi ) );

}

info query( int node, int b, int e, int i, int j, int value )
{
    info ans;
    ans.firstMaxi = INT_MIN, ans.secondMaxi = INT_MIN;

    if( i > e or j < b )
    {
        return ans;
    }
    if( b >= i and e <= j )
    {
        return tree[ node ];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    info p1 = query( left, b, mid, i, j, value );
    info p2 = query( right, mid + 1, e, i, j, value );

    ans.firstMaxi = max( p1.firstMaxi, p2.firstMaxi );
    ans.secondMaxi = min( max( p1.firstMaxi, p2.secondMaxi ), max( p1.secondMaxi, p2.firstMaxi ) );

    return ans;
}

void update( int node, int b, int e, int i, int value )
{
    if( i > e or i < b ){
        return;
    }
    if( b >= i and e <= i ){
        tree[node].firstMaxi = value;
        tree[node].secondMaxi = INT_MIN;
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2;

    update( left, b, mid, i, value );
    update( right, mid + 1, e, i, value );

    tree[ node ].firstMaxi = max( tree[ left ].firstMaxi, tree[ right ].firstMaxi );
    tree[ node ].secondMaxi = min( max( tree[ left ].firstMaxi, tree[ right ].secondMaxi ), max( tree[ right ].firstMaxi, tree[ left ].secondMaxi ) );
}

int main()
{
    int n, q, sum, total, ans;

    sf1( n );

    for( int i = 1; i <= n; i++ )
    {
        sf1( a[ i ] );
    }

    build( 1, 1, n );

    sf1( q );

    while( q-- )
    {
       char ch;
       cin >> ch;

       if( ch == 'Q' )
       {
           int l, r;
           sf2( l, r );
           printf("%d\n", query( 1, 1, n, l, r, 0 ).firstMaxi + query( 1, 1, n, l, r, 0 ).secondMaxi );
       }
       else {
            int idx, value;
            sf2( idx, value );
            update( 1, 1, n, idx, value );
       }

    }
    return 0;
}






