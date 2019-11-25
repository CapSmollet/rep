#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        unsigned long long int N, count;
        cin >> N;

	count = N;
	if (N <= 5)
		N += N + N + 1;
	else
		N += N;



	bool *isPrime = new bool[N + 1];

        isPrime[0] = isPrime[1] = false;
        for (unsigned long long int i = 2; i <= N; i++)
        {
                isPrime[i] = true;
        };

        for (unsigned long long int i = 2; i*i <= N; i++)
        {
                if (isPrime[i] && i <= (unsigned long long int)sqrt(N))
                        for (unsigned long long int j = i*i; j <= N; j += i)
                                isPrime[j] = false;;
        };
	unsigned long long int i = 2;
	while (count > 0)
	{
		if(!isPrime[i])
		{
			cout << i << " ";
			count--;
		};
		i++;
	};
        cout << endl;
        return 0;
}
