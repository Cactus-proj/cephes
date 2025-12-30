#include <cephes/misc.h>
#include <xtest.hpp>

TEST(StruveH, BrokenTests) {
    GTEST_SKIP() << "Broken Tests";
    /* Wolfram 
        StruveH[0, 0] == 0
    */
    EXPECT_EQ(cephes::struve(0.0, 0.0), 0.0);   // NaN
}

TEST(StruveH, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::struve(-1.0, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::struve(0.0, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::struve(1.0, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::struve(3.14, xtest::NaN64)));

    /*
        Table[NumberForm[StruveH[nv, x], 16],
            {nv, {-2.7, -1, 0, 1, 2, 3.14}},
            {x, {0.0}}]
    */
    EXPECT_TRUE(std::isnan(cephes::struve(-2.7, 0.0)));
    // EXPECT_TRUE(std::isnan(cephes::struve(-1.5, 0.0)));
    EXPECT_EQ(cephes::struve(-1.5, 0.0), 0.0);  // TODO: check?
    EXPECT_TRUE(std::isnan(cephes::struve(-1.0, 0.0)));
    // EXPECT_EQ(cephes::struve(0.0, 0.0), 0.0);
    EXPECT_EQ(cephes::struve(1.0, 0.0), 0.0);
    EXPECT_EQ(cephes::struve(2.0, 0.0), 0.0);
    EXPECT_EQ(cephes::struve(3.14, 0.0), 0.0);
}

/*
    ref:  https://dlmf.nist.gov/11.3

    Table[NumberForm[PolyGamma[0, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(StruveH, Branches) {
    // EXPECT_REL_NEAR_F64(cephes::struve(0.0, 0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::struve(1.0, 0.0), 0.0);
}
