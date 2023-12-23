//Рандом+столбцы
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int dataCheckInt(int integer) { //Проверка на int
    while (cin.fail() || integer < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка, вы должны ввести целое неотрицательное число." << endl << "Введите число ещё раз: " << endl;
        cin >> integer;
    }
    return integer;
} 

int seedR(int max) {
    int seed = 1;
    seed = seed * 1103515245 + 12345;
    seed = seed / 65536;
    return seed;     
}

int randFunction(int max) {
    int x = rand() % (max)+1;
    return x;
}

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Введите размерность матрицы:" << endl;
    int n = 0;
    cin >> n;
    n = dataCheckInt(n);
    cout << "Введите максимальное число для матрицы (рекомендуем не больше 10 000): " << endl;
    int maxNum = 10000;
    cin >> maxNum;
    maxNum = dataCheckInt(maxNum);
    std::vector <std::vector <int> > matrix;
    int v = 1;
    //Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++) {
        std::vector <int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(randFunction(maxNum));
        }
        matrix.push_back(row);
    }

    cout << "Матрица до перетосовки: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    std::vector <std::vector <int> > newMatrix;
    for (int i = 0; i < n; i++) {
        std::vector <int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(0);
        }
        newMatrix.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j +=2) {
        newMatrix[i][j] = matrix[i][j/2];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            if ((j * 2 + 1) < n){
                newMatrix[i][j * 2 + 1] = matrix[i][n - j - 1];
            }
        }
    }
    
    cout << "Матрица после: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
