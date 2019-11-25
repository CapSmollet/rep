#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ullint;

ullint divPow(ullint a, ullint b)
{
	ullint result = 0;
	while (a % (ullint)pow(b, result++) == 0);
	return result - 2;

}

int main()
{
        ullint N;
        cin >> N;
        N += 2;

        int  *primeDvds = new int[N + 1];
        primeDvds[0] = primeDvds[1] = 2;
        for (ullint i = 2; i <= N; i++)
                primeDvds[i] = 2;

        for (ullint i = 2; i <= N; i++)
                if (primeDvds[i] == 2)
                        for (ullint j = i+i; j <= N; j += i)
                                primeDvds[j] += divPow(j, i);

        N -= 2;
        for (ullint i = 2; i <= N; i++)
                if (primeDvds[i] == 2 && (primeDvds[i + 2] == 4 || primeDvds[i + 2] == 2))
                        cout << i << " ";
        cout << endl;
        return 0;
}
