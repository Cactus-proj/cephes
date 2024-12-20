#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(LogGamma, BasicAssertions)
{
    EXPECT_TRUE(std::isnan(cephes::lgam(xtest::NaN64)));
    EXPECT_TRUE(std::isinf(cephes::lgam(xtest::Inf64)));
    EXPECT_TRUE(std::isinf(cephes::lgam(0.0)));

    EXPECT_REL_NEAR_F64(cephes::lgam(1.0), 0.0);
}

TEST(LogGamma, BranchCov)
{
    // if (x < -34.0)
    EXPECT_TRUE(std::isinf(cephes::lgam(-35.0)));
    EXPECT_REL_NEAR_F64(cephes::lgam(-35.1), -90.17418399135259);

    // if (x < 13.0) && if (z < 0.0)

    // if (x > MAXLGM)
    EXPECT_TRUE(std::isinf(cephes::lgam(2.6e305)));
    EXPECT_TRUE(std::isinf(cephes::lgam(xtest::Inf64)));
    // (x <= MAXLGM) && (x > 1.0e8)
    EXPECT_REL_NEAR_F64(cephes::lgam(2.0e8), 3.622765576264487e9);
    // (x <= MAXLGM) && (x <= 1.0e8) && (x >= 1000.0)
    EXPECT_REL_NEAR_F64(cephes::lgam(1.0e8), 1.7420680661038346e9);
}

/* Julia + SpecialFunctions (MPFR 4.2.0)
```jl
using SpecialFunctions
for i in 0:50
    gam = loggamma(BigInt(i)/10)
    f64 = Float64(gam)
    println("EXPECT_REL_NEAR_F64(cephes::lgam($i/10.0), $f64);")
end
```
*/
// TABLE 3.11 Gamma Function
TEST(LogGamma, CoSF_Table_3p1)
{
    // EXPECT_REL_NEAR_F64(cephes::lgam(0/10.0), Inf);
    EXPECT_REL_NEAR_F64(cephes::lgam(1/10.0), 2.252712651734206);
    EXPECT_REL_NEAR_F64(cephes::lgam(2/10.0), 1.5240638224307845);
    EXPECT_REL_NEAR_F64(cephes::lgam(3/10.0), 1.0957979948180756);
    EXPECT_REL_NEAR_F64(cephes::lgam(4/10.0), 0.7966778177017838);
    EXPECT_REL_NEAR_F64(cephes::lgam(5/10.0), 0.5723649429247001);
    EXPECT_REL_NEAR_F64(cephes::lgam(6/10.0), 0.3982338580692349);
    EXPECT_REL_NEAR_F64(cephes::lgam(7/10.0), 0.26086724653166654);
    EXPECT_REL_NEAR_F64(cephes::lgam(8/10.0), 0.15205967839983758);
    EXPECT_REL_NEAR_F64(cephes::lgam(9/10.0), 0.06637623973474296);
    EXPECT_REL_NEAR_F64(cephes::lgam(10/10.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::lgam(11/10.0), -0.04987244125983972);
    EXPECT_REL_NEAR_F64(cephes::lgam(12/10.0), -0.08537409000331585);
    EXPECT_REL_NEAR_F64(cephes::lgam(13/10.0), -0.10817480950786047);
    EXPECT_REL_NEAR_F64(cephes::lgam(14/10.0), -0.1196129141723713);
    EXPECT_REL_NEAR_F64(cephes::lgam(15/10.0), -0.12078223763524522);
    EXPECT_REL_NEAR_F64(cephes::lgam(16/10.0), -0.11259176569675579);
    EXPECT_REL_NEAR_F64(cephes::lgam(17/10.0), -0.09580769740706586);
    EXPECT_REL_NEAR_F64(cephes::lgam(18/10.0), -0.07108387291437217);
    EXPECT_REL_NEAR_F64(cephes::lgam(19/10.0), -0.03898427592308333);
    EXPECT_REL_NEAR_F64(cephes::lgam(20/10.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::lgam(21/10.0), 0.045437738544485136);
    EXPECT_REL_NEAR_F64(cephes::lgam(22/10.0), 0.09694746679063877);
    EXPECT_REL_NEAR_F64(cephes::lgam(23/10.0), 0.15418945495963057);
    EXPECT_REL_NEAR_F64(cephes::lgam(24/10.0), 0.21685932244884162);
    EXPECT_REL_NEAR_F64(cephes::lgam(25/10.0), 0.2846828704729192);
    EXPECT_REL_NEAR_F64(cephes::lgam(26/10.0), 0.35741186354897975);
    EXPECT_REL_NEAR_F64(cephes::lgam(27/10.0), 0.4348205536551045);
    EXPECT_REL_NEAR_F64(cephes::lgam(28/10.0), 0.5167027919877468);
    EXPECT_REL_NEAR_F64(cephes::lgam(29/10.0), 0.6028696102493114);
    EXPECT_REL_NEAR_F64(cephes::lgam(30/10.0), 0.6931471805599453);
    EXPECT_REL_NEAR_F64(cephes::lgam(31/10.0), 0.7873750832738624);
    EXPECT_REL_NEAR_F64(cephes::lgam(32/10.0), 0.885404827154909);
    EXPECT_REL_NEAR_F64(cephes::lgam(33/10.0), 0.9870985778947345);
    EXPECT_REL_NEAR_F64(cephes::lgam(34/10.0), 1.0923280598027416);
    EXPECT_REL_NEAR_F64(cephes::lgam(35/10.0), 1.2009736023470743);
    EXPECT_REL_NEAR_F64(cephes::lgam(36/10.0), 1.312923308576416);
    EXPECT_REL_NEAR_F64(cephes::lgam(37/10.0), 1.4280723266653879);
    EXPECT_REL_NEAR_F64(cephes::lgam(38/10.0), 1.546322209168905);
    EXPECT_REL_NEAR_F64(cephes::lgam(39/10.0), 1.6675803472417399);
    EXPECT_REL_NEAR_F64(cephes::lgam(40/10.0), 1.791759469228055);
    EXPECT_REL_NEAR_F64(cephes::lgam(41/10.0), 1.918777194764963);
    EXPECT_REL_NEAR_F64(cephes::lgam(42/10.0), 2.04855563696059);
    EXPECT_REL_NEAR_F64(cephes::lgam(43/10.0), 2.181021046367169);
    EXPECT_REL_NEAR_F64(cephes::lgam(44/10.0), 2.3161034914248573);
    EXPECT_REL_NEAR_F64(cephes::lgam(45/10.0), 2.4537365708424423);
    EXPECT_REL_NEAR_F64(cephes::lgam(46/10.0), 2.5938571540384805);
    EXPECT_REL_NEAR_F64(cephes::lgam(47/10.0), 2.7364051463155667);
    EXPECT_REL_NEAR_F64(cephes::lgam(48/10.0), 2.881323275901245);
    EXPECT_REL_NEAR_F64(cephes::lgam(49/10.0), 3.0285569003773407);
    EXPECT_REL_NEAR_F64(cephes::lgam(50/10.0), 3.1780538303479458);
}
