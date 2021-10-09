#include <iostream>
#include <locale.h>
using namespace std;

void sum(int a, int b);
int remains(int a1, int b1);
void k_s(int N);
void contribution(float P);
int Evklid(int A, int B);
void Fibonachi(int Fib);

int main()
{
    setlocale(LC_ALL, "ru");
    int number, a, b, summ, n;
    float p;
    bool end = true;
    while (end == true) {
        cout << "Выберите задание, которое хотите проверить:\n" << 
            "1. Даны целые положительные числа A и B (A < B).\nВывести все целые числа от A до B включительно; при этом каждое число должно выводиться столько раз, каково его значение (например, число 3 выводится 3 раза).\n" <<
            "2. Даны положительные числа A и B (A > B).\nНа отрезке длины A размещено максимально возможное количество отрезков длины B (без наложений).\nНе используя операции умножения и деления, найти длину незанятой части отрезка A.\n" <<
            "3. Дано целое число N (> 1).\nВывести наименьшее из целых чисел K, для которых сумма 1 + 2 + . . . + K будет больше или равна N, и саму эту сумму.\n" <<
            "4. Начальный вклад в банке равен 1000 руб.\nЧерез каждый месяц размер вклада увеличивается на P процентов от имеющейся суммы (P — вещественное число, 0 < P < 25).\nПо данному P определить, через сколько месяцев размер вклада превысит 1100 руб., и вывести найденное количество месяцев K (целое число) и итоговый размер вклада S (вещественное число).\n" <<
            "5. Даны целые положительные числа A и B.\nНайти их наибольший общий делитель (НОД), используя алгоритм Евклида.\n" <<
            "6. Дано целое число N (> 1), являющееся числом Фибоначчи: N = FK.\nНайти целое число K — порядковый номер числа Фибоначчи N.\n" <<
            "Для завершения проги нажмите любую другую цифру, хорошего вам дня :)\n\n" << 
            "Введите число: ";
        cin >> number;
        if (number >= 1 and number <= 6) {
            switch (number)
            {
            case 1:
                system("cls");
                cout << "Вы просматриваете 1 задание.\n\n";
                cout << "Введите числа А и В (A < B):\n";
                cin >> a >> b;
                sum(a, b);
                cout << endl;
                break;
            case 2:
                system("cls");
                cout << "Вы просматриваете 2 задание.\n\n";
                cout << "Введите числа А и В (A > B):\n";
                cin >> a >> b;
                summ = remains(a, b);
                if (summ != -1) {
                    cout << "Остаток равен: " << summ << endl << endl;
                }
                else {
                    cout << "Ошибка ввода\n\n";
                }
                break;
            case 3:
                system("cls");
                cout << "Вы просматриваете 3 задание.\n\n";
                cout << "Введите число N (N > 1):\n";
                cin >> n;
                k_s(n);
                cout << endl;
                break;
            case 4:
                system("cls");
                cout << "Вы просматриваете 4 задание.\n\n";
                cout << "Введите число процентов P (0<P<25): ";
                cin >> p;
                contribution(p);
                cout << endl;
                break;
            case 5:
                system("cls");
                cout << "Вы просматриваете 5 задание.\n\n";
                cout << "Введите два положительных числа A и B: ";
                cin >> a >> b;
                summ = Evklid(a, b);
                if (summ != 0) {
                    cout << summ << endl << endl;
                }
                else
                    cout << "Ошибка ввода, прекратите ошибаться...\n";
                break;
            case 6:
                system("cls");
                cout << "Вы просматриваете 6 задание.\n\n";
                cout << "Введите число N, являющееся числом Фибоначчи (N>1): ";
                cin >> n;
                Fibonachi(n);
                break;
            }
        }
        else {
            system("cls");
            cout << "Спасибо за проверку лабы!!! :)\n";
            end = false;
        }
    }
}

void sum(int a, int b) {
    if (a >= b) {
        cout << "Ошибка ввода\n\n";
    }
    else {
        for (int i = a; i <= b; i++) {
            for (int j = 0; j < i; j++) {
                cout << i << "\t";
            }
            cout << endl;
        }
    }
}

int remains(int a1, int b1) {
    if (a1 > b1) {
        int x = a1;
        for (int i = b1; i <= a1; i += b1) {
            x -= b1;
        }
        return x;
    }
    else
        return -1;
}

void k_s(int N) {
    if (N > 1) {
        int i = 0, k, j = 0;
        while (i < N) {
            j++;
            i += j;
            k = j;
        }
        cout << "Сумма равна " << i << endl << "k суммы равно " << k << endl << endl;
    }
    else 
        cout << "Ошибка ввода!!!\n\n";
}

void contribution(float P) {
    system("cls");
    int i = 0;
    double k = 1000;
    if (P > 0 and P < 25) {
        for (k ; k < 1100; k += (float)k * (P / 100)) {
            i++;
        }
        cout << "Итоговый размер вклада " << k << endl << "Месяцев прошло: " << i << endl;
    }
    else
        cout << "Ошибка ввода!!!\n";
}

int Evklid(int A, int B) {
    system("cls");
    if (A > 0 and B > 0) {
        while (A != B) {
            if (A > B) {
                A = A - B;
            }
            else if (B > A) {
                B = B - A;
            }
        }
        cout << "Наибольший общий делитель равен: ";
        return A;
    }
    else
        return 0;
}

void Fibonachi(int Fib) {
    system("cls");
    int i = 0, j = 1, g = 0, count = 2;
    if (Fib > 1) {
        for (; g < Fib; g = i + j) {
            if (i > j) {
                j = i;
                i = g;
            }
            else if (j > i) {
                i = j;
                j = g;
            }
            else {
                i = j;
                j = g;
            }
            count++;
        }
        if (g == Fib) {
            cout << "Порядковый номер числа Фибоначчи равен: " << count << endl;
        }
        else {
            cout << "Число не является числом Фибоначчи!!!\n\n";
        }
    }
    else
        cout << "Ошибка ввода\n\n";
}