#include <cephes/exp_int.h>
#include <xtest.hpp>

TEST(ExpN, Errors) {
    // n < 0
    EXPECT_TRUE(cephes::expn(-1, 10.0) > 1e308);
    // x < 0
    EXPECT_TRUE(cephes::expn(1, -1.0) > 1e308);
    // x > MAXLOG ≈ 709.78
    EXPECT_EQ(cephes::expn(1, 800), 0.0);
    // x==0 && n < 2
    EXPECT_TRUE(cephes::expn(1, 0.0) > 1e308);
    EXPECT_TRUE(cephes::expn(0, 0.0) > 1e308);
}

TEST(ExpN, Codecov) {
    // Refined numeric checks using Wolfram to 18 decimals:
    // Command form: wolframscript -c "N[ExpIntegralE[n, x], 18]"
    //
    // x==0.0 && n >= 2
    // Wolfram: N[ExpIntegralE[2, 0], 18] -> 1.000000000000000000
    EXPECT_REL_NEAR_F64(cephes::expn(2, 0.0), 1.000000000000000000);
    // Wolfram: N[ExpIntegralE[10, 0], 18] -> 0.111111111111111111
    EXPECT_REL_NEAR_F64(cephes::expn(10, 0.0), 0.111111111111111111);
    //
    // n==0
    // Definition: E_0(x) = e^{-x} / x
    // Wolfram: N[ExpIntegralE[0, 10], 18] -> 0.000004539992976248
    EXPECT_REL_NEAR_F64(cephes::expn(0, 10.0), 0.000004539992976248);
    //
    // n > 5000
    // Wolfram: N[ExpIntegralE[5500, 10], 18] -> 0.000000008241044618
    EXPECT_REL_NEAR_F64(cephes::expn(5500, 10.0), 0.000000008241044618);
    //
    // n <= 5000 && x > 1.0  (cfrac: continued fraction)
    // Wolfram: N[ExpIntegralE[10, 10], 18] -> 0.000002325302657028
    EXPECT_REL_NEAR_F64(cephes::expn(10, 10.0), 0.000002325302657028);
    //
    // Power series expansion
    // Wolfram: N[ExpIntegralE[1, 0.5], 18] -> 0.559773594776160700
    EXPECT_REL_NEAR_F64(cephes::expn(1, 0.5), 0.559773594776160700);
    // Wolfram: N[ExpIntegralE[10, 0.5], 18] -> 0.063458300427127200
    EXPECT_REL_NEAR_F64(cephes::expn(10, 0.5), 0.063458300427127200);
}
