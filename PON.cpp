#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#define ull unsigned long long
using namespace std;

/*
 * calculates (a * b) % c taking into account that a * b might overflow
 */
ull mulmod(ull a, ull b, ull mod)
{
    ull x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

/*
 * modular exponentiation
 */
ull modulo(ull base, ull exponent, ull mod)
{
    ull x = 1;
    ull y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)x = mulmod(x, y, mod);
        y = mulmod(y, y, mod);
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool MillerRabin(ull p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ull s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ull a = rand() % (p - 1) + 1, temp = s;
        ull mod = modulo(a, temp, p);
        if(mod==1 || mod == p-1)continue;
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1)return false;
    }

    return true;
}

int main()
{
    int tests = 5;

    int tc;

    scanf("%d", &tc );

    while( tc-- )
    {
        ull num;
        scanf("%llu", &num);
        if (MillerRabin(num, tests))printf("YES\n");
        else printf("NO\n");

    }
}
