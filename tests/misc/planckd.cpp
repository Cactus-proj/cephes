#include <cephes/misc.h>
#include <xtest.hpp>
#include <cmath>

TEST(PlanckD, Basic) {
    double T = 1000.0;
    double w = 2.898e-6; // Approx peak
    double y = cephes::planckd(w, T);
    EXPECT_GT(y, 0.0);
}
