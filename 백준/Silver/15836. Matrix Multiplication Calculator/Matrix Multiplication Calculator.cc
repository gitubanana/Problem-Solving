#include <stdio.h>
#include <stdexcept>

class Matrix {
private:
    int **arr;
    int ySize, xSize;
public:
    Matrix(FILE *stream, int ySize, int xSize) : arr(new int*[ySize]), ySize(ySize), xSize(xSize) {
        for (int y = 0; y < ySize; y++) {
            arr[y] = new int[xSize];
            for (int x = 0; x < xSize; x++) {
                fscanf(stream, " %d", &arr[y][x]);
            }
        }
    }

    Matrix(int ySize, int xSize) : arr(new int*[ySize]), ySize(ySize), xSize(xSize) {
        for (int y = 0; y < ySize; y++) {
            arr[y] = new int[xSize];
        }
    }

    Matrix(const Matrix &o) : arr(NULL), ySize(0), xSize(0) {
        *this = o;
    }

    ~Matrix() {
        for (int y = 0; y < ySize; y++) {
            delete[] arr[y];
        }
        delete[] arr;
    }

    // deep copy
    Matrix &operator=(const Matrix &o) {
        this->~Matrix();

        ySize = o.ySize;
        xSize = o.xSize;
        arr = new int*[ySize];
        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                arr[y][x] = o.arr[y][x];
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix &o) const {
        if (this->xSize != o.ySize) {
            throw std::runtime_error("undefined");
        }

        Matrix ret(this->ySize, o.xSize);

        for (int y = 0; y < ret.ySize; y++) {
            for (int x = 0; x < ret.xSize; x++) {
                int num = 0;

                for (int i = 0; i < this->xSize; i++) {
                    num += this->arr[y][i] * o.arr[i][x];
                }
                ret.arr[y][x] = num;
            }
        }
        return ret;
    }

    friend void printMatrix(const Matrix &);
};

void printMatrix(const Matrix &m) {
    for (int y = 0; y < m.ySize; y++) {
        printf("| ");
        for (int x = 0; x < m.xSize; x++) {
            printf("%d ", m.arr[y][x]);
        }
        printf("|\n");
    }
}

int main(void) {
    for (int t = 1; ; t++) {
        int aYsize, aXsize;
        int bYsize, bXsize;

        scanf(" %d %d %d %d", &aYsize, &aXsize, &bYsize, &bXsize);
        if (aYsize == 0) {
            break;
        }

        printf("Case #%d:\n", t);

        Matrix A(stdin, aYsize, aXsize);
        Matrix B(stdin, bYsize, bXsize);

        try {
            printMatrix(A * B);
        } catch (std::exception &e) {
            printf("%s\n", e.what());
        }
    }
    return 0;
}
