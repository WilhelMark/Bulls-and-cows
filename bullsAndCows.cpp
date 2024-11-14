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

    // Массив для отслеживания использованных цифр в загаданном числе
    bool usedInSecret[4] = {false, false, false, false};
    bool usedInGuess[4] = {false, false, false, false};

    // Подсчет быков и отметка использованных цифр
    for (int i = 0; i < 4; ++i) {
        if (secretNumber[i] == guessedNumber[i]) {
            bulls++; // Увеличиваем счетчик быков
            usedInSecret[i] = true; // Отмечаем, что эта цифра использована
            usedInGuess[i] = true;  // Отмечаем, что эта цифра использована
        }
    }

    // Подсчет коров
    for (int i = 0; i < 4; ++i) {
        if (!usedInGuess[i]) { // Если эта цифра не была использована как бык
            for (int j = 0; j < 4; ++j) {
                if (secretNumber[i] == guessedNumber[j] && !usedInSecret[j]) {
                    cows++; // Увеличиваем счетчик коров
                    usedInSecret[j] = true; // Отмечаем, что эта цифра использована в загаданном числе
                    break; // Прерываем внутренний цикл для предотвращения повторного учета одной и той же коровы
                }
            }
        }
    }

    // Выводим результат
    cout << "Быков: " << bulls << ", коров: " << cows << endl;

    return 0;
}
