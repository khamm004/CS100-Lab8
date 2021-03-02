#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

using namespace std;

class Add : public Base {
	private: 
		Base* left;
		Base* right;
	public:
		Add();
		~Add(){
			delete left;
			delete right;
		}
		Add(Base* lh, Base* rh){left=lh; right=rh;};
		double evaluate(){return left->evaluate()+right->evaluate();}
		string stringify() {return "(" + left->stringify() + "+" + right->stringify() + ")";}
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
