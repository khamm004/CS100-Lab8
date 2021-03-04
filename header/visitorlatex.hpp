#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "base.hpp"
#include <cstring>


class VisitorLaTeX : public Visitor{
	private:
	std::string equation;
	public:
	std::string getstring(){
		return equation;
	}
	virtual void visit_op(Op* node){
		equation += "{" + node->stringify() + "}";
	}
	virtual void visit_rand(Rand* node){
		equation += "{" + node->stringify() + "}";
	}


	virtual void visit_add_begin(Add* node){
		equation += "{(";
	}
	virtual void visit_add_middle(Add* node){
		equation += "+";
	}
	virtual void visit_add_end(Add* node){
		equation += ")}";
	}


    virtual void visit_sub_begin(Sub* node){
		equation += "{(";
	}
    virtual void visit_sub_middle(Sub* node){
		equation += "-";
	}
    virtual void visit_sub_end(Sub* node){
		equation += ")}";
	}


    virtual void visit_mult_begin(Mult* node){
		equation += "{(";
	}
    virtual void visit_mult_middle(Mult* node){
		equation += "\\cdot";
	}
    virtual void visit_mult_end(Mult* node){
		equation += ")}";
	}


    virtual void visit_div_begin(Div* node){
		equation += "{\\frac";
	}
    virtual void visit_div_middle(Div* node){

	}
    virtual void visit_div_end(Div* node){
		equation += "}";
	}


    virtual void visit_pow_begin(Pow* node){
		equation += "{(";
	}
    virtual void visit_pow_middle(Pow* node){
		equation += "^";
	}
    virtual void visit_pow_end(Pow* node){
		equation += ")}";
	}
};
#endif
