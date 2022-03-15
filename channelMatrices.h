#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "matrix/matrix.h"

typedef matrix::Matrix<double> matrixT;

typedef std::vector<double> vectorT;


/* Возвращает канальную матрицу P(A;B) восстановленную по канальной матрице
 * источника source - P(A/B) и вектору pb - p(b) */
matrixT getChannelBySource(const matrixT &source, const vectorT &pb);

/* Возвращает канальную матрицу P(A;B) восстановленную по канальной матрице
 * приемника receiver - P(B/A) и вектору pa - p(a) */
matrixT getChannelByReceiver(const matrixT &receiver, const vectorT & pa);

/* Возвращает канальную матрицу источника - P(A/B), восстановленную по
 * канальной матрице channel - P(A;B) и вектору pb - p(b) */
matrixT getSource(const matrixT &channel, const vectorT &pb);

/* Возвращает канальную матрицу источника - P(B/A), восстановленную по
 * канальной матрице channel - P(A;B) и вектору pa - p(a) */
matrixT getReceiver(const matrixT &channel, const vectorT &pa);

// Возвращает массив сумм элементов каждой стороки матрицы a
vectorT getRowSumsVector(const matrixT & a);

// Возвращает массив сумм элементов каждого столбца матрицы a
vectorT getColSumsVector(const matrixT & a);

// Выводит вектор v на экран
void printVector(const vectorT &v);

// Считывает вектор v c клавиатуры
void inputVector(vectorT &v);

// Возвращает энтропию случайного вектора p - H(p)
double getH(const vectorT &p);

// Возвращает энтропию канальной матрица channel - P(A;B)
double getH(matrixT &channel);

