#include <iostream>
#include <iomanip>

using namespace std;

const double COMMISSION_RATE = 0.05; // �������� ����� 

int main()
{
    setlocale(LC_ALL, "ru");
    const string currencies[] = { "������", "����", "����", "�����", "����" };
    const double exchange_rates[] = { 75.0, 90.0, 10.0, 2.0, 0.6 }; // ��������� �����

    double rubles, amount_to_exchange, converted_amount;
    int choice;

    do {
        cout << "������� ����� � ������: ";
        cin >> rubles;

        cout << "�������� ������ ��� ������:\n";
        for (int i = 0; i < sizeof(currencies) / sizeof(currencies[0]); ++i) {
            cout << i + 1 << ". " << currencies[i] << endl;
        }

        cout << "��� �����: ";
        cin >> choice;

        if (choice >= 1 && choice <= sizeof(currencies) / sizeof(currencies[0])) {
            amount_to_exchange = rubles * (1 - COMMISSION_RATE); // ����� ����� ��������� ��������
            converted_amount = amount_to_exchange / exchange_rates[choice - 1];

            cout << "�� ������ ������ " << fixed << setprecision(2) << converted_amount << " " << currencies[choice - 1] << endl;
            cout << "�������� �����: " << fixed << setprecision(2) << rubles * COMMISSION_RATE << " ������" << endl;
        }
        else {
            cout << "������������ ����� ������." << endl;
        }

        cout << "��������� �����? (1 - ��, 0 - ���): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}