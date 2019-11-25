#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ullint;

ullint primer(ullint N)
{
        ullint result = 1;
        bool *isPrime = new bool[N + 1];

        isPrime[0] = isPrime[1] = false;
        for (ullint i = 2; i <= N; i++)
        {
                isPrime[i] = true;
        };

        for (ullint i = 2; i <= N; i++)
        {
                if (isPrime[i] && i <= (ullint)sqrt(N))
                        for (ullint j = i+i; j <= N; j += i)
                                isPrime[j] = false;
                if (isPrime[i])
			          result *= i;
        };
        return result;

}


int main()
{
        ullint N;
        cin >> N;
        cout << primer(N);
        return 0;
}
