#ifndef __MATHML_TEST_HPP__
#define __MATHML_TEST_HPP__
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

TEST(MATHML, Add){
        Base* seven =  new Op(7);
        Base* six = new Op(6);
        Base* add  = new Add(seven, six);
        EXPECT_EQ("<math>\n\t<apply>\n\t\t<plus/>\n\t\t<cn>7.000000</cn>\n\t\t<cn>6.000000</cn>\n\t</apply>\n</math>", PrintMathML(add));
        delete add;
}

TEST(MATHML, Sub){
    Base* seven =  new Op(7);
    Base* six = new Op(6);
    Base* sub  = new Sub(seven, six);
    EXPECT_EQ("<math>\n\t<apply>\n\t\t<minus/>\n\t\t<cn>7.000000</cn>\n\t\t<cn>6.000000</cn>\n\t</apply>\n</math>", PrintMathML(sub));
    delete sub;
}

TEST(MATHML, Mult){
    Base* seven =  new Op(7);
    Base* six = new Op(6);
    Base* mult  = new Mult(seven, six);
    EXPECT_EQ("<math>\n\t<apply>\n\t\t<times/>\n\t\t<cn>7.000000</cn>\n\t\t<cn>6.000000</cn>\n\t</apply>\n</math>", PrintMathML(mult));
    delete mult;
}

TEST(MATHML, Div){
    Base* seven =  new Op(7);
    Base* six = new Op(6);
    Base* div  = new Div(seven, six);
    EXPECT_EQ("<math>\n\t<apply>\n\t\t<divide/>\n\t\t<cn>7.000000</cn>\n\t\t<cn>6.000000</cn>\n\t</apply>\n</math>", PrintMathML(div));
    delete div;
}

TEST(MATHML, Pow){
    Base* seven =  new Op(7);
    Base* six = new Op(6);
    Base* pow  = new Pow(seven, six);
    EXPECT_EQ("<math>\n\t<apply>\n\t\t<power/>\n\t\t<cn>7.000000</cn>\n\t\t<cn>6.000000</cn>\n\t</apply>\n</math>", PrintMathML(pow));
    delete pow;
}

TEST(MATHML, Nested){
    Base* seven =  new Op(7);
    Base* six = new Op(6);
    Base* one = new Op(1);
    Base* add  = new Add(seven, six);
    Base* sub = new Sub(one, add);
    EXPECT_EQ("<math>\n\t<apply>\n\t\t<minus/>\n\t\t<cn>1.000000</cn>\n\t\t<apply>\n\t\t\t<plus/>\n\t\t\t<cn>7.000000</cn>\n\t\t\t<cn>6.000000</cn>\n\t\t</apply>\n\t</apply>\n</math>", PrintMathML(sub));
    delete sub;	
}

TEST(MATHML, Nested2){
    Base* two =  new Op(2);
    Base* five = new Op(5);
    Base* twos =  new Op(2);
    Base* fiver = new Op(5);
    Base* mult  = new Mult(two, five);
    Base* pow  = new Pow(fiver, twos);
    Base* div = new Div(mult, pow);
    EXPECT_EQ("<math>\n\t<apply>\n\t\t<divide/>\n\t\t<apply>\n\t\t\t<times/>\n\t\t\t<cn>2.000000</cn>\n\t\t\t<cn>5.000000</cn>\n\t\t</apply>\n\t\t<apply>\n\t\t\t<power/>\n\t\t\t<cn>5.000000</cn>\n\t\t\t<cn>2.000000</cn>\n\t\t</apply>\n\t</apply>\n</math>", PrintMathML(div));
    delete div;
}

#endif

