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

void vector_sub(const vector_t &alpha, const vector_t &betta, vector_t &dst)
{
    dst.x = alpha.x - betta.x;
    dst.y = alpha.y - betta.y;
    dst.z = alpha.z - betta.z;
}

void vector_mul(const vector_t &alpha, const double &factor, vector_t &dst)
{
    dst.x = alpha.x * factor;
    dst.y = alpha.y * factor;
    dst.z = alpha.z * factor;
}

void vector_scl(const vector_t &alpha, const vector_t &relevant, const double &factor, vector_t &dst)
{
    vector_t rel_zero, scaled_rel_zero;
    vector_sub(alpha, relevant, rel_zero);
    vector_mul(rel_zero, factor, scaled_rel_zero);
    vector_add(scaled_rel_zero, relevant, dst);
}

void vector_rot(const vector_t &alpha, const vector_t &relevant, const double &rel_x, const double &rel_y, const double &rel_z, vector_t &dst)
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

    vector_t rel_zero, rotated_rel_zero;

    vector_sub(alpha, relevant, rel_zero);

    rotated_rel_zero.x = k_0_0 * rel_zero.x + k_0_1 * rel_zero.y + k_0_2 * rel_zero.z;
    rotated_rel_zero.y = k_1_0 * rel_zero.x + k_1_1 * rel_zero.y + k_1_2 * rel_zero.z;
    rotated_rel_zero.z = k_2_0 * rel_zero.x + k_2_1 * rel_zero.y + k_2_2 * rel_zero.z;

    vector_add(rotated_rel_zero, relevant, dst);
}

void vector_prj(const vector_t &alpha, const double &rel_x, const double &rel_y, const double &rel_z, vector_t &dst)
{
    double dx = PI / 2.0 - rel_x;
    double dy = PI / 2.0 - rel_y;
    double dz = PI - rel_z;

    vector_t rotated_vector, zero = {0.0, 0.0, 0.0};
    vector_rot(alpha,  zero, dx, dy, dz, rotated_vector);

    dst.x = rotated_vector.x;
    dst.y = rotated_vector.y;
    dst.z = 0.0;
}
