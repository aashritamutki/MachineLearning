//
// Created by Ashrita on 20-Nov-21.
//

#ifndef ML_MULTIPLE_REGRESSION_MRMODEL_H
#define ML_MULTIPLE_REGRESSION_MRMODEL_H

#endif //ML_MULTIPLE_REGRESSION_MRMODEL_H

//start multiple regression from scratch

#include <iostream>
#include "Matrix.h"

class Multiple_regression
{
    private :

        matrix X_train, y_train;

        matrix coeff;

        matrix betas;

        double intercept;

        double y_mean = 0;

        double r_squared;

        Dataset ds;


    public :

        void set_y_mean()
        {
            int i;

            for(i = 0; i < y_train.row(); i++)
            {
                y_mean += y_train.mat[i][0];
            }

            y_mean /= i;
        }

        double get_y_mean()
        {
            return y_mean;
        }

        void get_coeff()
        {
            std::cout<<coeff;
        }

        matrix get_betas()
        {
            return betas;
        }

        double get_intercept()
        {
            return intercept;
        }

        double get_r_squared()
        {
            std::vector<std::vector<double>> X;

            X.resize(X_train.row());

            for(int i = 0; i < X_train.row(); i++)
            {
                X[i].resize(X_train.column());

                for(int j = 0; j < X_train.column(); j++)
                {
                    X[i][j] = X_train.mat[i][j];
                }
            }
            double y_original_diff_sq = 0;

            double y_predicted_diff_sq = 0;

            for(int i = 0; i < X_train.row(); i++)
            {
                y_original_diff_sq += (pow((y_train[i][0] - y_mean), 2));

                std::vector<double> y_predicted_col(X_train[i].begin()+1, X_train[i].end());

                y_predicted_diff_sq += pow(predict(y_predicted_col) - y_mean, 2);
            }

            r_squared = y_predicted_diff_sq / y_original_diff_sq;

            return r_squared;
        }

        void fit()
        {
            X_train.resize(ds.X_train.size() + 1, ds.X_train[0].size());

            y_train.resize(1, ds.y_train.size());

            for(int i = 0; i < X_train.column(); i++)
            {
                X_train[0][i] = 1;
            }

            for(int i = 1; i < X_train.row(); i++)
            {
                for(int j = 0; j < X_train.column(); j++)
                {
                    X_train.mat[i][j] = ds.X_train[i-1][j];
                }
            }

            for(int j = 0; j < y_train.column(); j++)
            {
                y_train.mat[0][j] = ds.y_train[j];
            }

            X_train = X_train.transpose();

            y_train = y_train.transpose();

            // calculating coefficients

            betas = ( (X_train.transpose() * X_train) ^ -1 ) * X_train.transpose() * y_train;

            intercept = betas.mat[0][0];

            coeff.resize(betas.row() - 1, 1);

            for(int i = 1; i < betas.row(); i++)
            {
                coeff.mat[i-1][0] = betas.mat[i][0];
            }
        }

        double predict(std::vector<double> X_test)
        {
            matrix y;

            y.resize(1, coeff.row());

            for(int i = 0; i < y.row(); i++)
            {
                y[0][i] = X_test[i];
            }

            y = y * coeff;

            y[0][0] += intercept;

            return y[0][0];
        }

        Multiple_regression(Dataset ds) : ds(std::move(ds))
        {
            fit();
        }


};