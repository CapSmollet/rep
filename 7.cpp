#include <iostream>

using namespace std;

long long strange_multiply(long long x, long long y)
{
    int res = 0;
    for (int i = 0; i < y; i++)
        res += x;
    return res;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << strange_multiply(x, y);
}
