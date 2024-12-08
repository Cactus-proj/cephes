#include <xtest.hpp>
#include <cephes/bessel.h>


TEST(BesselI0, Branches) {
    EXPECT_REL_NEAR_F64(cephes::i0(0.0), 1.0);

    // x < 0
    EXPECT_REL_NEAR_F64(cephes::i0(-0.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::i0(-10.0), 2815.716628466253);

    // x <= 8.0
    EXPECT_REL_NEAR_F64(cephes::i0(1.0), 1.266065877752008);
    EXPECT_REL_NEAR_F64(cephes::i0(8.0), 427.5641157218048);

    // x > 8.0
    EXPECT_REL_NEAR_F64(cephes::i0(9.0),  1093.588354511374);
    EXPECT_REL_NEAR_F64(cephes::i0(10.0), 1.266065877752008);
    EXPECT_REL_NEAR_F64(cephes::i0(100.0), 1.073751707131074e42);
}
