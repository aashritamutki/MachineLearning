#include <iostream>
#include <vector>
#include "dataset.h"
#include "LRmodel.h"

using namespace std;

int main() {

    vector <double> x{1,2,3,4,5};
    vector <double> y{2,4,5,4,5};
/*
    Linear_regression demo_model_1(x, y);

    vector <double> y_predicted = demo_model_1.predict(x);

    for(int i = 0; i < y_predicted.size(); i++)
    {
        cout<<y_predicted[i]<<endl;
    }

    cout<<"\nslope : "<<demo_model_1.get_slope();
    cout<<"\nintercept : "<<demo_model_1.get_intercept();
    cout<<"\nR squared : "<<demo_model_1.get_R_squared()<<endl;
*/
    // using dataset

    Dataset d1("C:\\Users\\Ashrita\\CLionProjects\\ML_Linear_Regression\\Salary_Data.csv");

    d1.train_x("YearsExperience");

    d1.train_y("Salary");

    Linear_regression demo_model_2(d1);
\\+++++++++++++++++++++++++++start here :
    std::cout<<"r2 score : "<<demo_model_2.get_R_squared();

    return 0;
}
