#include <iostream>
#include <string>

using namespace std;

int main() {
    string secretNumber; // Загаданное число
    string guessedNumber; // Число, названное вторым игроком

    // Считываем загаданное число
    cout << "Введите задуманное число (четыре цифры): ";
    cin >> secretNumber;

    // Проверяем, что загаданное число состоит из 4 цифр
    while (secretNumber.length() != 4) {
        cout << "Ошибка! Введите четырёхзначное число: ";
        cin >> secretNumber;
    }

    // Считываем число, названное вторым игроком
    cout << "Введите второе число (четыре цифры): ";
    cin >> guessedNumber;

    // Проверяем, что угаданное число состоит из 4 цифр
    while (guessedNumber.length() != 4) {
        cout << "Ошибка! Введите четырёхзначное число: ";
        cin >> guessedNumber;
    }

    int bulls = 0; // Количество быков
    int cows = 0;  // Количество коров

    // Подсчет быков
    for (int i = 0; i < 4; ++i) {
        if (secretNumber[i] == guessedNumber[i]) {
            bulls++; // Увеличиваем счетчик быков
        }
    }

    // Подсчет коров
    for (int i = 0; i < 4; ++i) {
        if (secretNumber[i] != guessedNumber[i]) { // Только если это не бык
            for (int j = 0; j < 4; ++j) {
                if (secretNumber[i] == guessedNumber[j] && secretNumber[j] != guessedNumber[j]) {
                    cows++; // Увеличиваем счетчик коров
                    break; // Прерываем внутренний цикл, чтобы не считать одну корову несколько раз
                }
            }
        }
    }

    // Выводим результат
    cout << "Быков: " << bulls << ", коров: " << cows << endl;

    return 0;
}
