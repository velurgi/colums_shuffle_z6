//Рандом+столбцы
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

int dataCheckInt(int a) {
    while (cin.fail() || a < 1 || a > 2) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка, вы должны ввести целое число." << endl;
        cin >> a;
    }
    return a;
}

int main()
{
    cout << "Введите размерность матрицы:" << endl;
    int n = 0;
    cin >> n;
    n = dataCheckInt(n);


    return 0;
}
