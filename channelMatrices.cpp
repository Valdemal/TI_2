#include "channelMatrices.h"

matrixT getChannelBySource(const matrixT &source, const vectorT &pb) {
    matrixT channel (source.rows(), source.cols());

    for (size_t i = 0; i < channel.rows(); ++i)
        for (size_t j = 0; j < channel.cols(); ++j)
            channel[i][j] = source[i][j] * pb[j];

    return channel;
}

matrixT getChannelByReceiver(const matrixT &receiver, const vectorT & pa){
    matrixT channel (receiver.cols(), receiver.rows());

    for (size_t i = 0; i < channel.rows(); ++i)
        for (size_t j = 0; j < channel.cols(); ++j)
            channel[i][j] = receiver[i][j] * pa[i];

    return channel;
}

matrixT getSource(const matrixT &channel, const vectorT &pb){
    matrixT source (channel.rows(), channel.cols());

    for (size_t i = 0; i < channel.rows(); ++i)
        for (size_t j = 0; j < channel.cols(); ++j)
            source[i][j] = channel[i][j] / pb[j];

    return source;
}


matrixT getReceiver(const matrixT &channel, const vectorT &pa) {
    matrixT receiver (channel.rows(), channel.cols());

    for (size_t i = 0; i < channel.rows(); ++i)
        for (size_t j = 0; j < channel.cols(); ++j)
            receiver[i][j] = channel[i][j] / pa[i];

    return receiver;
}

double getH(const vectorT &p){
    double res = 0;

    for (auto &v : p)
        if (v != 0)
            res -= v * log2(v);

    return res;
}

double getH(matrixT &channel){
    double res = 0;

    for (size_t i = 0; i < channel.rows(); ++i) {
        res += getH(channel[i]);
    }

    return res;
}

void printVector(const vectorT &v){
    std::cout << "(";

    for (size_t i = 0; i < v.size() - 1; ++i) {
        std::cout << v[i] << ", ";
    }

    std::cout << v.back() << ")" << std::endl;
}

void inputVector(vectorT &v){
    for(auto & elem : v)
        std::cin >> elem;
}

vectorT getRowSumsVector(const matrixT & a){
    vectorT p (a.rows());

    for (size_t i = 0; i < a.rows(); ++i)
        for (size_t j = 0; j < a.cols(); ++j)
            p[i] += a[i][j];

    return p;
}

vectorT getColSumsVector(const matrixT & a){
    vectorT colsSumsVector (a.cols());

    for (size_t i = 0; i < a.rows(); ++i)
        for (size_t j = 0; j < a.cols(); ++j)
            colsSumsVector[j] += a[i][j];

    return colsSumsVector;
}
