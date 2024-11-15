#include <iostream>
#include <iomanip>

using namespace std;

const double COMMISSION_RATE = 0.05; // Комиссия банка 

int main()
{
    setlocale(LC_ALL, "ru");
    const string currencies[] = { "Доллар", "Евро", "Юань", "Фарит", "Йена" };
    const double exchange_rates[] = { 75.0, 90.0, 10.0, 2.0, 0.6 }; // Примерные курсы

    double rubles, amount_to_exchange, converted_amount;
    int choice;

    do {
        cout << "Введите сумму в рублях: ";
        cin >> rubles;

        cout << "Выберите валюту для обмена:\n";
        for (int i = 0; i < sizeof(currencies) / sizeof(currencies[0]); ++i) {
            cout << i + 1 << ". " << currencies[i] << endl;
        }

        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice >= 1 && choice <= sizeof(currencies) / sizeof(currencies[0])) {
            amount_to_exchange = rubles * (1 - COMMISSION_RATE); // Сумма после удержания комиссии
            converted_amount = amount_to_exchange / exchange_rates[choice - 1];

            cout << "Вы можете купить " << fixed << setprecision(2) << converted_amount << " " << currencies[choice - 1] << endl;
            cout << "Комиссия банка: " << fixed << setprecision(2) << rubles * COMMISSION_RATE << " рублей" << endl;
        }
        else {
            cout << "Некорректный выбор валюты." << endl;
        }

        cout << "Повторить обмен? (1 - да, 0 - нет): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}