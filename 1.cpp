#include <iostream>

using namespace std;

int delete_duplicates(int d, int* &Array)
{
    int dup = 0;
    for (int i = 0; i < d; i++)
        for (int j = i; j >= 0; j--)
            if (Array[i] == Array[j] && i != j)
            {
                dup++;
                break;
            }

    int* b = new int[d - dup];
    int cnt = 0;
    for (int i = 0; i < d; i++)
    {
        bool dp = false;
        for (int j = i - 1; j >= 0; j--)
            if (Array[i] == Array[j])
               dp = true;
        if (!dp)
            b[cnt++] = Array[i];
    }
    int *c = Array;
    Array = new int[d - dup];
    for (int i = 0; i < d - dup; i++)
        Array[i] = b[i];
    return d - dup;
}

int main() {
    int d;
    cin >> d;
    int* Array = new int[d];
    for (int i = 0; i < d; i++)
        cin >> Array[i];
    d = delete_duplicates(d, Array);
    for (int i = 0; i < d; i++)
        cout << Array[i] << " ";
    delete [] Array;
    return 0;
}
