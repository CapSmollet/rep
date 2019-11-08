#include <iostream>
#include <algorithm>

using namespace std;

void build_ziggurat(int n, int** Ziggurat)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Ziggurat[i][j] = min(min(i, j) + 1, min(n - i, n - j));
}

int main()
{
    int size;
    cin >> size;
    int **Ziggurat = new int*[size];
    for (int i = 0; i < size; i++)
        Ziggurat[i] = new int[size];

    build_ziggurat(size, Ziggurat);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << Ziggurat[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < size; i++)
        delete [] Ziggurat[i];
    delete [] Ziggurat;

    return 0;
}
