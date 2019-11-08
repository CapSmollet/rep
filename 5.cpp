#include <iostream>
#include <algorithm>

using namespace std;

void put_snake(int n, int m, int** &Snake)
{
    int pos_x = m - 1;
    int pos_y = 0;
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, 1, 0, -1};

    bool possible = true;
    int num = 1, step = 0;
    while (possible)
    {
        Snake[pos_y][pos_x] = num++;
        if (pos_y + diry[step] >= n || pos_y + diry[step] < 0 || pos_x + dirx[step] >= m || pos_x + dirx[step] < 0)
            step = (step + 1) % 4;
        else if (Snake[pos_y + diry[step]][pos_x + dirx[step]] != 0)
            step = (step + 1) % 4;

        if (Snake[pos_y + diry[step]][pos_x + dirx[step]] != 0)
        {
            possible = false;
        }
        else
        {
            pos_x += dirx[step];
            pos_y += diry[step];
        }

    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **Snake = new int*[n];
    for (int i = 0; i < n; i++)
        Snake[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Snake[i][j] = 0;

    put_snake(n, m, Snake);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << Snake[i][j] << "t";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete [] Snake[i];
    delete [] Snake;
    return 0;
}
