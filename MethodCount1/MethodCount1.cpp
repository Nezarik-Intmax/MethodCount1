#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

double a = 18;
double b = 0.3;
double e = M_E;
double c = 2.89;
double d = 0.28;

double f(double x, double y){
    std::cout << pow(e, c * x * x + d * y * y);
    return a*x + b*y + pow(e, c*x*x + d*y*y);
         //18*x1 + 0.3*x2 + e^(2.89*x1*x1 + 0.28*x2*x2)
}
double ff_x(double x, double y){
    return a + 2*c*x*pow(e, c*x*x + d*y*y);
}
double ff_y(double x, double y){
    return b + 2*d*y*pow(e, c*x*x + d*y*y);
}
double get_k_x(double x, double y, double alpha){
    return x - alpha * ff_x(x, y);
}
double get_k_y(double x, double y, double alpha){
    return y - alpha * ff_y(x, y);
}

int main()
{
    std::cout << "Hello World!\n";
    double x = 0;
    double old_x = 0;
    double y = 0;
    double old_y = 0;
    double alpha = 1;
    double min = f(x, y) + 1;
    while(true){
        double tmp = f(x, y);
        std::cout << "X: " << x << "; Y: " << y << "; F = " << tmp << "\n";
        if (tmp < min){
            old_x = x;
            old_y = y;
            min = tmp;
            x = get_k_x(old_x, old_y, alpha);
            y = get_k_y(old_x, old_y, alpha);
        }else if(tmp == min){
            break;
        }else{
            alpha /= 2;
            x = old_x;
            y = old_y;
        }
    }
}
