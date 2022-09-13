#include <iostream>
#include "Gradient_Descent.h"
#include "Ggradient_Descent_2.h"
#include <vector>

int main()
{
    std::vector<double> x{1,2,3,4,5};
    std::vector<double> y{2,4,5,4,5};

    GD_regression demo_model_1(x, y, 0.1, 100);

    demo_model_1.fit();

    GD_regression_2 demo_model_2(x, y, 0.0001, 100000);

    demo_model_2.fit();

    std::vector<double> y_predicted = demo_model_2.predict(x);

    std::cout<<"\n "<<y_predicted;

    return 0;
}
