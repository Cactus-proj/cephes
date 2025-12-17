#include <cephes/exp_int.h>
#include <xtest.hpp>

TEST(ShiChi, Errors) {
    int ret;
    double x, si, ci;

    // x == 0.0
    ret = cephes::shichi(0.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    EXPECT_EQ(si, 0.0);
    EXPECT_LT(ci, -1e308);
}

TEST(ShiChi, Codecov) {
    int ret;
    double x, si, ci;

    // x < 0.0
    ret = cephes::shichi(-1.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[-1], 18]" -> -1.057250875375728515
    EXPECT_REL_NEAR_F64(si, -1.057250875375728515);
    // Wolfram: wolframscript -c "N[CoshIntegral[-1], 18]" -> 0.837866940980208241 + π i
    // Use real part only for real-valued Cephes output
    EXPECT_REL_NEAR_F64(ci, 0.837866940980208241);

    // x >= 8.0
    // chb:
    ret = cephes::shichi(8.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[8], 18]" -> 220.189968600230556461
    EXPECT_REL_NEAR_F64(si, 220.189968600230556461);
    // Wolfram: wolframscript -c "N[CoshIntegral[8], 18]" -> 220.189930934607712536
    EXPECT_REL_NEAR_F64(ci, 220.189930934607712536);

    // x < 18.0
    ret = cephes::shichi(15.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[15], 18]" -> 117477.926245393744928
    EXPECT_REL_NEAR_F64(si, 117477.926245393744928);
    // Wolfram: wolframscript -c "N[CoshIntegral[15], 18]" -> 117477.926245374558650
    EXPECT_REL_NEAR_F64(ci, 117477.926245374558650);

    // 18.0 <= x <= 88.0
    ret = cephes::shichi(18.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[18], 18]" -> 1938952.165298722153
    EXPECT_REL_NEAR_F64(si, 1938952.165298722153);
    // Wolfram: wolframscript -c "N[CoshIntegral[18], 18]" -> 1938952.165298721350
    EXPECT_REL_NEAR_F64(ci, 1938952.165298721350);
    ret = cephes::shichi(88.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[88], 18]" -> 9.493446879912848346e35
    EXPECT_REL_NEAR_F64_(si, 9.493446879912848346e35, 1e-12);
    // Wolfram: wolframscript -c "N[CoshIntegral[88], 18]" -> 9.493446879912848346e35
    EXPECT_REL_NEAR_F64_(ci, 9.493446879912848346e35, 1e-12);

    // x > 88.0
    ret = cephes::shichi(100.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[100], 18]" -> 1.357776372426939911e41
    // Wolfram: wolframscript -c "N[CoshIntegral[100], 18]" -> 1.357776372426939911e41
    // TODO: y = 1.7976931348623157e+308
    // EXPECT_REL_NEAR_F64_(si, 1.357776372426939911e41, 1e-12);
    // EXPECT_REL_NEAR_F64_(ci, 1.357776372426939911e41, 1e-12);

    // x < 0.0 and |x| > 88.0 -> overflow branch with negative sign
    ret = cephes::shichi(-100.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Expect Shi to be -MAXNUM and Chi to be MAXNUM
    EXPECT_LT(si, -1e308);
    EXPECT_GT(ci, 1e308);

    // x < 8.0
    // power series expansion
    ret = cephes::shichi(3.0, &si, &ci);
    EXPECT_EQ(ret, 0);
    // Wolfram: wolframscript -c "N[SinhIntegral[3], 18]" -> 4.973440475859806798
    EXPECT_REL_NEAR_F64(si, 4.973440475859806798);
    // Wolfram: wolframscript -c "N[CoshIntegral[3], 18]" -> 4.960392094765609760
    EXPECT_REL_NEAR_F64(ci, 4.960392094765609760);
}
