#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long int ullint;

ullint multOfDigits(ullint number)
{
	ullint size = (ullint)log10(number) + 1;
	ullint result = 1;
	for (ullint i = 0; i < size; i++)
	{
		result *= (number % 10 ? number % 10 : 1);
		number /= 10;
	};
	return number == 0 ? result : 0;
}
void printOfK(ullint* arr, ullint size, ullint k)
{
	for (ullint i = 0; i < size; i++)
		if (multOfDigits(arr[i]) > k)
			cout << arr[i] << " ";
}

int main()
{
	ullint N, k;
	cin >> N >> k;
	ullint* number = new ullint[N];
	for (ullint i = 0; i < N; i++)
	{
		cin >> number[i];
	};
	printOfK(number, N, k);
	return 0;
}
