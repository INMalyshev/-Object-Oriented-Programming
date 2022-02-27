#include <iostream>
#include <cmath>

#include "../inc/vector.h"

#define PI (acos(-1.0))
#define EPS 1e-6

int main() {
    using namespace std;
    cout << "Hello, World!" << endl;

    vector_t a = {1, 2, 3};
    vector_t b = {3, 2, 1};

    vector_t op_01, op_02;

    vector_add(a, b, op_01);
    vector_mul(a, 3, op_02);

    vector_pri(a);
    vector_pri(op_01);
    vector_pri(op_02);

    cout << PI << endl;

    vector_t op_03,  c = {1, 1, 0};
    vector_pri(c);
    vector_rot(c, PI/2, 0, 0, op_03);
    vector_pri(op_03);

    return 0;
}
