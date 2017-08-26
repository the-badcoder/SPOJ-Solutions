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

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e6 + 10;
const ll mod = 1e9 + 7;

ll BIT[res], a[res], b[res];
int n;

void update( int x, ll val )
{
    ll sum = 0;
    for( ; x <= n; x += x&-x )
    {
        BIT[x] += val;
    }
}

void range_update( int a, int b, ll v ) // for range update.
{
    update( a, v );
    update( b + 1, -v );
}

ll query( ll x )
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
    int test;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        memset( BIT, 0, sizeof BIT );
        memset( a, 0, sizeof a );
        memset( b, 0, sizeof b );

        for( int i = 0; i < n; i++ )
        {
            scanf("%lld", &a[i] );
            b[i] = a[i];
        }

        sort( b, b + n );

        for( int i = 0; i < n; i++ )
        {
            int rankk = lower_bound( b, b + n, a[i] ) - b;
            a[i] = rankk + 1;
        }
        ll inv_count = 0;

        for( int i = n - 1; i >= 0; i-- )
        {
            //deb( a[i], i, a[i] - 1 );
            ll x = query( a[i] - 1 );
            inv_count += x;
            update( a[i], 1 );
        }
        printf("%lld\n", inv_count );
    }
    check_time();
    return 0;
}

