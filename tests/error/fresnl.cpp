#include <xtest.hpp>
#include <cephes/error.h>


TEST(Fresnel, Branches) {
    double x, s, c;

    EXPECT_REL_NEAR_F64(cephes::fresnl(1.0, &s, &c), 0.0);
}
