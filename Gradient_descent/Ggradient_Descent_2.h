//
// Created by Ashrita on 25-Nov-21.
//

#ifndef GRADIENT_DESCENT_GGRADIENT_DESCENT_2_H
#define GRADIENT_DESCENT_GGRADIENT_DESCENT_2_H

#include<iostream>
#include<vector>
#include<math.h>

// Gradient descent - 2 parameters i.e intercept(b) and slope(m)

class GD_regression_2 {
private :

    std::vector<double> x_train, y_train;

    double learning_rate;

    double slope;

    int epoch;

    double intercept;

    //double r_squared;

    //Dataset ds;

public :

    //constructor

    GD_regression_2(std::vector<double> x, std::vector<double> y, double lr, int e)
    {
        (*this).x_train = x;

        (*this).y_train = y;

        (*this).learning_rate = lr;

        (*this).epoch = e;
    }

    // calculating the intercept using G

    void fit()
    {
        double loss_slope_m;

        double loss_slope_b;

        intercept = 0;                       //  initial value

        slope = 0;                          // initial value

        for (int i = 0; i < epoch; i++)
        {
            loss_slope_m = -2 * summation_m();

            loss_slope_b = -2 * summation_b();

            (*this).intercept = intercept - (learning_rate * loss_slope_b);

            (*this).slope = slope - (learning_rate * loss_slope_m);
        }
        std::cout << "\nintercept : " << intercept;

        std::cout << "\nslope : " << slope<<"  ";
    }

    double summation_b()
    {
        double result = 0;

        for (size_t i = 0; i < x_train.size(); i++)
        {
            result += y_train[i] - slope * x_train[i] - intercept;
        }
        return result;
    }

    double summation_m()
    {
        double result = 0;

        for (size_t i = 0; i < x_train.size(); i++)
        {
            result += (y_train[i] - slope * x_train[i] - intercept) * x_train[i];
        }
        return result;
    }

    std::vector<double> predict(std::vector<double> x_test)
    {
        std::vector<double> y_target(x_test.size());

        for(int i = 0; i < x_test.size(); i++)
        {
            y_target[i] = intercept + slope * x_test[i];
        }
        return y_target;
    }

};

#endif //GRADIENT_DESCENT_GGRADIENT_DESCENT_2_H
