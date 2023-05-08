#include <iostream>
#include <cmath>

class Logarithm {
 public:
  Logarithm(double base, double argument) {
    base_ = base;
    argument_ = argument;
  }

  double Calculate() const {
      if(argument_ <= 0){
        throw std::invalid_argument("Invalid Argument");
      }
      if(base_ == 1 || base_ <=0){
        throw std::invalid_argument("Invalid Base");
    }
    return std::log(argument_) / std::log(base_);
  }

 private:
  double base_;
  double argument_;
};

int main(){
    //Logarithm log1;
    int a;
    try{
        Logarithm log1(0, 2);
        a = log1.Calculate();
        std::cout<<a<<std::endl;
    }catch(const std::invalid_argument& e){
    std::cerr <<"Error: " <<e.what() << std::endl;
        }


}
