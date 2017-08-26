/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

const int dr[] = { -1, 1, 0, 0 }; /// 4 side moves.
const int dc[] = { 0, 0, -1, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; /// 8 side moves.
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int kr[] = { 1, 1, -1, -1, 2, 2, -2, -2 }; /// Knight Moves.
const int kc[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<string, string>      mss;
typedef  map<int,int>	          mii;
typedef  map<ll, ll>              mll;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          ii;
typedef  pair<string, int>        psi;
typedef  pair<string, string>     pss;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector<char>	          vc;
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

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.

const int res = 1e5 + 10;
const ll mod = 1e9 + 7;
int a[res];
struct info
{
    int sum, prefix, suffix, maxi;
} tree[res * 4];

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[node].sum = a[b];
        tree[node].prefix = a[b];
        tree[node].suffix = a[b];
        tree[node].maxi = a[b];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2;

    build( left, b, mid );
    build( right, mid + 1, e );

    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].prefix = max( tree[left].prefix, tree[left].sum + tree[right].prefix );
    tree[node].suffix = max( tree[right].suffix, tree[right].sum + tree[left].suffix );
    tree[node].maxi = max( tree[node].prefix, max( tree[node].suffix, max( tree[left].maxi, max( tree[right].maxi, tree[left].suffix + tree[right].prefix ) ) ) );
}

info query( int node, int b, int e, int i, int j )
{
    info result;
    result.sum = result.prefix = result.suffix = result.maxi = INT_MIN;

    if( i > e or j < b )
    {
        return result;
    }
    if( b >= i and e <= j )
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    if( i > mid )
    {
        return query( right, mid + 1, e, i, j );
    }
    if( j <= mid )
    {
        return query( left, b, mid, i, j );
    }

    info p1 = query( left, b, mid, i, j );
    info p2 = query( right, mid + 1, e, i, j );

    result.sum = p1.sum + p2.sum;
    result.prefix = max( p1.prefix, p1.sum + p2.prefix ) ;
    result.suffix = max( p2.suffix, p2.sum + p1.suffix ) ;
    result.maxi = max( result.prefix, max( result.suffix, max( p1.maxi, max( p2.maxi, p1.suffix + p2.prefix ) ) ) ) ;

    return result;
}

int main()
{
    int n, q;

    sf1( n );

    for( int i = 1; i <= n; i++ )
    {
        sf1( a[i] );
    }

    build( 1, 1, n );

    sf1( q );

    while( q-- )
    {
        int x, y;
        sf2( x, y );

        printf("%d\n", query( 1, 1, n, x, y ).maxi );
    }
    return 0;
}

