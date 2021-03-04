#ifndef __VISITORMATHML_HPP__
#define __VISITORMATHML_HPP__

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

class VisitorMathML : public Visitor{
private:
	int tab = 1;
	std::string equation;
public:
	std::string getstring(){
		return equation;
	}
	virtual void visit_op(Op* node){
		for (int i=0;i<tab;i++){
			equation +="\t";
		}
		equation += "<cn>" + node->stringify() + "</cn>\n";
	}
	virtual void visit_rand(Rand* node){
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "<cn>" + node->stringify() + "</cn>\n";
	}

	virtual void visit_add_begin(Add* node){
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "<apply>\n";
		for (int i=0;i<=tab;i++){
			equation += "\t";
		}
		equation += "<plus/>\n";
		tab++;
	}
	virtual void visit_add_middle(Add* node){
		
	}

	virtual void visit_add_end(Add* node){
		tab--;
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "</apply>\n";
	}

	virtual void visit_sub_begin(Sub* node){
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "<apply>\n";
		for (int i=0;i<=tab;i++){
			equation += "\t";
		}
		equation += "<minus/>\n";
		tab++;
	}

	virtual void visit_sub_middle(Sub* node){

	}

	virtual void visit_sub_end(Sub* node){
		tab--;
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "</apply>\n";
	}


	virtual void visit_mult_begin(Mult* node){
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "<apply>\n";
		for (int i=0;i<=tab;i++){
			equation += "\t";
		}
		equation += "<times/>\n";
		tab++;
	}

	virtual void visit_mult_middle(Mult* node){

	}

	virtual void visit_mult_end(Mult* node){
		tab--;
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "</apply>\n";
	}
	virtual void visit_div_begin(Div* node){
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "<apply>\n";
		for (int i=0;i<=tab;i++){
			equation += "\t";
		}
		equation += "<divide/>\n";
		tab++;
	}
	virtual void visit_div_middle(Div* node){

	}
	virtual void visit_div_end(Div* node){
		tab--;
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "</apply>\n";
	}
	virtual void visit_pow_begin(Pow* node){
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "<apply>\n";
		for (int i=0;i<=tab;i++){
			equation += "\t";
		}
		equation += "<power/>\n";
		tab++;
	}

	virtual void visit_pow_middle(Pow* node){

	}

	virtual void visit_pow_end(Pow* node){
		tab--;
		for (int i=0;i<tab;i++){
			equation += "\t";
		}
		equation += "</apply>\n";
	}


};
#endif
