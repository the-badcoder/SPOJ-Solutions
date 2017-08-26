#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair < int, int >;
const int res = 2e6 + 10;
const int res1 = 1e6 + 10;

int n, q, BLOCK_SIZE, a[res];
ll current_answer, digit[res], answers[res];

pair < ii, int > queries[res];

inline bool mo_cmp( const pair < ii, int > &x, const pair < ii, int > &y )
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;

    if( block_x != block_y )
    {
        return block_x < block_y;
    }
    return x.first.second < y.first.second;
}

inline void add( int x )
{
    digit[ x ]++;
    if( digit[x] == 1 )
    {
        current_answer++;
    }
}

inline void rmv( int x )
{
    digit[ x ]--;
    if( digit[x] == 0 )
    {
        current_answer--;
    }
}

int main()
{
    scanf("%d", &n );
    BLOCK_SIZE = static_cast <int> ( sqrt( n ) );

    for( int i = 0; i < n; i++ )
    {
        scanf("%d", &a[i] );
    }

    scanf("%d", &q );

    for( int i = 0; i < q; i++ )
    {
        //cin >> queries[i].first.first >> queries[i].first.second;
        scanf("%I64d %I64d", &queries[i].first.first, &queries[i].first.second );
        queries[i].first.first--, queries[i].first.second--;
        queries[i].second = i;
    }

    sort( queries, queries + q, mo_cmp );

    int mo_left = 0, mo_right = -1;

    for( int i = 0; i < q; i++ )
    {
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        while( mo_right < right )
        {
            mo_right++;
            add( a[ mo_right ] );
        }

        while( mo_right > right )
        {
            rmv( a[ mo_right ] );
            mo_right--;
        }

        while( mo_left < left )
        {
            rmv( a[ mo_left ] );
            mo_left++;
        }

        while( mo_left > left )
        {
            mo_left--;
            add( a[ mo_left ] );
        }

        answers[ queries[i].second ] = current_answer;
    }

    for( int i = 0; i < q; i++ )
    {
        printf("%I64d\n", answers[i] );
    }

    return 0;
}
