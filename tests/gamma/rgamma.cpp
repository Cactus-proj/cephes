#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(RGamma, BasicAssertions)
{
    EXPECT_REL_NEAR_F64(cephes::rgamma(0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(1.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(2.0), 1.0);
}
TEST(RGamma, Branches)
{
}

/* Julia + SpecialFunctions (MPFR 4.2.0)
```jl
using SpecialFunctions
for i in 0:50
    rgam = big"1" / gamma(BigInt(i)/10)
    f64 = Float64(rgam)
    println("    EXPECT_REL_NEAR_F64(cephes::rgamma($i/10.0), $f64);")
end
```
*/
// TABLE 3.11 Gamma Function
TEST(RGamma, CoSF_Table_3p1)
{
    EXPECT_REL_NEAR_F64(cephes::rgamma(0/10.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(1/10.0), 0.10511370061117778);
    EXPECT_REL_NEAR_F64(cephes::rgamma(2/10.0), 0.21782488421166726);
    EXPECT_REL_NEAR_F64(cephes::rgamma(3/10.0), 0.33427275256419053);
    EXPECT_REL_NEAR_F64(cephes::rgamma(4/10.0), 0.4508241991944111);
    EXPECT_REL_NEAR_F64(cephes::rgamma(5/10.0), 0.5641895835477563);
    EXPECT_REL_NEAR_F64(cephes::rgamma(6/10.0), 0.6715049724420734);
    EXPECT_REL_NEAR_F64(cephes::rgamma(7/10.0), 0.770383183866566);
    EXPECT_REL_NEAR_F64(cephes::rgamma(8/10.0), 0.8589370192246675);
    EXPECT_REL_NEAR_F64(cephes::rgamma(9/10.0), 0.9357787209128727);
    EXPECT_REL_NEAR_F64(cephes::rgamma(10/10.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(11/10.0), 1.0511370061117777);
    EXPECT_REL_NEAR_F64(cephes::rgamma(12/10.0), 1.0891244210583364);
    EXPECT_REL_NEAR_F64(cephes::rgamma(13/10.0), 1.1142425085473018);
    EXPECT_REL_NEAR_F64(cephes::rgamma(14/10.0), 1.1270604979860277);
    EXPECT_REL_NEAR_F64(cephes::rgamma(15/10.0), 1.1283791670955126);
    EXPECT_REL_NEAR_F64(cephes::rgamma(16/10.0), 1.1191749540701224);
    EXPECT_REL_NEAR_F64(cephes::rgamma(17/10.0), 1.1005474055236657);
    EXPECT_REL_NEAR_F64(cephes::rgamma(18/10.0), 1.0736712740308343);
    EXPECT_REL_NEAR_F64(cephes::rgamma(19/10.0), 1.0397541343476364);
    EXPECT_REL_NEAR_F64(cephes::rgamma(20/10.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(21/10.0), 0.9555790964652525);
    EXPECT_REL_NEAR_F64(cephes::rgamma(22/10.0), 0.9076036842152803);
    EXPECT_REL_NEAR_F64(cephes::rgamma(23/10.0), 0.8571096219594629);
    EXPECT_REL_NEAR_F64(cephes::rgamma(24/10.0), 0.8050432128471626);
    EXPECT_REL_NEAR_F64(cephes::rgamma(25/10.0), 0.7522527780636751);
    EXPECT_REL_NEAR_F64(cephes::rgamma(26/10.0), 0.6994843462938264);
    EXPECT_REL_NEAR_F64(cephes::rgamma(27/10.0), 0.6473808267786268);
    EXPECT_REL_NEAR_F64(cephes::rgamma(28/10.0), 0.5964840411282413);
    EXPECT_REL_NEAR_F64(cephes::rgamma(29/10.0), 0.5472390180777034);
    EXPECT_REL_NEAR_F64(cephes::rgamma(30/10.0), 0.5);
    EXPECT_REL_NEAR_F64(cephes::rgamma(31/10.0), 0.4550376649834536);
    EXPECT_REL_NEAR_F64(cephes::rgamma(32/10.0), 0.41254712918876374);
    EXPECT_REL_NEAR_F64(cephes::rgamma(33/10.0), 0.3726563573736795);
    EXPECT_REL_NEAR_F64(cephes::rgamma(34/10.0), 0.3354346720196511);
    EXPECT_REL_NEAR_F64(cephes::rgamma(35/10.0), 0.30090111122547003);
    EXPECT_REL_NEAR_F64(cephes::rgamma(36/10.0), 0.26903244088224093);
    EXPECT_REL_NEAR_F64(cephes::rgamma(37/10.0), 0.23977067658467663);
    EXPECT_REL_NEAR_F64(cephes::rgamma(38/10.0), 0.2130300146886576);
    EXPECT_REL_NEAR_F64(cephes::rgamma(39/10.0), 0.18870310968196669);
    EXPECT_REL_NEAR_F64(cephes::rgamma(40/10.0), 0.16666666666666666);
    EXPECT_REL_NEAR_F64(cephes::rgamma(41/10.0), 0.14678634354304954);
    EXPECT_REL_NEAR_F64(cephes::rgamma(42/10.0), 0.12892097787148868);
    EXPECT_REL_NEAR_F64(cephes::rgamma(43/10.0), 0.11292616890111501);
    EXPECT_REL_NEAR_F64(cephes::rgamma(44/10.0), 0.09865725647636797);
    EXPECT_REL_NEAR_F64(cephes::rgamma(45/10.0), 0.08597174606442);
    EXPECT_REL_NEAR_F64(cephes::rgamma(46/10.0), 0.07473123357840025);
    EXPECT_REL_NEAR_F64(cephes::rgamma(47/10.0), 0.06480288556342612);
    EXPECT_REL_NEAR_F64(cephes::rgamma(48/10.0), 0.056060530181225685);
    EXPECT_REL_NEAR_F64(cephes::rgamma(49/10.0), 0.048385412738965815);
    EXPECT_REL_NEAR_F64(cephes::rgamma(50/10.0), 0.041666666666666664);
}
