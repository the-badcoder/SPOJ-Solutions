#include <bits/stdc++.h>

using namespace std;

const int res = 2e5 + 10;

/// complexity: O( nlogn ).

string T;
int n;
int RA[res], tempRA[res];
int SA[res], tempSA[res];
int c[res];

void counting_Sort( int k )
{
    int i, sum, maxi = max( 300, n );
    memset( c, 0, sizeof c );

    for(  i = 0; i < n; i++ )
        c[ i + k < n ? RA[ i + k ] : 0 ]++;
    for( i = sum = 0; i < maxi; i++ )
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for( i = 0; i < n; i++ )
    {
        tempSA[ c[ SA[i] + k < n ? RA[ SA[i] + k ] : 0 ]++ ] = SA[i];
    }

    for( i  = 0; i < n; i++ )
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

int main()
{
    int test;
    char ch[res];

    //scanf("%d", &test);
    //cin.ignore();


        scanf("%s", ch );
        T = ch;
        T += ch;
        n = T.size();
        T[n++] = '~';

        constructSA();
        for( int i = 0; i < n; i++ )
        {
            if( SA[i] < n / 2 )
            {
                printf("%d\n", (SA[i]) );
                break;
            }
        }
    }
//}
