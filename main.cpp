#include <iostream>
#include <vector>
#include "core_numeric.h"

using namespace std;

int main() {

    vector<double> v{1.0,2.0,3.0};

    cout << core_numeric::sum(v) << endl;
    cout << core_numeric::mean(v) << endl;
    cout << core_numeric::variance(v) << endl;
    cout << core_numeric::max(v) << endl;

    auto r = core_numeric::transform_reduce(v, [](double x){
        return x * x;
    });

    cout << r << endl;

    cout << core_numeric::sum_variadic(1,2,3,4) << endl;
    cout << core_numeric::mean_variadic(1.0,2.0,3.0,4.0) << endl;
    cout << core_numeric::variance_variadic(1.0,2.0,3.0,4.0) << endl;
    cout << core_numeric::max_variadic(1.0,2.7,3.0,4.0) << endl;

    return 0;
}