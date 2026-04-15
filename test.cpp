#include <vector>
#include <string>
#include "core_numeric.h"

using namespace std;

int main() {

    vector<int> v{1,2,3};
    core_numeric::sum(v); // OK

    vector<double> d{1.0,2.0,3.0};
    core_numeric::mean(d); // OK

    vector<string> s{"a","b","c"};

    return 0;
}