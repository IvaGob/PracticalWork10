#include <iostream>
#include <Windows.h>
using namespace std;

class Time {
public:
    int sec = 0;
    int min = 0;
    void AddSec() {
        int input;
        cout << "Введіть кількість секунд:"<< endl;
        cin >> input;
        if (input < 0) {
            cout << "Введіть додатнє число!";
            AddSec();
        }
        sec += input;
        while (sec >= 60) {
            min++;
            sec -= 60;
        }
    }
    void RemSec() {
        int input;
        cout << "Введіть кількість секунд:" << endl;
        cin >> input;
        if (input < 0) {
            cout << "Введіть додатнє число!";
            RemSec();
        }
        sec -= input;
        while (sec < 0) {
            min--;
            sec += 60;
        }
        if (min < 0) {
            min = 0;
            sec = 0;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Time interval;
    while (true)
    {
        cout << "Додати чи відняти секунди до інтервалу?(напишіть будь-що інше щоб вийти)" << endl;
        string answer;
        cin >> answer;
        if (answer == "додати") {
            interval.AddSec();
        }
        else if (answer == "відняти") {
            interval.RemSec();
        }
        else {
            break;
        }

        std::cout << "\nІнтервал: " << interval.min << ":" << (interval.sec < 10 ? "0":"") << interval.sec << endl;
    }
    std::cout << "Кінцевий інтервал: " << interval.min << ":" << (interval.sec < 10 ? "0" : "") << interval.sec << endl;
    getchar();
    getchar();
}
