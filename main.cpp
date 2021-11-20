#include <iostream>
#include<vector>
#include"LRmodel.h"

using namespace std;

int main() {

    Linear_regression demo_model_1;

    vector <double> x{1,2,3,4,5};
    vector <double> y{2,4,5,4,5};

    demo_model_1.train_model(x, y);

    cout<<demo_model_1.x_mean<<endl;
    cout<<demo_model_1.y_mean<<endl;
    cout<<demo_model_1.b0<<endl;
    cout<<demo_model_1.b1<<endl;


    vector <double> y_predicted = demo_model_1.predict(x);

    for(int i = 0; i < y_predicted.size(); i++)
    {
        cout<<y_predicted[i]<<endl;
    }

    cout<<"R squared : "<<demo_model_1.R_squared<<endl;

    return 0;
}
