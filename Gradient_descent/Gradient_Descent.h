//
// Created by Ashrita on 25-Nov-21.
//

#ifndef GRADIENT_DESCENT_GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_GRADIENT_DESCENT_H

#include<iostream>
#include<vector>
#include<math.h>

// Gradient descent - only 1 parameter i.e intercept(b)

class GD_regression
{
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

        GD_regression(std::vector<double> x, std::vector<double> y, double lr, int e)
        {
            (*this).x_train = x;

            (*this).y_train = y;

            (*this).learning_rate = lr;

            (*this).epoch = e;
        }

        // calculating the intercept using G

        void fit()
        {
            double loss_slope;

            calculate_slope();

            intercept = 0;                              // initial value

            for (int i = 0; i < epoch; i++)
            {
                loss_slope = -2 * summation();

                (*this).intercept = intercept - (learning_rate * loss_slope);
            }
            std::cout<<"\nintercept : "<<intercept;
        }
        
        double summation()
        {
            double result = 0;

            for (size_t i = 0; i < x_train.size(); i++)
            {
                result += y_train[i] - slope * x_train[i] - intercept;
            }
            return result;
        }

    double calculate_slope()
    {
        double x, y, x_diff_sq = 0, xy_diff = 0;

        double x_mean = get_mean(x_train);

        double y_mean = get_mean(y_train);

        for(int i = 0; i < x_train.size(); i++)
        {
            x = x_train[i] - x_mean;

            y = y_train[i] - y_mean;

            x_diff_sq += (pow(x, 2));

            xy_diff += (x * y);
        }
        (*this).slope = xy_diff / x_diff_sq;
    }

    double get_slope()
    {
        return slope;
    };

    static double get_mean(std::vector<double> v)
    {
        double result;

        for(int i = 0; i < v.size(); i++)
        {
            result += v[i];
        }

        result /= v.size();

        return result;
    }
};

#endif //GRADIENT_DESCENT_GRADIENT_DESCENT_H















