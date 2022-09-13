//
// Created by Ashrita on 22-Nov-21.
//

#ifndef ML_MULTIPLE_REGRESSION_DATASET_H
#define ML_MULTIPLE_REGRESSION_DATASET_H

#include<iostream>
#include<vector>
#include<iomanip>
#include<initializer_list>
#include "rapidcsv.h"
#include "Matrix.h"

using std::vector;

class Dataset
{
    private :

        std::string filepath;

        std::vector<std::vector<double>> X_train;

        std::vector<double> y_train;

        std::vector<std::string> X_headers;

        std::string y_header;

        friend class Multiple_regression;

    public :

        explicit Dataset(const std::string &fp)
        {
            (*this).filepath = fp;
        }

    template<typename... Args>
        void train_x(Args... args)
        {
            rapidcsv::Document doc(filepath);

            X_headers = {args...};

            X_train.resize(X_headers.size());

            for(int i = 0; i < X_train.size(); i++)
            {
                X_train[i] = doc.GetColumn<double>(X_headers[i]);
            }
        }

        void train_y(const std::string &y)
        {
            rapidcsv::Document doc(filepath);

            y_header = y;

            y_train = doc.GetColumn<double>(y_header);
        }

        void get_column_names()
        {
            std::cout<<"\n\n";

            for(int i = 0; i < X_headers.size(); i++)
            {
                std::cout<<X_headers[i]<<" ";
            }
            std::cout<<y_header<<std::endl;
        }

        void head()
        {
            std::cout<<"\n\n";

            for(int i = 0; i < ((X_train.size() > 5) ? 5 : (X_train.size())); i++)
            {
                for(int j = 0; j < X_headers.size(); j++)
                {
                    std::cout<<std::setprecision(5)<<X_train[i][j]<<" ";
                }
                std::cout<<y_train[i]<<std::endl;
            }
        }

        void head(size_t rows)
        {
            std::cout<<"\n\n";

            for(size_t i = 0; i < ((X_train.size() > rows) ? rows : (X_train.size())); i++)
            {
                for(int j = 0; j < X_headers.size(); j++)
                {
                    std::cout<<std::setprecision(5)<<X_train[i][j]<<" ";
                }
                std::cout<<y_train[i]<<std::endl;
            }
        }

        void tail()
        {
            std::cout<<"\n\n";

            for(size_t i = ((X_train.size() > 5) ? (X_train.size() - 5) : X_train.size()); i < (X_train.size()); i++)
            {
                for(int j = 0; j < X_headers.size(); j++)
                {
                    std::cout<<std::setprecision(5)<<X_train[i][j]<<" ";
                }
                std::cout<<y_train[i]<<std::endl;
            }
        }

        void tail(size_t rows)
        {
            std::cout<<"\n\n";

            for(size_t i = ((X_train.size() > rows) ? (X_train.size() - rows) : X_train.size()); i < (X_train.size()); i++)
            {
                for(int j = 0; j < X_headers.size(); j++)
                {
                    std::cout<<std::setprecision(5)<<X_train[i][j]<<" ";
                }
                std::cout<<y_train[i]<<std::endl;
            }
        }
};


#endif //ML_MULTIPLE_REGRESSION_DATASET_H
