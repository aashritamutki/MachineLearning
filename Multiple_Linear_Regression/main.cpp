#include <iostream>
#include "dataset.h"
#include "MRmodel.h"

int main()
{

    //Dataset d1("C:\\Users\\Ashrita\\CLionProjects\\ML_Multiple_Regression\\Startups.csv");

    //d1.train_x("R&D Spend", "Administration", "Marketing Spend");

    //d1.train_y("Profit");

    Dataset d1("C:\\Users\\Ashrita\\CLionProjects\\ML_Multiple_Regression\\CROPNUM.csv");

    d1.train_x("N", "P", "K", "TEMPERATURE", "RAINFALL", "WATER REQUIREMENT");
    //76,57,18,18.9802729,94.26249353,CORN,DRY,DESERT,3.6
    d1.train_y("CROP NUMBER");

    Multiple_regression model_1(d1);

    //std::cout<<"\ncoefficients : ";
    //model_1.get_coeff();
    //std::cout<<"\nintercept : " << model_1.get_intercept();
    std::cout<<"\nR2 score : " << model_1.get_r_squared();

    std::vector<double> X_test_1 = {75, 55, 15, 15.22, 92, 4};

    double y_predicted_1 = model_1.predict(X_test_1);

    //std::cout <<"\nProfit : "<< y_predicted_1;

    std::cout <<"\nCROP : "<< y_predicted_1;

     return 0;
}

