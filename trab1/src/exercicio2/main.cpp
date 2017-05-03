#include <iostream>
#include <random>

void malmult(float** A, float** B, float** C, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = A[i][j] + B[i][k] * C[k][j];
            }
        }
    }
}

void malmultTie2(float** A, float** B, float** C, int n)
{
    for (int k = 0; k < n; k += 2)
    {
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < n; j += 2)
            {
                A[i][j] = A[i][j] + B[i][k] * C[k][j];
                A[i+1][j] = A[i+1][j] + B[i+1][k] * C[k][j];
                A[i][j] = A[i][j] + B[i][k+1] * C[k+1][j];
                A[i+1][j] = A[i+1][j] + B[i+1][k+1] * C[k+1][j];
                A[i][j+1] = A[i][j+1] + B[i][k] * C[k][j+1];
                A[i+1][j+1] = A[i+1][j+1] + B[i+1][k] * C[k][j+1];
                A[i][j+1] = A[i][j+1] + B[i][k+1] * C[k+1][j+1];
                A[i+1][j+1] = A[i+1][j+1] + B[i+1][k+1] * C[k+1][j+1];
            }
        }
    }
}

void malmultTieNB(float** A, float** B, float** C, int n, int nb)
{
    for (int k = 0; k < n; k += nb)
    {
        for (int i = 0; i < n; i += nb)
        {
            for (int j = 0; j < n; j += nb)
            {
                for (int kk = k; kk < k+nb; kk++)
                {
                    for (int ii = i; ii < i+nb; ii++)
                    {
                        for (int jj = j; jj < j+nb; jj++)
                        {
                            A[ii][jj] = A[ii][jj] + B[ii][kk] * C[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

void malmultTieComb(float** A, float** B, float** C, int n, int nb)
{
    for (int k = 0; k < n; k += 2)
    {
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < n; j += nb)
            {
                for (int t = 0; t < nb; t++)
                {
                    A[i][j+t] = A[i][j+t] + B[i][k] * C[k][j+t];
                }
                A[i+1][j] = A[i+1][j] + B[i+1][k] * C[k][j];
                A[i][j] = A[i][j] + B[i][k+1] * C[k+1][j];
                A[i+1][j] = A[i+1][j] + B[i+1][k+1] * C[k+1][j];
                A[i+1][j+1] = A[i+1][j+1] + B[i+1][k] * C[k][j+1];
                A[i][j+1] = A[i][j+1] + B[i][k+1] * C[k+1][j+1];
                A[i+1][j+1] = A[i+1][j+1] + B[i+1][k+1] * C[k+1][j+1];
            }
        }
    }
}

float** genRandomMatrix(int n)
{
    srand(0);
    float** M = new float*[n];
    for (int i = 0; i < n; i++)
    {
        M[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            M[i][j] = float(rand()) / float(RAND_MAX) * 10.0f;
        }
    }
    return M;
}

void deleteMatrix(float** M, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete [] M[i];
    }
    delete [] M;
}

void printMatrix(float** M, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    int n;
    int multType;
    int nb;
    if (argc < 3)
    {
        std::cout << "Please input matrix size and press [ENTER]: ";
        std::cin >> n;

        std::cout << "Please input matrix mult type [1: Normal, 2: Tie2, 3: NB, 4: Combination]: ";
        std::cin >> multType;

        std::cout << "Please input NB value: ";
        std::cin >> nb;
    }
    else 
    {
        n = std::stoi(argv[1]);
        multType = std::stoi(argv[2]);
        nb = std::stoi(argv[3]);
    }

    float** A = genRandomMatrix(n);
    float** B = genRandomMatrix(n);
    float** C = genRandomMatrix(n);

    clock_t start, end;

    switch (multType)
    {
        case 1:
            start = clock();
            malmult(A, B, C, n);
            end = clock();
            std::cout << "Normal: ";
            break;
        case 2:
            start = clock();
            malmultTie2(A, B, C, n);
            end = clock();
            std::cout << "Tie2: ";
            break;
        case 3:
            start = clock();
            malmultTieNB(A, B, C, n, nb);
            end = clock();
            std::cout << "NB: ";
            break;
        case 4:
            start = clock();
            malmultTieComb(A, B, C, n, nb);
            end = clock();
            std::cout << "Combination: ";
            break;
    }

    std::cout << double(end - start) / CLOCKS_PER_SEC << std::endl;

    deleteMatrix(A, n);

    return 0;
}
