#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    private:
        Base* left;
        Base* right;
    public:
        ~Div(){
                delete left;
                delete right;
        }
	Div(Base* lt, Base* rt) : Base() {left = lt; right = rt;}

        virtual double evaluate() { return (left->evaluate())/(right->evaluate()); }
        virtual std::string stringify() { return '(' + left->stringify() + '/' + right->stringify() + ')'; }
	virtual int number_of_children(){ return 2;} 
        virtual Base* get_child(int i){ 
		if(i == 0){
			return left;
		}
		else{
			return right;
		}
         }
};

#endif //__DIV_HPP__
