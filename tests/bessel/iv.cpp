#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(BesselIv, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::iv(-1.0, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::iv(0.0, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::iv(1.0, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::iv(3.14, xtest::NaN64)));

    /* 
        Table[NumberForm[BesselI[nv, x], 16], 
            {nv, {-3, -2.7, -1, 0, 1, 2.7, 3}},
            {x, {0.0}}]

        {{0.},{ComplexInfinity},{0.},{1.},{0.},{0.},{0.}}
    */
    EXPECT_EQ(cephes::iv(-3.0, 0.0), 0.0);
    EXPECT_GE(cephes::iv(-2.7, 0.0), 1e300);  // OVERFLOW error
    EXPECT_EQ(cephes::iv(-1.0, 0.0), 0.0);
    EXPECT_EQ(cephes::iv(0.0, 0.0), 1.0);
    EXPECT_EQ(cephes::iv(1.0, 0.0), 0.0);
    EXPECT_EQ(cephes::iv(2.7, 0.0), 0.0);
    EXPECT_EQ(cephes::iv(3.0, 0.0), 0.0);

    /*
        In[]:= Table[NumberForm[BesselI[nv,x],16],
                    {nv,{-2.7,2.7}}, {x,{-1.0}}]
        Out[]= {{-1.347410968345851-1.854552096275787 I},
                {-0.02319371570609598+0.03192341096641882 I}}
    */
    EXPECT_EQ(cephes::iv(2.7, -1.0), 0.0);  // DOMAIN error
    EXPECT_EQ(cephes::iv(-2.7, -1.0), 0.0);  // DOMAIN error
}

TEST(BesselIv, FuncPropertyRandom) {
    // Even function:   iv(-z) =  iv(z), for nv ...
    // Odd function:    iv(-z) = -iv(z), for nv ...
    // TODO
}

/*
In[]:= Table[NumberForm[BesselI[nv,x],16],
            {nv,{-3,-2,1,2,2.7}},
            {x,{-1.0,1.0}}]
Out[]= {{-0.0221684249243319,0.0221684249243319},
        {0.1357476697670383,0.1357476697670383},
        {-0.5651591039924851,0.5651591039924851},
        {0.1357476697670383,0.1357476697670383},
        {-0.02319371570609598+0.03192341096641882 I,0.03945950602815591}}
 */
TEST(BesselIv, Branches) {
    // nv < 0, odd int
    EXPECT_REL_NEAR_F64(cephes::iv(-3.0, -1.0),  -0.0221684249243319);
    EXPECT_REL_NEAR_F64(cephes::iv(-3.0, +1.0),  0.0221684249243319);
    // nv < 0, even int
    EXPECT_REL_NEAR_F64(cephes::iv(-2.0, -1.0),  0.1357476697670383);
    EXPECT_REL_NEAR_F64(cephes::iv(-2.0, +1.0),  0.1357476697670383);
    // nv <0, real
    // Domain Error

    // nv > 0, odd int
    EXPECT_REL_NEAR_F64(cephes::iv(1.0, -1.0),  -0.5651591039924851);
    EXPECT_REL_NEAR_F64(cephes::iv(1.0, +1.0),  0.5651591039924851);
    // nv > 0, even int
    EXPECT_REL_NEAR_F64(cephes::iv(2.0, -1.0),  0.1357476697670383);
    EXPECT_REL_NEAR_F64(cephes::iv(2.0, +1.0),  0.1357476697670383);
    // nv > 0, real
    EXPECT_REL_NEAR_F64(cephes::iv(2.7, -1.0),  0.0); // DOMAIN error
    EXPECT_REL_NEAR_F64(cephes::iv(2.7, +1.0),  0.03945950602815591);
}
