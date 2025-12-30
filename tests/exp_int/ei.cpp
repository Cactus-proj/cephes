#include <cephes/exp_int.h>
#include <xtest.hpp>

TEST(Ei, BrokenTests) {
    EXPECT_EQ(cephes::ei(0.0), 0.0);
    EXPECT_TRUE(std::isnan(cephes::ei(xtest::Inf64)));

    GTEST_SKIP() << "Broken Tests";
    /* Wolfram
        ExpIntegralEi[0.0] == -Infinity
        ExpIntegralEi[Infinity] == Infinity
    */
    EXPECT_LE(cephes::ei(0.0), -1e300);
    EXPECT_EQ(cephes::ei(xtest::Inf64), xtest::Inf64);
}

TEST(Ei, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::ei(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::ei(-xtest::NaN64)));

    // EXPECT_LE(cephes::ei(0.0), -1e300);  // 0.0
    EXPECT_EQ(cephes::ei(-xtest::Inf64), 0.0);
    // EXPECT_EQ(cephes::ei(xtest::Inf64), xtest::Inf64);  // NaN
}

/*
In[]:= Table[NumberForm[ExpIntegralEi[x],16],
            {x, {
                0.5,1.0,3.9, 
                4.,7.9,     8.,15.9, 
                16.,31.9,   32.,63.9, 
                64.,128.}}]
Out[]= {
    0.4542199048631736, 1.895117816355937, 18.31571434644304,
    19.63087447005622,404.7006958537439,
    440.3798995348382,542546.3392529309,
    595560.998670837,2.314859549217819*10^(12),
    2.550043566357785*10^(12),8.9718140679545*10^(25),
    9.89964092597445*10^(25),3.061380614342895*10^(53)}
*/
TEST(Ei, Branches) {
    // x <= 0.0
    EXPECT_EQ(cephes::ei(-314.), 0.0);
    EXPECT_EQ(cephes::ei(-1.0), 0.0);
    EXPECT_EQ(cephes::ei(-0.1), 0.0);
    // if (x < 4.0)
    EXPECT_REL_NEAR_F64(cephes::ei(0.5), 0.4542199048631736);
    EXPECT_REL_NEAR_F64(cephes::ei(1.0), 1.895117816355937);
    EXPECT_REL_NEAR_F64(cephes::ei(3.9), 18.31571434644304);
    // if (x < 8.0) 
    EXPECT_REL_NEAR_F64(cephes::ei(4.0), 19.63087447005622);
    EXPECT_REL_NEAR_F64(cephes::ei(7.9), 404.7006958537439);
    // if (x < 16.0)
    EXPECT_REL_NEAR_F64(cephes::ei(8.0), 440.3798995348382);
    EXPECT_REL_NEAR_F64(cephes::ei(15.9), 542546.3392529309);
    // if (x < 32.0)
    EXPECT_REL_NEAR_F64(cephes::ei(16.0), 595560.998670837);
    EXPECT_REL_NEAR_F64(cephes::ei(31.9), 2.314859549217819e12);
    // if (x < 64.0)
    EXPECT_REL_NEAR_F64(cephes::ei(32.0), 2.550043566357785e12);
    EXPECT_REL_NEAR_F64(cephes::ei(63.9), 8.9718140679545e25);
    // else : x >= 64
    EXPECT_REL_NEAR_F64(cephes::ei(64.0), 9.89964092597445e25);
    EXPECT_REL_NEAR_F64(cephes::ei(128.0), 3.061380614342895e53);
}
