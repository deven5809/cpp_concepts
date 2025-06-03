/**
 * @file OverloadClass.hpp
 * @author Daniel Even
 * @brief This class will be used to demonstrate the overloading capabilities of
 * the C++ language with regards to member functions. 
 */

 #include <iostream>

 /**
  * @brief This is a sample class used solely to demonstrate how one can
  * overload member functions based on const qualifiers. This would primarily be
  * used when the class in question is returning a reference/pointer to some
  * member data and we want to allow the user to decide whether or not to give
  * edit access. If the user wants to limit access they can delcare the object
  * as const and const correctness will be maintained but the option to be 
  * flexible still exists.
  * 
  */
class OverloadClass {
private:
    int num1 = 0;
public:
    int get_number(void) {
        std::cout << "The non-const version of this function has been called from OverloadClass!" << std::endl;
        return OverloadClass::num1;
    }
    
    int get_number(void) const {
        std::cout << "The const version of this function has been called from OverloadClass!" << std::endl;
        return OverloadClass::num1;
    }
};