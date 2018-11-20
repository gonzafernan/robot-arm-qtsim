#include "m_function.h"

double m_sin(double value){
    return sin(value * M_PI / 180);
}

double m_cos(double value){
    return cos(value * M_PI / 180);
}

int RadtoDegree(float value){
    int ans = static_cast<int>(static_cast<double>(value * 180) / M_PI);
    return ans;
}
