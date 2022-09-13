//
// Created by Ashrita on 01-Nov-21.
//

#ifndef ML_LINEAR_REGRESSION_LRMODEL_H
#define ML_LINEAR_REGRESSION_LRMODEL_H

#endif //ML_LINEAR_REGRESSION_LRMODEL_H

#include<stdio.h>
#include<vector>
#include<math.h>

using std::vector;

class Linear_regression
{
    private :

        vector <double> x_train, y_train;

        // equation :  y = b0 + b1x

        double b0;         // intercept

        double b1;         // slope

        double R_squared;  // r2 score

        double x_mean, y_mean;

        double x_diff = 0, y_diff = 0, xy_diff = 0;

        double x_diff_sq = 0, y_diff_sq = 0, y_predicted_diff_sq = 0;

        void get_pre_values();

        void find_b0_b1();

        void get_xm_ym();

        void find_R_squared();

        Dataset ds;


    public :

        void train_model(vector<double> x, vector<double> y);

        vector <double> predict(vector <double> x_test);

        double get_slope();

        double get_intercept();

        double get_R_squared();

        static double get_mean(vector<double> v)
        {
            double result;

            for(int i = 0; i < v.size(); i++)
            {
                result += v[i];
            }

            result /= v.size();

            return result;
        }

        /*
        Linear_regression(std::vector<double> x, std::vector<double> y)
        {
            train_model(x, y);
        }
*/
        Linear_regression(Dataset ds) : ds(std::move(ds))
        {
            fit();
        }

        void fit()
        {
            std::vector<double> x;
            std::vector<double> y;

            x.resize(ds.X_train.size());
            y.resize(ds.y_train.size());

            for(int i = 0; i < x.size(); i++)
            {
                x[i] = ds.X_train[i][0];
                y[i] = ds.y_train[i];
            }

            train_model(x,y);
        }

};

void Linear_regression::train_model(vector<double> x, vector<double> y)
{
    x_train = x;
    y_train = y;

    get_xm_ym();
    get_pre_values();
    find_b0_b1();
    find_R_squared();
}

void Linear_regression::get_xm_ym()
{
    x_mean = get_mean(x_train);

    y_mean = get_mean(y_train);

}

void Linear_regression::find_b0_b1()
{
    b1 = xy_diff / x_diff_sq;

    b0 = y_mean - b1 * x_mean;
}

vector<double> Linear_regression::predict(vector<double> x_test)
{
    vector<double> y_target(x_test.size());
    for(int i = 0; i < x_test.size(); i++)
    {
        y_target[i] = b0 + b1 * x_test[i];
    }
    return y_target;
}

void Linear_regression::get_pre_values()
{
    for(int i = 0; i < x_train.size(); i++)
    {
        double x = x_train[i] - x_mean;

        double y = y_train[i] - y_mean;

        x_diff += x;

        y_diff += y;

        x_diff_sq += (pow(x, 2));

        y_diff_sq += (pow(y, 2));

        xy_diff += (x * y);

        vector<double> y_predicted = predict(x_train);

    }
}

void Linear_regression::find_R_squared()
{
    vector<double> y_predicted(x_train.size());

    y_predicted = predict(x_train);

    for(int i = 0; i < y_predicted.size(); i++)
    {
        y_predicted_diff_sq += pow((y_predicted[i] - y_mean), 2);
    }

    R_squared = y_predicted_diff_sq / y_diff_sq;
}

double Linear_regression::get_R_squared()
{
    return R_squared;
}

double Linear_regression::get_slope()
{
    return b1;
}

double Linear_regression::get_intercept()
{
    return b0;
}