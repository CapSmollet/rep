include <iostream>

using namespace std;

typedef unsigned long long ullint;

ullint amount2In3 (ullint number)
{
	if (number < 3 && number != 2)
		return 0;
	else if (number % 3 == 2)
		return 1 + amount2In3(number / 3);
	else
		return amount2In3(number / 3);

}

ullint total2In3 (ullint* number, ullint size, ullint k)
{
	ullint result = 0, lresult = 0;
	for (ullint i = 0; i < size; i++)
	{
		lresult = result;
		result += amount2In3(number[i]);
		//cout << result - lresult << endl;
		if (-lresult + result < k)
			cout << number[i] << " ";
	};
	return result;
}

int main()
{
	ullint N, k;
	cin >> N >> k;
	ullint *number = new ullint[N];
	for (ullint i = 0; i < N; i++)
	{
		cin >> number[i];
	};
	cout << total2In3(number, N, k) << endl;
	return 0;
}
}
