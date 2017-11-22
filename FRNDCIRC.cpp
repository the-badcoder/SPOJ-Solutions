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
const ll mod = 1e9 + 7;


const int maxn = 2e5 + 10;
int Rank[maxn], p[maxn];
vi setSize;
int numSets;

struct DisjointSet
{
    void make_set( int n )
    {
        numSets = n;       /// it will count number of disjointset.
        setSize.assign( n + 1, 1); /// initially setsize is 1;

        for( int i = 1; i <= n; i++ )
        {
            Rank[i] = 0;      /// at first time all rank  == 0;
            p[i] = i;         /// parent[i] == i;
        }
    }

    int findSet( int i )
    {
        return ( p[i] == i ) ? i : ( p[i] = findSet( p[i] ) ); /// Path Comperssions.
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j); /// return true or false;
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet( i ), y = findSet( j ); /// Finding Parents.

            if( Rank[x] > Rank[y] )
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];

                if( Rank[x] == Rank[y] )
                {
                    Rank[y]++;
                }
            }
        }
    }

    int numofdisjointset()
    {
        return numSets;    /// Return component or numofdisjointset;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

} UF;


int main()
{
    int test, n, sum, total, comp;
    msi m;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        UF.make_set( n * 2 );
        m.clear();
        setSize.clear();
        int digit = 0;
        cin.ignore();

        for( int i = 0; i < n; i++ )
        {
            string x, y;

            cin >> x >> y;

            if( !m.count( x ) )
            {
                m[ x ] = ++digit;
            }
            if( !m.count( y ) )
            {
                m[ y ] = ++digit;
            }

            //deb( m[ x ], m[ y ] );

            if( !UF.isSameSet( m[ x ], m[ y ] ) ){
                UF.unionSet( m[ x ], m[ y ] );
            }
            printf("%d\n", UF.sizeOfSet( m[x] ) );
            //deb( UF.sizeOfSet( m[ x ] ), UF.sizeOfSet( m[ y ] ) );
        }
    }


    return 0;
}

