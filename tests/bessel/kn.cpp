#include <cephes/bessel.h>
#include <xtest.hpp>

/*
In[]:= Table[NumberForm[BesselK[nv,x],16],
          {nv,{-1.,0.,1.,3.}},
          {x,{3.14,9.55,13.,709.,710.}}]
Out[]= {
{0.03397775659595887,0.00002997636659771943,8.07858841220235*10^(-7),5.7303176125546*10^(-310),2.106579397305305*10^(-310)},
{0.02956274724299548,0.00002851878466121676,7.784543861420499*10^(-7),5.726280754686924*10^(-310),2.105097455568843*10^(-310)},
{0.03397775659595887,0.00002997636659771943,8.07858841220235*10^(-7),5.7303176125546*10^(-310),2.106579397305305*10^(-310)},
{0.0992065851630097,0.00004455084105664585,1.085625106363125*10^(-6),5.762715047033327*10^(-310),2.118472532415392*10^(-310)}}
*/
TEST(BesselKn, Branches) {
    EXPECT_GT(cephes::kn(0, 0.0), 1.0e308);  // +Inf
    EXPECT_GT(cephes::kn(1, 0.0), 1.0e308);  // +Inf
    EXPECT_GT(cephes::kn(10, 0.0), 1.0e308); // +Inf

    // if (n > MAXFAC) {
    EXPECT_GT(cephes::kn(32, 2.7), 1.0e308);  // OVERFLOW
    EXPECT_GT(cephes::kn(-32, 2.7), 1.0e308); // OVERFLOW

    // if (x <= 0.0) {
    EXPECT_GT(cephes::kn(1, -2.7), 1.0e308);  // DOMAIN
    EXPECT_GT(cephes::kn(1, -0.0), 1.0e308);   // SING
    EXPECT_GT(cephes::kn(1, +0.0), 1.0e308);   // SING

    // if (x > 9.55)  goto asymp;
    // n>0; n==1; n>1; n==0
    EXPECT_REL_NEAR_F64(cephes::kn(-1, 13.), 8.07858841220235e-7);
    EXPECT_REL_NEAR_F64(cephes::kn(0, 13.), 7.784543861420499e-7);
    EXPECT_REL_NEAR_F64(cephes::kn(1, 13.), 8.07858841220235e-7);
    EXPECT_REL_NEAR_F64(cephes::kn(3, 13.), 1.085625106363125e-6);

    // if (x > MAXLOG) {
    EXPECT_REL_NEAR_F64(cephes::kn(1, 709.), 5.7303176125546e-310);
    EXPECT_EQ(cephes::kn(1, 710.), 0.0); // UNDERFLOW

    // !(x > 9.55)
    EXPECT_REL_NEAR_F64(cephes::kn(-1, 3.14), 0.03397775659595887);
    EXPECT_REL_NEAR_F64(cephes::kn(0, 3.14), 0.02956274724299548);
    EXPECT_REL_NEAR_F64(cephes::kn(1, 3.14), 0.03397775659595887);
    EXPECT_REL_NEAR_F64(cephes::kn(3, 3.14), 0.0992065851630097);
}
