#include <iostream>
#include <cstring>

enum    e_idx
{
    A,
    B,
    SIZE
};

int main(void)
{
    int **matrix[SIZE];
    int i, y, x;
    int y_size, x_size;
    
    scanf(" %d %d", &y_size, &x_size);
    for (i = 0; i < SIZE; ++i)
    {
        matrix[i] = new int*[y_size];
        for (y = 0; y < y_size; ++y)
        {
            matrix[i][y] = new int[x_size];
            for (x = 0; x < x_size; ++x)
                scanf(" %d", &matrix[i][y][x]);
        }
    }
    for (y = 0; y < y_size; ++y)
    {
        for (x = 0; x < x_size; ++x)
            printf("%d ", matrix[A][y][x] + matrix[B][y][x]);
        printf("\n");
    }
    return (0);
}
