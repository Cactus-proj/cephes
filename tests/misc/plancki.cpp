#include <cephes/misc.h>
#include <xtest.hpp>
#include <cmath>

TEST(PlanckInt, Basic) {
    double T = 1000.0;
    double w = 1.0e-6; // 1 micron
    double y = cephes::plancki(w, T);
    // Expected value is positive
    EXPECT_GT(y, 0.0);
}
