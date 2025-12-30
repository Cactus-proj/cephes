#include <cephes/misc.h>
#include <xtest.hpp>
#include <cmath>

TEST(PlanckC, Basic) {
    double T = 1000.0;
    double w = 1.0e-6;
    double y = cephes::planckc(w, T);
    EXPECT_GT(y, 0.0);
}
