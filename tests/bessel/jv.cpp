#include <cephes/bessel.h>
#include <xtest.hpp>

/** Wolframe
    Table[NumberForm[BesselJ[nv + 1/4., x], 16],
        {nv, {0, 5, 10, 50, 100}},
        {x, {1, 50}}]
*/
TEST(BesselJv, CoSF_Table_5p13) {
    double nv, x;

    nv = 1 / 4;
    x = 1.0;
    // TODO: large error
    // EXPECT_REL_NEAR_F64(cephes::jv(0+nv, x),    0.7522313333407901);
    // EXPECT_REL_NEAR_F64(cephes::jv(5+nv, x),    0.0001365611922260019);
    // EXPECT_REL_NEAR_F64(cephes::jv(10+nv, x),   1.225744639746669e-10);
    // EXPECT_REL_NEAR_F64(cephes::jv(50+nv, x),   9.1612835058319e-81);
    // EXPECT_REL_NEAR_F64(cephes::jv(100+nv, x),  2.238669811158841e-189);

    // nv = 1/4;
    // x = 50.0;
    // EXPECT_REL_NEAR_F64(cephes::jv(0+nv, x),    0.01410606268088954);
    // EXPECT_REL_NEAR_F64(cephes::jv(5+nv, x),   -0.1041926237944591);
    // EXPECT_REL_NEAR_F64(cephes::jv(10+nv, x),  -0.1054019881703558);
    // EXPECT_REL_NEAR_F64(cephes::jv(50+nv, x),   0.1137789059221363);
    // EXPECT_REL_NEAR_F64(cephes::jv(100+nv, x),  8.01262704186791e-22);
}
/** Wolframe
    Table[NumberForm[BesselJ[nv + 3/4., x], 16],
        {nv, {0, 5, 10, 50, 100}},
        {x, {1, 50}}]
*/
TEST(BesselJv, CoSF_Table_5p17) {
    double nv, x;

    nv = 3 / 4;
    x = 1.0;
    // TODO: large error
    // EXPECT_REL_NEAR_F64(cephes::jv(0+nv, x),    0.5586524932048919);
    // EXPECT_REL_NEAR_F64(cephes::jv(5+nv, x),    0.00003952258729143145);
    // EXPECT_REL_NEAR_F64(cephes::jv(10+nv, x),   2.615437708142973e-11);
    // EXPECT_REL_NEAR_F64(cephes::jv(50+nv, x),   9.07139545679838e-82);
    // EXPECT_REL_NEAR_F64(cephes::jv(100+nv, x),  1.575139282276652e-190);

    // nv = 3/4;
    // x = 50.0;
    // EXPECT_REL_NEAR_F64(cephes::jv(0+nv, x),   -0.06874351931088636);
    // EXPECT_REL_NEAR_F64(cephes::jv(5+nv, x),   -0.1071110937351616);
    // EXPECT_REL_NEAR_F64(cephes::jv(10+nv, x),  -0.05465844413942518);
    // EXPECT_REL_NEAR_F64(cephes::jv(50+nv, x),   0.0988291994940441);
    // EXPECT_REL_NEAR_F64(cephes::jv(100+nv, x),  4.122166908740485e-22);
}
TEST(BesselJv, Branches) {
    // (x < 0.0) && (y != an)
    EXPECT_REL_NEAR_F64(cephes::jv(1.1, -1.0), 0.0);
}
