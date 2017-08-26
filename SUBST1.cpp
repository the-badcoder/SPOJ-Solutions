#include <bits/stdc++.h>

using namespace std;

#define ii pair <int,int>
const int res = 5e5 + 10;

/// complexity: O( nlogn ).

char T[res], T1[res], x[res], y[res];                   // the input string, up to 100K characters
//string T, T1, X;
int n;                                        // the length of input string
int RA[res], tempRA[res];        // rank array and temporary rank array
int SA[res], tempSA[res];    // suffix array and temporary suffix array
int c[res];                                    // for counting/radix sort

char P[res];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Phi[res];                      // for computing longest common prefix
int PLCP[res];
int LCP[res];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
// and current suffix T+SA[i]

void counting_Sort( int k )                    // O(n)
{
    int i, sum, maxi = max( 300, n );          // up to 255 ASCII chars or length of n
    memset( c, 0, sizeof c );                  // clear frequency table

    for(  i = 0; i < n; i++ )
    {
        c[ i + k < n ? RA[ i + k ] : 0 ]++;    // count the frequency of each integer rank
    }
    for( i = sum = 0; i < maxi; i++ )
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for( i = 0; i < n; i++ )                   // shuffle the suffix array if necessary
    {
        tempSA[ c[ SA[i] + k < n ? RA[ SA[i] + k ] : 0 ]++ ] = SA[i];
    }
    for( i  = 0; i < n; i++ )                  // update the suffix array SA
    {
        SA[i] = tempSA[i];
    }
}

void constructSA() // this version can go up to 1e5 characters.
{
    int i, k, r;
    for( i = 0; i < n; i++ ) RA[i] = T[i];  // Initial Ranking.
    for( i = 0; i < n; i++ ) SA[i] = i;     // initial SA: { 0, 1, 2.....,n-1 }
    for( k = 1; k < n; k <<= 1 )            // repeat sorting process log(n) times;
    {
        counting_Sort( k );                  // actually radix sort: sort based on the second item;
        counting_Sort( 0 );                 // then ( stable ) sort based on the first item;
        tempRA[ SA[0] ] = r = 0;             // re-ranking; start from rank r = 0;
        for( i = 1; i < n; i++ )             // compare adjacent suffixes;
            tempRA[ SA[i] ] =                // if same pair => same rank; otherwise, increase r;
                ( RA[ SA[i] ] == RA[ SA[i-1] ] and RA[ SA[i] + k ] == RA[ SA[i-1]+k ] ) ? r : ++r;
        for( i = 0; i < n; i++ )                   // update the rank Array RA.
            RA[i] = tempRA[i];
        if( RA[ SA[ n - 1] ] == n - 1 ) break;       // nice optimization trick
    }
}

void computeLCP()
{
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++)               // compute Permuted LCP in O(n)
    {
        if (Phi[i] == -1)
        {
            PLCP[i] = 0;    // special case
            continue;
        }
        while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}


int owner(int idx)
{
    return (idx < n-m-1) ? 1 : 2;
}

ii LCS()                   // returns a pair (the LCS length and its index)
{
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++)                         // O(n), start from i = 1
        if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

int main()
{
    int test;

    scanf("%d", &test );
    cin.ignore();

    while( test-- )
    {
        n = ( int ) strlen( gets( T ) );
        T[ n++ ] = '#';

        constructSA();
        computeLCP();

        int digit = 0;

        for( int i = 0; i < n; i++ )
        {
            digit += n - SA[i] - 1;
            digit -= LCP[i];
        }

        printf("%d\n", digit );

    }
    return 0;
}

