// pr9_Shitov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void operation1(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = data[i] * 0.9;
    }
    cout << "Скидка 10% применена ко всем товарам" << endl;
}
void operation2(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = data[i] * 0.8;
    }
    cout << "Скидка 20% применена ко всем товарам" << endl;
}
void operation3(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = data[i] + 70.00;
    }
    cout << "Наценка 70р. применена ко всем товарам" << endl;
}
void operation4(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = round(data[i]);
    }
    cout << "Округление применено ко всем товарам" << endl;
}
//void processor(double* data, int size);
//void (*processor)(double* data, int) = nullptr;
//void (*processors[])(double*, int) = {
//    operation1,
//    operation2,
//    operation3,
//    operation4
//};
void applyProcessing(
    double* data,
    int size,
    void (*processor)(double*, int)
) {
    if (processor != nullptr)
    {
        processor(data, size);
    }
    //else cout << "Выбранной функции не существует" << endl;
}

void printArray(double* data, int size)
{
    cout << "Текущие цены: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " | ";
    }
    cout << "\n";
}
int main()
{
    setlocale(NULL, "Russian");
    const int SIZE = 6;

    double prices[SIZE] = { 1250.25, 980.00, 1102.73, 647.12, 1450.50, 732.98 };
    double copyPrices[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        copyPrices[i] = prices[i];
    }

    void (*processors[])(double*, int) = {
            operation1,
            operation2,
            operation3,
            operation4
        };
    int choice;
    do
    {
        cout << "===МЕНЮ===" << endl <<
            "1. Показать текущие цены" << endl <<
            "2. Выбрать и выполнить обработку" << endl <<
            "3. Восстановить исходные данные" << endl <<
            "4. Выход" << endl;
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            choice = 20;
        }
        cin.ignore(10000, '\n');
        try
        {
            if (choice == 1)
            {
                printArray(prices, SIZE);
            }
            else if (choice == 2)
            {
                int choice2;
                do
                {
                    cout << "===Выберите функцию===" << endl <<
                        "1. Применить скидку 10%" << endl <<
                        "2. Применить скидку 20%" << endl <<
                        "3. Добавить фиксированную наценку" << endl <<
                        "4. Округлить цены до целого значения" << endl <<
                        "5. Назад" << endl;
                    cin >> choice2;
                    if (cin.fail())
                    {
                        cin.clear();
                        choice = 20;
                    }
                    cin.ignore(10000, '\n');
                    if (choice2 > 0 && choice2 < 5)
                    {
                        applyProcessing(prices, SIZE, processors[choice2 - 1]);
                    }
                    else if (choice2 == 5)
                    {
                        cout << "Возвращение назад..." << endl;
                    }
                    else
                    {
                        cout << "Неверный ввод" << endl;
                    }
                } while (choice2 != 5);
            }
            else if (choice == 3)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    prices[i] = copyPrices[i];
                }    
                cout << "Данные востановленны в исходное состояние" << endl;
            }
            else if (choice == 4)
            {
                cout << "Выход..." << endl;
            }         
            else cout << "Неверный ввод" << endl;
        }
        catch (const exception& e)
        {
            cerr << "Ошибка: " << e.what() << endl;
        }
    } while (choice != 4);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
