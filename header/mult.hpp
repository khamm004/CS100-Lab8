#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
        Base* left;
	Base* right;
    public:
        Mult(Base* lt, Base* rt) : Base() {left = lt; right = rt;}
	~Mult(){
		delete left;
		delete right;
	}
        virtual double evaluate() { return (left->evaluate())*(right->evaluate()); }
        virtual std::string stringify() { return '(' + left->stringify() + '*' + right->stringify() + ')'; }
	virtual int number_of_children(){ return 2;} 
        virtual Base* get_child(int i){ 
		if(i == 0){
			return left;
		}
		else{
			return right;
		}
         }
	void accept(Visitor* visitor, int index){
		if(index == 0){
			visitor->visit_mult_begin(this);
		}
		else if(index == 1){
			visitor->visit_mult_middle(this);
		}
		else{
			visitor->visit_mult_end(this);
		}
        }

};

#endif //__MULT_HPP__

