// This is a sample program intended to demonstrate the workings of function
// overloading.
#include <iostream>
#include <cstdarg>
#include "OverloadClass.hpp"

// Uncomment the desired function to force the compiler to differentiate
// function types based on each function property.
#define NUM_OF_PARAMS_EXAMPLE
#define TYPE_OF_PARAMS_EXAMPLE
// #define RETURN_TYPE_EXAMPLE
#define ELLIPSIS_EXAMPLE

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

#ifdef ELLIPSIS_EXAMPLE
/**
 * @brief This demonstrates the compilers ability to differentiate ellipses from
 * standard parameters
 */
int add(int num1, ...);
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

#ifdef ELLIPSIS_EXAMPLE
int add(int count, ...)
{
    std::cout << "Fifth add version called! (The variable argument list type)" << std::endl;
    va_list list;
    va_start(list, count);
    int sum = 0;

    for (int i = 0; i < count; ++i)
    {
        sum += static_cast<double>(va_arg(list, int));
    }

    va_end(list);

    return sum;
}
#endif

int main() {
    // Demonstrate the initial 3 examples
    // This should call the first copy of the function.
    int sol = add(1, 2); 

    // This should call the second. Note that this was called with precedence 
    // over the variable argument list version of the function! Very interesting.
    sol = add(1, 2, 3); 

    // And this should call the third.
    float float_solution = add(1.0f, 2.0f); 

    // This should call the variable argument list version
    sol = add(5, 1, 2, 3, 4, 5);


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