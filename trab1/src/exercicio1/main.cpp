#include <iostream>
#include <random>


void malmultIJK(float** A, float** B, float** C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                A[i][j] = A[i][j] + B[i][k] * C[k][j];
            }
        }
    }
}

void malmultJKI(float** A, float** B, float** C, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                A[i][j] = A[i][j] + B[i][k] * C[k][j];
            }
        }
    }
}

void malmultKIJ(float** A, float** B, float** C, int n)
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

void malmultKJI(float** A, float** B, float** C, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                A[i][j] = A[i][j] + B[i][k] * C[k][j];
            }
        }
    }
}

float** genRandomMatrix(int n)
{
    srand(time(0));
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
    if (argc < 3)
    {
        std::cout << "Please input matrix size and press [ENTER]: ";
        std::cin >> n;

        std::cout << "Please input matrix mult type [1: IJK, 2: JKI, 3: KIJ, 4: KJI]: ";
        std::cin >> multType;
    }
    else 
    {
        n = std::stoi(argv[1]);
        multType = std::stoi(argv[2]);
    }

    float** A = genRandomMatrix(n);
    float** B = genRandomMatrix(n);
    float** C = genRandomMatrix(n);
    
    clock_t start, end;
    
    switch (multType)
    {
        case 1:
            start = clock();
            malmultIJK(A, B, C, n);
            end = clock();
            std::cout << "IJK: ";
            break;
        case 2:
            start = clock();
            malmultJKI(A, B, C, n);
            end = clock();
            std::cout << "JKI: ";
            break;
        case 3:
            start = clock();
            malmultKIJ(A, B, C, n);
            end = clock();
            std::cout << "KIJ: ";
            break;
        case 4:
            start = clock();
            malmultKJI(A, B, C, n);
            end = clock();
            std::cout << "KJI: ";
            break;
    }

    std::cout << double(end - start) / CLOCKS_PER_SEC << std::endl;

    deleteMatrix(A, n);

    return 0;
}