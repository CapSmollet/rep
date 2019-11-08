#include <iostream>

using namespace std;

int strange_sum(int l, int r, int *Array)
{
    if (l == r)
        return Array[l];
    return strange_sum(l, (l + r)/2, Array) + strange_sum((l + r)/2 + 1, r, Array);
}

int main() {
    int d;
    cin >> d;
    int* Array = new int[d];
    for (int i = 0; i < d; i++)
        cin >> Array[i];
    cout << strange_sum(0, d - 1, Array);
    delete [] Array;
    return 0;
}
