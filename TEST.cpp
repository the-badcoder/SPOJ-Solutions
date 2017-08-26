/*
    Bismillah Hir Rahmanir Rahim

    *MAY ALLAH HELP ME*
*/
/// Author: Tareq Aziz Khan

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <string>
#define PI 2 * acos(0.0)
#define LL long long

using namespace std;


int main()
{
     vector < int > v;
     int input, n, i;


     do {
        cin >> input;
        v.push_back(input);
     }while( input != 42 );

     for(i = 0; i < v.size(); i++ ){
        if( v[i] == 42 )
            break;
        cout << v[i] << endl;
     }
     return 0;
}
