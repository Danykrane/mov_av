#include <iostream>
#include <memory>
#include <iomanip>
#include <unistd.h>

using namespace std;

template <class T>
void input_val(T &); //ввод интервала

template <class T>
void input(T &, size_t &); //генерация чисел

template <class T>
void output(T &, const size_t); //вывод значений

template <class T>
void edit_midd_vall(T &, T &, const size_t, const size_t); //подсчет скользящей средней

template <class T>
void show_all_app_data(T &, T &, const size_t, const size_t); //поэтапный вывод в консоль

int main()
{
    size_t len; //кол-во измерений
    unique_ptr<double[]> data(new double[len]);
    input(data, len); //заполнение значений температур

    size_t interval;     //интервал скользящей
    input_val(interval); //ввод скользящей

    size_t new_len = len - 2 * ((interval - 1) / 2);         //длина массива скользящей
    unique_ptr<double[]> middle_m_data(new double[new_len]); //создание указателя на дин массив средней скольз длины - потери

    edit_midd_vall(middle_m_data, data, interval, new_len);    //подсчет и занесение значений сокльзящей
    show_all_app_data(middle_m_data, data, interval, new_len); //вывод результатов
}

template <class T>
void input_val(T &value)
{
    cout << "Введите значение интервала скользящей" << endl;
    cin >> value;
}

template <class T>
void input(T &array_of_data, size_t &size)
{
    cout << "Укажите кол-во температурных измерений:\n";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        array_of_data[i] = (rand() / (double)RAND_MAX) * (100 - -30) + -30; //генерация рандомных дробных чисел
    }
}

template <class T>
void output(T &array_of_data, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " value is: " << fixed << setprecision(2) << array_of_data[i] << "\n";
    }
}

template <class T>
void edit_midd_vall(T &array_of_middle, T &array_of_data, const size_t interv, const size_t size)
{
    //подсчет и занесение среднего арифметического
    for (int i = 0; i < size; i++)
    {

        double sum = 0;
        for (int j = i; j < i + interv; j++)
        {
            sum += array_of_data[j];
        }
        array_of_middle[i] = sum / interv;
    }
}

template <class T>
void show_all_app_data(T &array_of_middle, T &array_of_data, const size_t interv, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        sleep(1);
        cout << "\nДанные для " << i + 1 << " интервала:\nтемпературный интервал : ";
        for (int j = i; j < interv + i; j++)
        {
            cout << array_of_data[j] << " ";
        }
        cout << "\nТекущее скользящее среднее => " << array_of_middle[i] << "\n";
    }
}