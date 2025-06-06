/**
 * @file main.cpp
 * @author Daniel Even
 * @brief This file contains an example of how to use the default argument 
 * feature of C++. This is a feature that (unsurprisingly) allows you to
 * specify a value for a parameter that can be used if the caller of the 
 * function does not specify one. There are several considerations for this:
 * 
 * 1) All defaulted values must be on the rightmost side of the arguments. If an
 * argument has a default value then all other values to the right of it must
 * also have a default value. Other languages may support more complex ordering
 * but C++ does not.
 * 
 * 2) Functions with default arguments are allowed to be overloaded, but this
 * complicates the overload resolution process. In short, the compiler sees the
 * function call to be matched as a fully filled out parameter list. This can 
 * lead to situations where an otherwise clear match leads to an ambiguous
 * match.
 * 
 */
#include <iostream>

// Uncomment this line to demonstrate how a somewhat unexpected ambiguous match
// can arise when overloading 
// #define AMBIGUOUS_MATCH

/**
 * @brief A trivial multiplication function to demonstrate the use of a default
 * argument
 * 
 * @note The default value can be supplied here or in the function definition,
 * but not in both.
 */
int mult(int num1, int num2 = 2);

int mult(int num1, int num2)
{
    return num1 * num2;
}

#ifdef AMBIGUOUS_MATCH
// This specific function signature triggers an ambiguous match error because 
// the compiler now has two possible options for a function call of signature 
// 'mult(int)': This function and mult(int, default int).
int mult(int num)
{
    return num * 2;
}
#endif // AMBIGUOUS_MATCH


int main()
{
    // We'll demonstrate this by calling our function with only one parameter.
    std::cout << "mult(10)=" << mult(10) << std::endl;

    // Now we'll try it with both parameters included.
    std::cout << "mult(10, 3)=" << mult(10, 3) << std::endl;
}
