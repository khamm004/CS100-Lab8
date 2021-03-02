#ifndef __POW_HPP__
#define __POW_HPP__

#include <cmath>
#include "base.hpp"

using namespace std;

class Pow : public Base {
	private:
		Base* left;
		Base* right;
	public: 
		Pow();
		Pow(Base* lh, Base* rh) {left =lh; right=rh;}
		~Pow(){
                        delete left;
                        delete right;
                }
		double evaluate(){return pow(left->evaluate(), right->evaluate());}
		string stringify() {return "(" + left->stringify() + "**" + right->stringify() + ")";}
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
#endif 
