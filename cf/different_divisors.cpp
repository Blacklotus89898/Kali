#include <iostream>

#define ll long long

bool is_prime(ll n);

int main()
{
    // at least 4 divisors, so not prime
    // divisor separated by at least d

    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int d = 0;
        std::cin >> d;

        // start from a number 4 * d
        //  check if 1 + d and 1 + 2 * d are divisors of the number

        // must garantee that 1 + d and 1 + 2 * d are primes

        ll a = 1 + d;
        while (!is_prime(a))
        {
            a++;
        }

        ll b = a + d;
        while (!is_prime(b))
        {
            b++;
        }

        // while (num % (1 + d) != 0 || num % (1 + 2 * d) != 0)
        // {
        //     num++;
        // }

        std::cout << a * b << std::endl;
    }

    return 0;
}

bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}