// This is a sample program intended to demonstrate the workings of function
// overloading.
#include <iostream>
#include "OverloadClass.hpp"

// Uncomment the desired function to force the compiler to differentiate
// function types based on each function property.
#define NUM_OF_PARAMS_EXAMPLE
#define TYPE_OF_PARAMS_EXAMPLE
// #define RETURN_TYPE_EXAMPLE
#define CONST_EXAMPLE

//==============================================================================
// Function Declarations
//==============================================================================
/**
 * @brief A trivial function that will be overloaded in the following examples.
 */
int add(int num1, int num2);

#ifdef NUM_OF_PARAMS_EXAMPLE
/**
 * @brief A trivial function to force the compiler to overload based on the
 * number of parameters used.
 */
int add(int num1, int num2, int num3);
#endif

#ifdef TYPE_OF_PARAMS_EXAMPLE
/**
 * @brief A trivial function to force the compiler to overload based on the
 * type of parameters used.
 */
float add(float num1, float num2);
#endif

#ifdef RETURN_TYPE_EXAMPLE
/**
 * @brief A trivial function used to try to force the compiler to overload based
 * on the return type. This is not allowed and will fail.
 */
float add(int num1, int num2);
#endif

//==============================================================================
// Function Definitions
//==============================================================================
int add(int num1, int num2)
{
    std::cout << "First add version called!" << std::endl;
    return num1 + num2;
}

#ifdef NUM_OF_PARAMS_EXAMPLE
int add(int num1, int num2, int num3)
{
    std::cout << "Second add version called! (Overloaded based on number of parameters)" << std::endl;
    return num1 + num2 + num3;
}
#endif

#ifdef TYPE_OF_PARAMS_EXAMPLE
float add(float num1, float num2)
{
    std::cout << "Third add version called! (Overloaded based on type of parameters)" << std::endl;
    return num1 + num2;
}
#endif

#ifdef RETURN_TYPE_EXAMPLE
float add(int num1, int num2)
{
    std::cout << "Fourth add version called! (Overloaded based on return type)" << std::endl;
    return num1 + num2;
}
#endif

int main() {
    // Demonstrate the initial 3 examples
    int sol = add(1, 2);
    sol = add(1, 2, 3);
    float float_solution = add(1.0f, 2.0f);

    // Demonstrate how member functions of a class can be overloaded based on 
    // const or volatile qualifiers.

    // Create a non-const object.
    OverloadClass overload_class; 

    // Check the logs to see which version of this function was called.
    (void)overload_class.get_number(); 

    // Lets create a const version of the same class now.                               
    const OverloadClass overload_class_const;

    // Check the logs to see which version of this function was called.
    (void)overload_class_const.get_number(); 
}