#include "gtest/gtest.h"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/pow.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/base.hpp"

TEST(ITERATOR, MultChild){
	Base* temp1 = new Op(7);
	Base* temp2 = new Op(8);
	Base* test = new Mult(temp1,temp2);
	EXPECT_EQ(2,test->number_of_children());
	EXPECT_EQ(7,test->get_child(0)->evaluate());
	EXPECT_EQ(8,test->get_child(1)->evaluate());
	delete test;
}

TEST(FACTORY, AddChild){
	Base* temp1 = new Op(7);
	Base* temp2 = new Op(8);
	Base* test = new Add(temp1,temp2);
	EXPECT_EQ(2,test->number_of_children());
	EXPECT_EQ(7,test->get_child(0)->evaluate());
	EXPECT_EQ(8,test->get_child(1)->evaluate());
	delete test;
}

TEST(FACTORY, SubChild){
	Base* temp1 = new Op(7);
	Base* temp2 = new Op(8);
	Base* test = new Sub(temp1,temp2);
	EXPECT_EQ(2,test->number_of_children());
	EXPECT_EQ(7,test->get_child(0)->evaluate());
	EXPECT_EQ(8,test->get_child(1)->evaluate());
	delete test;
}

TEST(FACTORY, DivChild){
	Base* temp1 = new Op(7);
	Base* temp2 = new Op(8);
	Base* test = new Div(temp1,temp2);
	EXPECT_EQ(2,test->number_of_children());
	EXPECT_EQ(7,test->get_child(0)->evaluate());
	EXPECT_EQ(8,test->get_child(1)->evaluate());
	delete test;
}

TEST(FACTORY, PowChild){
	Base* temp1 = new Op(7);
	Base* temp2 = new Op(8);
	Base* test = new Pow(temp1,temp2);
	EXPECT_EQ(2,test->number_of_children());
	EXPECT_EQ(7,test->get_child(0)->evaluate());
	EXPECT_EQ(8,test->get_child(1)->evaluate());
	delete test;
}

TEST(FACTORY, OpChild){
	Base* temp1 = new Op(7);
	EXPECT_EQ(0,temp1->number_of_children());
	delete temp1;
}

TEST(FACTORY, RandChild){
	Base* temp1 = new Rand();
	EXPECT_EQ(0,temp1->number_of_children());
	delete temp1;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
