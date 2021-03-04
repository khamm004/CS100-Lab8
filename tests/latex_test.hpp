#ifndef __LATEX_TEST_HPP__
#define __LATEX_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/pow.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/base.hpp"
#include "../header/print.hpp"
#include "../header/iterator.hpp"

TEST(LATEX, Add){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* add  = new Add(seven, six);
        EXPECT_EQ("${({7.000000}+{6.000000})}$", PrintLaTeX(add));
        delete add;
}

TEST(LATEX, Sub){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* sub  = new Sub(seven, six);
        EXPECT_EQ("${({7.000000}-{6.000000})}$", PrintLaTeX(sub));
        delete sub;
}

TEST(LATEX, Mult){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* mult  = new Mult(seven, six);
        EXPECT_EQ("${({7.000000}\\cdot{6.000000})}$", PrintLaTeX(mult));
        delete mult;
}

TEST(LATEX, Div){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* div  = new Div(seven, six);
        EXPECT_EQ("${\\frac{7.000000}{6.000000}}$", PrintLaTeX(div));
        delete div;
}

TEST(LATEX, Pow){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* pow  = new Pow(seven, six);
        EXPECT_EQ("${({7.000000}^{6.000000})}$", PrintLaTeX(pow));
        delete pow;
}


TEST(LATEX, Nested){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* one = new Op(1);
        Base* add  = new Add(seven, six);
        Base* sub = new Sub(one, add);
        EXPECT_EQ("${({1.000000}-{({7.000000}+{6.000000})})}$", PrintLaTeX(sub));
        delete sub;
	
}


TEST(LATEX, Nested2){
        Base* two =  new Op(2);
        Base* five = new Op(5);
	Base* twos =  new Op(2);
        Base* fiver = new Op(5);
        Base* mult  = new Mult(two, five);
        Base* pow  = new Pow(fiver, twos);
        Base* div = new Div(mult, pow);
        EXPECT_EQ("${\\frac{({2.000000}\\cdot{5.000000})}{({5.000000}^{2.000000})}}$", PrintLaTeX(div));
        delete div;
}



#endif
