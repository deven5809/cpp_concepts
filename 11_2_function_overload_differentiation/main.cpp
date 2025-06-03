/**
 * @file main.cpp
 * @author Daniel Even
 * @brief This is a sample program demonstrating the workings of function
 * overloading. This includes examples for differentiation based on parameter
 * type, number of parameters, and const/volatile qualifiers for member
 * functions. It also demonstrates that the ellipsis is treated as a separate
 * argument type and can be used alongside overloaded functions.
 * 
 * Mangling as a Mechanism: The compiler uses a technique called "name mangling"
 * in order to differentiate these functions. The function name is modified 
 * based on the number of parameters and parameter types to create a truly 
 * unique name. Naming conventions are not standardzied and will vary between 
 * compilers.
 */
#include <iostream>
#include <cstdarg>
#include "OverloadClass.hpp"

// Uncomment this to demonstrate how functions cannot be overloaded based on
// return type.
// #define RETURN_TYPE_EXAMPLE


//==============================================================================
// Function Declarations
//==============================================================================
/**
 * @brief A trivial function that will be overloaded in the following examples.
 */
int add(int num1, int num2);

/**
 * @brief A trivial function to force the compiler to overload based on the
 * number of parameters used.
 */
int add(int num1, int num2, int num3);

/**
 * @brief A trivial function to force the compiler to overload based on the
 * type of parameters used.
 */
float add(float num1, float num2);


#ifdef RETURN_TYPE_EXAMPLE
/**
 * @brief A trivial function used to try to force the compiler to overload based
 * on the return type. This is not allowed and will fail.
 */
float add(int num1, int num2);
#endif

/**
 * @brief This demonstrates the compilers ability to differentiate ellipses from
 * standard parameters
 */
int add(int num1, ...);


//==============================================================================
// Function Definitions
//==============================================================================
int add(int num1, int num2)
{
    std::cout << "First add version called!" << std::endl;
    return num1 + num2;
}

int add(int num1, int num2, int num3)
{
    std::cout << "Second add version called! (Overloaded based on number of parameters)" << std::endl;
    return num1 + num2 + num3;
}

float add(float num1, float num2)
{
    std::cout << "Third add version called! (Overloaded based on type of parameters)" << std::endl;
    return num1 + num2;
}

#ifdef RETURN_TYPE_EXAMPLE
float add(int num1, int num2)
{
    std::cout << "Fourth add version called! (Overloaded based on return type)" << std::endl;
    return num1 + num2;
}
#endif

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