#include <cephes/bessel.h>
#include <xtest.hpp>

/*
In[]:= Table[NumberForm[BesselK[1,x],16],
            {x,{-2.7,-1.,0.,1.,2.,3.14}}]
Out[]= {
    -0.05773839895652593-9.47538177127153 I,
    -0.6019072301972347-1.775499689212181 I,
    ComplexInfinity,
    0.6019072301972347,0.1398658818165224,0.03397775659595887}
*/
TEST(BesselK1, Branches) {
    // x <= 0.0
    EXPECT_GT(cephes::k1(-2.7), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k1(-1.0), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k1(0.0), 1.0e308);  // DOMAIN error

    // x <= 2.0
    EXPECT_REL_NEAR_F64(cephes::k1(1.0), 0.6019072301972347);
    EXPECT_REL_NEAR_F64(cephes::k1(2.0), 0.1398658818165224);

    // x > 2.0
    EXPECT_REL_NEAR_F64(cephes::k1(3.14), 0.03397775659595887);
}
