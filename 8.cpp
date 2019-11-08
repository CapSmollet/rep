#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}

int proper_fraction(int n)
{
    int result = 0;
    for (int i = 1; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return 2 * result;
}

int main() {
    int n;
    cin >> n;
    cout << proper_fraction(n);
}
