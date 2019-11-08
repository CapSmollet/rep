#include <iostream>
#include <algorithm>

using namespace std;

void dig_trench(int n, int** Trench)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Trench[i][j] = abs(j - i);
}

int main()
{
    int size;
    cin >> size;
    int **Trench = new int*[size];
    for (int i = 0; i < size; i++)
        Trench[i] = new int[size];

    dig_trench(size, Trench);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << Trench[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < size; i++)
        delete [] Trench[i];
    delete [] Trench;
    return 0;
}
