#include <cephes/bessel.h>
#include <xtest.hpp>

/*
In[]:= Table[NumberForm[Exp[Abs[x]]*BesselK[1,x],16],
            {x,{-2.7,-1.,0.,1.,2.,3.14}}]
Out[]= {
    -0.859131886696784-140.9911387472708 I,
    -1.636153486263258-4.826308541620153 I,
    ComplexInfinity,
    1.636153486263258,1.033476847068689,0.7850175645511034}
*/
TEST(BesselK1Exp, Branches) {
    // x <= 0.0
    EXPECT_GT(cephes::k1e(-2.7), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k1e(-1.0), 1.0e308); // DOMAIN error
    EXPECT_GT(cephes::k1e(0.0), 1.0e308);  // DOMAIN error

    // x <= 2.0
    EXPECT_REL_NEAR_F64(cephes::k1e(1.0), 1.636153486263258);
    EXPECT_REL_NEAR_F64(cephes::k1e(2.0), 1.033476847068689);

    // x > 2.0
    EXPECT_REL_NEAR_F64(cephes::k1e(3.14), 0.7850175645511034);
}
