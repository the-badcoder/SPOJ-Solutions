/// Bismillah Hir Rahmanir Rahim

/**
    Practice like Cristiano Ronaldo
        Play Like Leo Messi..
**/

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define cubert(x)             (exp(log(x)/3))
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<int,int>	          mii;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          ii;
typedef  pair<string, int>        psi;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector< ii >             vii;

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

#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sf4ll(a,b,c,d)        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e6 + 10;
const int ret = 1e4 + 10;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/

bool mark[ res ];

int a[ ret ], tree[ ret * 4 ], lazy[ ret * 4 ];

void seive();

void build_tree( int node, int b, int e )
{
    if( b == e )
    {
        //deb( "CHECK ", mark[ a[ b ] ], a[ b ] );
        tree[ node ] = mark[ a[ b ] ] == true ? 1 : 0;
        return;
    }
    int mid = ( b + e ) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    build_tree( Left, b, mid );
    build_tree( Right, mid + 1, e );
    tree[ node ] = tree[ Left ] + tree[ Right ];
}

void pushDown( int node, int b, int e )
{
    if( lazy[ node ] != -1 )
    {
        if( mark[ lazy[ node ] ]  == true )
        {
            tree[ node ] = ( e - b + 1 ); // update it.
        }
        else
        {
            tree[ node ] = 0;
        }
        if( b != e )
        {
            lazy[ node * 2 ] = lazy[ node ];
            lazy[ node * 2 + 1 ] = lazy[ node ];
        }
        lazy[ node ] = -1; // reset.
    }
}

void update_tree( int node, int b, int e, int i, int j, int value )
{
    pushDown( node, b, e );

    if( i > e || j < b )
    {
        return;
    }
    if( b >= i && e <= j )
    {
        if( mark[  value ] == true )
        {
            tree[ node ] = ( e - b + 1 );
        }
        else
        {
            tree[ node ] = 0;
        }
        if( b != e )
        {
            lazy[ node * 2 ] = value;
            lazy[ node * 2 + 1 ] = value;
        }

        return;
    }
    int mid = ( b + e ) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    update_tree( Left, b, mid, i, j, value );
    update_tree( Right, mid + 1, e, i, j, value );

    tree[ node ] = tree[ Left ] + tree[ Right ];
}

int query( int node, int b, int e, int i, int j )
{
    pushDown( node, b, e );

    if( i > e or j < b )
    {
        return 0;
    }

    if( b >= i && e <= j )
    {
        return tree[ node ];
    }

    int mid = ( b + e ) >> 1;
    int Left = node << 1;
    int Right = Left | 1;
    return query( Left, b, mid, i, j ) + query( Right, mid + 1, e, i, j );
}

int main()
{
    seive();
    int test, n, q, sum, total, ans, loop = 0;

    sf1( test );

    while( test-- && sf2( n, q ) )
    {
        memset( lazy, -1, sizeof lazy );
        memset( a, 0, sizeof a );

        for( int i = 1; i <= n; i++ )
        {
            sf1( a[ i ] );
        }

        build_tree( 1, 1, n );

        printf("Case %d:\n", ++loop );

        while( q-- )
        {
            int type;
            sf1( type );
            if( type == 1 )
            {
                int l, r;
                sf2( l, r );
                printf("%d\n", query( 1, 1, n, l, r ) );
            }
            else
            {
                int l, r, v;
                sf3( l, r, v );
                update_tree( 1, 1, n, l, r, v );
            }
        }
    }
}

void seive()
{
    memset( mark, true, sizeof mark );

    for( int i = 4; i <= res; i += 2 )
    {
        mark[ i ] = false;
    }
    int sq = sqrt( res );

    mark[ 2 ] = true;

    for( int i = 3; i <= sq; i += 2 )
    {
        if( mark[ i ] == true )
        {
            for( int j = i * i; j <= res; j += ( 2 * i ) )
            {
                mark[ j ] = false;
            }
        }
    }
}
