#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

using namespace std;

class Sub : public Base {
	private: 
		Base* left;
		Base* right;
	public:
		Sub();
		Sub(Base* lh, Base* rh){left=lh; right=rh;}
		~Sub(){
                        delete left;
                        delete right;
                }
		double evaluate(){return left->evaluate()-right->evaluate();}
		string stringify() {return "(" + left->stringify() + "-" + right->stringify() + ")";}
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
