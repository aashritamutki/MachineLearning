//
// Created by Ashrita on 06-Nov-21.
//

#ifndef ML_MULTIPLE_REGRESSION_MATRIX_H
#define ML_MULTIPLE_REGRESSION_MATRIX_H

#include<iostream>
#include<vector>
#include "Eigen/Dense"

using std::vector;

class matrix
{
    private:

        friend class Multiple_regression;

        friend class Dataset;

    public :

        vector<vector<double>> mat;

        //size of matrix

        size_t row() const
        {
            return mat.size();
        }

        size_t column() const
        {
            return mat[0].size();
        }

        std::string dimensions() const
        {
            return (std::to_string(row()) + " X " + std::to_string(column()));
        }

        void resize(size_t r, size_t c)
        {
            mat.resize(r);

            for(int i = 0; i < mat.size(); i++)
            {
                mat[i].resize(c);
            }
        }

        void resize(size_t r, size_t c, double value)
        {
            resize(r, c);

            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    mat[i][j] = value;
                }
            }
        }

        //constructors

        matrix() = default;

        matrix(size_t r, size_t c)
        {
            size_t row = r;
            size_t column = c;
            mat.resize(row);
            for(int i = 0; i < mat.size(); i++)
            {
                mat[i].resize(column);
            }
        }

        matrix(size_t r, size_t c, double value) : matrix(r, c)
        {
            for(int i = 0; i < row(); i++)
            {
                for(int j = 0; j < column(); j++)
                {
                    mat[i][j] = value;
                }
            }
        }

        //operator overloading

        std::vector<double> &operator [](int i)
        {
            return static_cast<vector<double> &>(mat[i]);
        }

         std::vector<double> &operator [](int i) const
        {
            return const_cast<vector<double> &>(mat[i]);
        }

        friend std::istream& operator >> (std::istream& input, matrix &X)
        {
            for(size_t i = 0; i < X.row(); i++)
            {
                for(size_t j = 0; j  < X.column(); j++)
                {
                    input>>X.mat[i][j];
                }
            }
            return input;
        }

        friend std::ostream& operator << (std::ostream& output, matrix &X)
        {
            for(size_t i = 0; i < X.row(); i++)
            {
                for(size_t j = 0; j  < X.column(); j++)
                {
                    output<<std::setprecision(10)<<X.mat[i][j]<<" ";
                }
                output<<"\n";
            }
            return output;
        }

        matrix &operator = (matrix const &X)
        {
            (*this).resize(X.row(), X.column());

            (*this).mat = X.mat;

            return *this;
        }

        friend matrix operator + (matrix const &X, matrix const &Y)
        {
            matrix Z(X.row(), X.column());

            if(X.row() == Y.row() && X.column() == Y.column())
            {
                for(int i = 0; i < X.row(); i++)
                {
                    for(int j = 0; j < X.column(); j++)
                    {
                        Z.mat[i][j] = X.mat[i][j] + Y.mat[i][j];
                    }
                }
            }
            return Z;
        }

        friend matrix operator * (matrix const &X, matrix const &Y)
        {
            matrix Z(X.row(), Y.column());

            if(X.column() == Y.row())
            {
                for(int i = 0; i < X.row(); i++)
                {
                    for(int j = 0; j < Y.column(); j++)
                    {
                        for(int k = 0; k < Y.row(); k++)
                        {
                            Z.mat[i][j] += (X.mat[i][k] * Y.mat[k][j]);
                        }
                    }
                }
            }
            else
            {
                std::cout<<"Multiplication is not possible.";
            }
            return Z;
        }

        friend matrix operator ^ (matrix const &X, int const power)
        {
            matrix Y(X.row(), X.column());

            if(power == -1)
            {
                Eigen::MatrixXd Z(X.row(), X.column());

                for(int i = 0; i < X.row(); i++)
                {
                    for(int j = 0; j < X.column(); j++)
                    {
                        Z(i, j) = X[i][j];
                    }
                }
               Z = Z.inverse();

                for(int i = 0; i < X.row(); i++)
                {
                    for(int j = 0; j < X.column(); j++)
                    {
                        Y.mat[i][j] = Z(i, j);
                    }
                }
            }
            else if(power > 1)
            {
                Y = X * X;

                for(int i = 2; i < power; i++)
                {
                    Y = X * X;
                }
            }
            return Y;
        }

        //functions
        matrix transpose()
        {
            matrix X(column(), row());

            for(int i = 0; i < X.row(); i++)
            {
                for(int j = 0; j < X.column(); j++){

                    X.mat[i][j] = mat[j][i];
                }
            }
            return X;
        }

        matrix inverse() const
        {
            return (operator ^(*this, -1));
        }
};

#endif //ML_MULTIPLE_REGRESSION_MATRIX_H