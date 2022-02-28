#include <iostream>
#include <cmath>

#include "../inc/vector.h"

void vector_pri(const vector_t &alpha)
{
    using namespace std;

    cout << "(" << alpha.x << ", " << alpha.y << ", " << alpha.z << ")" << endl;
}

void vector_add(const vector_t &alpha, const vector_t &betta, vector_t &dst)
{
    dst.x = alpha.x + betta.x;
    dst.y = alpha.y + betta.y;
    dst.z = alpha.z + betta.z;
}

void vector_mul(const vector_t &alpha, const double &factor, vector_t &dst)
{
    dst.x = alpha.x * factor;
    dst.y = alpha.y * factor;
    dst.z = alpha.z * factor;
}

void vector_rot(const vector_t &alpha, const double &rel_x, const double &rel_y, const double &rel_z, vector_t &dst)
{
    double k_0_0 = cos(rel_y) * cos(rel_z);
    double k_0_1 = sin(rel_x) * sin(rel_y) * cos(rel_z) - cos(rel_x) * sin(rel_z);
    double k_0_2 = cos(rel_x) * sin(rel_y) * cos(rel_z) + sin(rel_x) * sin(rel_z);

    double k_1_0 = cos(rel_y) * sin(rel_z);
    double k_1_1 = sin(rel_x) * sin(rel_y) * sin(rel_z) + cos(rel_x) * cos(rel_z);
    double k_1_2 = cos(rel_x) * sin(rel_y) * sin(rel_z) - sin(rel_x) * cos(rel_z);

    double k_2_0 = -sin(rel_y);
    double k_2_1 = sin(rel_x) * cos(rel_y);
    double k_2_2 = cos(rel_x) * cos(rel_y);

    dst.x = k_0_0 * alpha.x + k_0_1 * alpha.y + k_0_2 * alpha.z;
    dst.y = k_1_0 * alpha.x + k_1_1 * alpha.y + k_1_2 * alpha.z;
    dst.z = k_2_0 * alpha.x + k_2_1 * alpha.y + k_2_2 * alpha.z;
}

void vector_prj(const vector_t &alpha, const double &rel_x, const double &rel_y, const double &rel_z, vector_t &dst)
{
    double dx = PI / 2.0 - rel_x;
    double dy = PI / 2.0 - rel_y;
    double dz = PI - rel_z;

    vector_t rotated_vector;
    vector_rot(alpha, dx, dy, dz, rotated_vector);

    dst.x = rotated_vector.x;
    dst.y = rotated_vector.y;
    dst.z = 0.0;
}
