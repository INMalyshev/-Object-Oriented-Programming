#ifndef MY_VECTOR
#define MY_VECTOR

#define PI (acos(-1.0))
#define EPS 1e-6

typedef struct
{
    double x;
    double y;
    double z;
} vector_t;

void vector_pri(const vector_t &alpha);

void vector_add(const vector_t &alpha, const vector_t &betta, vector_t &dst);
void vector_sub(const vector_t &alpha, const vector_t &betta, vector_t &dst);
void vector_mul(const vector_t &alpha, const double &factor, vector_t &dst);
void vector_scl(const vector_t &alpha, const vector_t &relevant, const double &factor, vector_t &dst);
void vector_rot(const vector_t &alpha, const vector_t &relevant, const double &rel_x, const double &rel_y, const double &rel_z, vector_t &dst);
void vector_prj(const vector_t &alpha, const double &rel_x, const double &rel_y, const double &rel_z, vector_t &dst);

#endif
