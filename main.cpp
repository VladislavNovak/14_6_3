#include <iostream>

//int MATRIX_SIZE = 4;

// Сравнивает две матрицы
template<size_t M>
bool hasEqual(int (&first)[M][M], int (&second)[M][M]) {
    bool isEqual = true;

    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (first[i][j] != second[i][j]) {
                isEqual = false;
                return isEqual;
            }
        }
    }

    return isEqual;
}

// Приводит массив в диагональный, обнуляя все данные не по главной диагонали
template<size_t M>
void setDiagonalMatrix(int (&result)[M][M]) {
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (i != j) {
                result[i][j] = 0;
            }
        }
    }
}

int main() {
    int base[4][4] = {
            { 2, 2, 6, 6 },
            { 2, 2, 6, 6 },
            { 2, 2, 6, 6 },
            { 2, 2, 6, 6 },
    };

    int matrix3[4][4][4] = {
            {
                    { 4, 5, 6, 7 },
                    { 2, 2, 6, 6 },
                    { 2, 2, 6, 6 },
                    { 2, 2, 6, 6 }
            },
            {
                    { 6, 2, 6, 6 },
                    { 6, 2, 6, 6 },
                    { 6, 2, 6, 6 },
                    { 2, 2, 6, 6 }
            },
            // Совпадение с base. Станет диагональной
            {
                    { 2, 2, 6, 6 },
                    { 2, 2, 6, 6 },
                    { 2, 2, 6, 6 },
                    { 2, 2, 6, 6 }
            },
            {
                    { 2, 2, 6, 0 },
                    { 7, 2, 6, 6 },
                    { 2, 9, 6, 6 },
                    { 2, 2, 6, 6 }
            }

    };

    for (auto & matrix : matrix3) {
        std::cout << std::endl;

        if (hasEqual(base, matrix)) {
            setDiagonalMatrix(matrix);

            std::cout << "Diagonal matrix:" << std::endl;
        }

        for (const auto & line : matrix) {
            for (int cell : line) std::cout << cell << " ";
            std::cout << std::endl;
        }
    }
}