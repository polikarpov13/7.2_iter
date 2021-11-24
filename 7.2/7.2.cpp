#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** array, const int k, const int n, const int Low, const int High);
void Print(int** array, const int k, const int n);
int min_elements_sum(int** array, const int k, const int n);

void Create(int** array, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** array, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
    cout << endl;
}


int min_elements_sum(int** array, const int rows, const int cols)
{
    int sum = 0;
    int min;

    for (int i = 0; i < cols; i++)
    {
        if (i % 2 == 0) {
            min = array[0][i];
            for (int j = 0; j < rows; j++) {
                if (array[j][i] < min)
                    min = array[j][i];
            }
            sum += min;
        }
    }

    return sum;
}


int main()
{
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 30;
    int k;
    int n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** array = new int* [k];
    for (int i = 0; i < k; i++)
        array[i] = new int[n];

    Create(array, k, n, Low, High);
    Print(array, k, n);

    cout << "Sum : " << min_elements_sum(array, k, n) << endl;
    for (int i = 0; i < k; i++)
        delete[] array[i];
    delete[] array;

    return 0;
}