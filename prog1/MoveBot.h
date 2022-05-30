#include <iostream>

using namespace std;


int massComp(int mass1[4][4], int mass2[4][4])//1 - одинаково
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (mass1[i][j] != mass2[i][j])
                return 0;
    return 1;
}



int move1(int mass[4][4])
{
    int i, j, k, l, sc;
    sc = 0;
    for (j = 0; j < 4; j++)
    {
        for (i = 1; i < 4; i++)
            if (mass[i][j] != 0 && mass[i - 1][j] == 0)
                for (k = i; k > 0 && mass[k - 1][j] == 0; k--) {
                    mass[k - 1][j] = mass[k][j];
                    mass[k][j] = 0;
                }
        for (i = 0; i < 3; i++)
            if (mass[i][j] == mass[i + 1][j])
            {
                mass[i][j] *= 2;
                sc += mass[i][j];
                for (k = i + 1; k < 3; k++)
                    mass[k][j] = mass[k + 1][j];
                mass[3][j] = 0;
            }
    }
    return sc;
}


int move0(int mass[4][4])
{
    int i, j, k, l, sc;
    sc = 0;
    for (j = 0; j < 4; j++)
    {
        for (i = 1; i < 4; i++)
            if (mass[j][i] != 0 && mass[j][i - 1] == 0)
                for (k = i; k > 0 && mass[j][k - 1] == 0; k--) {
                    mass[j][k - 1] = mass[j][k];
                    mass[j][k] = 0;
                }
        for (i = 0; i < 3; i++)
            if (mass[j][i] == mass[j][i + 1])
            {
                mass[j][i] *= 2;
                sc += mass[j][i];
                for (k = i + 1; k < 3; k++)
                    mass[j][k] = mass[j][k + 1];
                mass[j][3] = 0;
            }
    }
    return sc;
}



int allmove(int k, int mass[4][4])
{
    int sc = 0;
    switch (k) {
    case 0:  //вправо
    {
        sc = move0(mass);
    }
    break;
    case 1:  //влево
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
            {
                mass[i][j] += mass[i][3 - j];
                mass[i][3 - j] = mass[i][j] - mass[i][3 - j];
                mass[i][j] -= mass[i][3 - j];
            }
        sc = move0(mass);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
            {
                mass[i][j] += mass[i][3 - j];
                mass[i][3 - j] = mass[i][j] - mass[i][3 - j];
                mass[i][j] -= mass[i][3 - j];
            }
    }
    break;
    case 2:  //вверх
    {
        sc = move1(mass);
    }
    break;
    case 3:  //вниз
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
            {
                mass[j][i] += mass[3 - j][i];
                mass[3 - j][i] = mass[j][i] - mass[3 - j][i];
                mass[j][i] -= mass[3 - j][i];
            }
        sc = move1(mass);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
            {
                mass[j][i] += mass[3 - j][i];
                mass[3 - j][i] = mass[j][i] - mass[3 - j][i];
                mass[j][i] -= mass[3 - j][i];
            }
    }
    break;
    }
    return sc;
}




