#include "header/iterator.hpp"
#include "header/visitorlatex.hpp"
#include <cstring>
#include "header/visitor.hpp"
#include "header/div.hpp"
#include "header/add.hpp"
#include "header/pow.hpp"
#include "header/op.hpp"
#include "header/sub.hpp"
#include "header/rand.hpp"
#include "header/mult.hpp"
#include "header/base.hpp"
#include <iostream>
#include "header/print.hpp"

int main(){
    Base* two =  new Op(2);
    Base* five = new Op(5);
    Base* twos =  new Op(2);
    Base* fiver = new Op(5);
    Base* mult  = new Mult(two, five);
    Base* pow  = new Pow(fiver, twos);
    Base* div = new Div(mult,pow);
    cout << "LaTeX: " << PrintLaTeX(div)<< endl;
    cout <<"MathML: "<< endl << PrintMathML(div)<< endl;
    delete div;

}
