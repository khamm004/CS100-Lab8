#ifndef __PRINT_HPP__
#define __PRINT_HPP__

#include "iterator.hpp"
#include "visitorlatex.hpp"
#include "visitormathml.hpp"
#include <cstring>
#include "visitor.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "base.hpp"

std::string PrintLaTeX(Base* ptr){
        Iterator it(ptr);
        VisitorLaTeX visit;
        std::string output;
        output += "$";
        while (!it.is_done()){
                it.current_node()->accept(&visit, it.current_index());
                it.next();
        }
        output += visit.getstring();
        output += "$";

        return output;

}
std::string PrintMathML(Base* ptr){
	Iterator it(ptr);
	VisitorMathML visit;
	std::string output; 
	output += "<math>\n";
	while (!it.is_done()){
		it.current_node()->accept(&visit, it.current_index());
		it.next();
	}
	output += visit.getstring();
	output += "</math>"; 
	return output;

}

#endif
