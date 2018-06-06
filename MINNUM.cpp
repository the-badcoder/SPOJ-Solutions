/// Bismillah Hir Rahmanir Rahim

/**
    Practice like Cristiano Ronaldo
        Play Like Leo Messi..
**/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define space ""
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

const int res = 1e5 + 1;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/

char ch[ 26 ];

int main()
{
    string s;

    while( cin >> s )
    {
        if( s == "-1")
        {
            break;
        }
        if( s.size() == 1 && s[ 0 ] == '0' )
        {
            deb("0");
            continue;
        }
        else if( s.size() == 1 and s[ 0 ] != '0' )
        {
            deb("1");
            continue;
        }
        int len = s.size();
        ll sum = 0;

        for( int i = 0; i < len; i++ )
        {
            sum = sum * 10 + (s[ i ] - '0');
            //deb( "HY", sum );
            ll temp = sum / 9;
            sum -= (temp * 9);
            ch[ i ] = temp + '0';

            //deb("HY", ch[ i ] );
        }

        //deb("VALUE", sum );

        if( sum > 0 )
        {
            len--;
            ll curr = ch[ len ] - '0';

            while( curr > 8 )
            {
                ch[ len ] = '0';
                len--;
                curr = ch[ len ] - '0';
            }
            curr = curr + 1;
            ch[ len ] = curr + '0';
            //deb( curr, ch[ len ] );

            for( int i = 0; i < s.size(); i++ )
            {
                //deb( i, ch[ i ] );
                if( ch[ i ] == '0' and i == 0 )
                {
                    continue;
                }
                cout << ch[ i ];
            }
            cout << endl;
        }
        else
        {
            for( int i = 0; i < s.size(); i++ )
            {
                if( ch[ i ] == '0' and i == 0 )
                {
                    continue;
                }
                //deb( i, ch[ i ] );
                cout << ch[ i ];
            }
            cout << endl;
        }
    }
    return 0;

}
