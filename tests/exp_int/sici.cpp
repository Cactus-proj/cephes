#include <cephes/exp_int.h>
#include <xtest.hpp>

TEST(SiCi, Errors) {
    int ret;
    double x, si, ci;

    // x == 0.0
    ret = cephes::sici(0.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(si, 0.0);
    EXPECT_LT(ci, -1e308);
}

TEST(SiCi, Codecov) {
    int ret;
    double x, si, ci;

    // x < 0.0
    ret = cephes::sici(-1.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinIntegral[-1], 18]" -> -0.946083070367183015
    EXPECT_REL_NEAR_F64(si, -0.946083070367183015);
    // Wolfram: wolframscript -c "N[CosIntegral[-1], 18]" -> 0.337403922900968135 + π i
    // Use real part only for real-valued Cephes output
    EXPECT_REL_NEAR_F64(ci, 0.337403922900968135);

    // x > 1.0e9
    ret = cephes::sici(1e10, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinIntegral[10^10], 18]" -> 1.570796326707584657
    // Wolfram: wolframscript -c "N[CosIntegral[10^10], 18]" -> -4.8750602517482266e-11
    EXPECT_REL_NEAR_F64(si, 1.570796326707584657);
    // TODO: y = 0
    // EXPECT_REL_NEAR_F64(ci, -4.8750602517482266e-11);

    // x > 4.0
    // asympt
    ret = cephes::sici(5.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinIntegral[5], 18]" -> 1.549931244944674137
    EXPECT_REL_NEAR_F64(si, 1.549931244944674137);
    // Wolfram: wolframscript -c "N[CosIntegral[5], 18]" -> -0.190029749656643879
    EXPECT_REL_NEAR_F64(ci, -0.190029749656643879);

    // x < 0.0 and |x| > 4.0
    ret = cephes::sici(-5.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinIntegral[-5], 18]" -> -1.549931244944674137
    EXPECT_REL_NEAR_F64(si, -1.549931244944674137);
    // Wolfram: wolframscript -c "N[CosIntegral[-5], 18]" -> -0.190029749656643879 + π i
    // Use real part only for real-valued Cephes output
    EXPECT_REL_NEAR_F64(ci, -0.190029749656643879);

    // x >= 8.0
    ret = cephes::sici(8.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinIntegral[8], 18]" -> 1.574186821706942052
    EXPECT_REL_NEAR_F64(si, 1.574186821706942052);
    // Wolfram: wolframscript -c "N[CosIntegral[8], 18]" -> 0.122433882532009557
    EXPECT_REL_NEAR_F64(ci, 0.122433882532009557);

    // x <= 4.0
    // asympt
    ret = cephes::sici(3.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinIntegral[3], 18]" -> 1.848652527999468256
    EXPECT_REL_NEAR_F64(si, 1.848652527999468256);
    // Wolfram: wolframscript -c "N[CosIntegral[3], 18]" -> 0.119629786008000328
    EXPECT_REL_NEAR_F64(ci, 0.119629786008000328);
}
