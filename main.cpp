#include <iostream>
#include <windows.h>
#include "channelMatrices.h"

using namespace std;

void getInfByReceiverCase() {
    size_t m, n;
    cout << "Введите размеры матрицы:";
    cin >> m >> n;

    matrixT receiver(m, n);
    cout << "Введите матрицу приемника - P(B/A):" << endl;
    cin >> receiver;

    vectorT pa(receiver.rows());
    cout << "Введите p(a):";
    inputVector(pa);

    auto channel = getChannelByReceiver(receiver, pa);
    cout << "Канальная матрица P(A;B):" << endl << channel;

    auto pb = getColSumsVector(channel);
    cout << "p(b): ";
    printVector(pb);

    auto source = getSource(channel, pb);
    cout << "Матрица источника - P(A/B):" << endl << source;

    double ha = getH(pa), hb = getH(pb);
    cout << "H(A) = " << ha << "; H(B) = " << hb << endl;

    double channelH = getH(channel);
    cout << "H(A;B) = " << channelH << endl;

    double receiverH = channelH - hb, sourceH = channelH - ha;
    cout << "H(A/B) = " << receiverH << "; H(B/A) = " << sourceH << endl;

    double j = ha - receiverH;
    cout << "~J(A;B) = " << j;
}

void getInfBySourceCase() {
    size_t m, n;
    cout << "Введите размеры матрицы:";
    cin >> m >> n;

    matrixT source(m, n);
    cout << "Введите матрицу источника - P(A/B):" << endl;
    cin >> source;

    vectorT pb(source.cols());
    cout << "Введите p(b):";
    inputVector(pb);

    auto channel = getChannelBySource(source, pb);
    cout << "Канальная матрица P(A;B):" << endl << channel;

    auto pa = getRowSumsVector(channel);
    cout << "p(a): ";
    printVector(pa);

    auto receiver = getReceiver(channel, pa);
    cout << "Матрица приемника - P(B/A):" << endl << receiver;

    double ha = getH(pa), hb = getH(pb);
    cout << "H(A) = " << ha << "; H(B) = " << hb << endl;

    double channelH = getH(channel);
    cout << "H(A;B) = " << channelH << endl;

    double receiverH = channelH - hb, sourceH = channelH - ha;
    cout << "H(A/B) = " << receiverH << "; H(B/A) = " << sourceH << endl;

    double j = ha - receiverH;
    cout << "~J(A;B) = " << j;
}

void getInfByChannelCase(){
    size_t m, n;
    cout << "Введите размеры матрицы:";
    cin >> m >> n;

    matrixT channel (m, n);
    cout << "Введите канальную матрицу - P(A;B):" << endl;
    cin >> channel;

    auto pa = getRowSumsVector(channel);
    auto pb = getColSumsVector(channel);

    cout << "p(a): ";
    printVector(pa);
    cout << "p(b): ";
    printVector(pb);

    auto source = getSource(channel, pb);
    cout << "Матрица источника - P(A/B):" << endl << source;

    auto receiver = getReceiver(channel, pa);
    cout << "Матрица приемника - P(B/A):" << endl << receiver;

    double ha = getH(pa), hb = getH(pb);
    cout << "H(A) = " << ha << "; H(B) = " << hb << endl;

    double channelH = getH(channel);
    cout << "H(A;B) = " << channelH << endl;

    double receiverH = channelH - hb, sourceH = channelH - ha;
    cout << "H(A/B) = " << receiverH << "; H(B/A) = " << sourceH << endl;

    double j = ha - receiverH;
    cout << "~J(A;B) = " << j;

}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Подключение русского языка

    cout << "Выберите случай ввода:" << endl
         << "1. Дана матрица источника P(A/B) и вектор p(b)." << endl
         << "2. Дана матрица приемника P(B/A) и вектор p(a)." << endl
         << "3. Дана канальная матрица P(A;B)" << endl
         << "Введите номер случая:";

    size_t caseNum;
    cin >> caseNum;

    switch (caseNum) {
        case 1:
            getInfBySourceCase();
            break;
        case 2:
            getInfByReceiverCase();
            break;
        case 3:
            getInfByChannelCase();
            break;
        default:
            cout << "Неверный номер случая! Попробуйте снова.";
    }
}

