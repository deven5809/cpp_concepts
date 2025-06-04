/**
 * @file main.cpp
 * @author Daniel Even
 * @brief This is a demonstration of the function deletion feature of C++. This 
 * is used to block the compiler from performing an overload resolution to a 
 * specific parameter type. If this specific funtion signature is "deleted" then
 * a compile error will be thrown if overload resolution matches a function call
 * to this specific signature. An example is shown below.
 * 
 * Another use of this is to specify that a function can only be called with an
 * exact match for parameter types, no conversion/promotion allowed. This is 
 * achieved with a function template which will take precedence over all other
 * types.
 */
#include <iostream>

// Uncomment this line to attempt to call the deleted function parameter and to
// see the resulting compiler error.
// #define ATTEMPT_DELETED_FUNC_CALL

// Uncomment this line to attempt to call a templated deleted function with 
// anything other than the specified parameter type and see the resulting
// compiler error.
// #define ATTEMPT_TEMPLATE_DELETED_FUNCTION

/**
 * @brief Our example function
 */
void foo(int x)
{
    std::cout << "This function should never be called with a char as a parameter." << std::endl;
}

/**
 * @brief Our second example function
 */
void bar(int x)
{
    std::cout << "This function should never be called with anything other than an int as a parameter." << std::endl;
}

/**
 * @brief This function template will be invoked for any non-exactl function 
 * match
 * 
 * @tparam T 
 * @param x 
 */
template <typename T>
void bar(T x) = delete;


// This should block compiling if we attempt to call foo with a char.
void foo(char) = delete; 

int main()
{
    // Let's call foo with the intendent type of parameter, and int
    foo(97);
    // That should have worked!

#ifdef ATTEMPT_DELETED_FUNC_CALL
    // Now lets try it with a char and see what happens
    foo('a');
#endif // ATTEMPT_DELETED_FUNC_CALL

    // There's nothing stopping us from calling it with a boolean though, right?
    foo(true);

    // Now lets take a look at the second example function, foo. It should only
    // allow calls that exactly match it's function signature.
    // This should be allowed:
    bar(97);

#ifdef ATTEMPT_TEMPLATE_DELETED_FUNCTION
    // None of these following examples should be allowed:
    bar('a');
    bar(true);
    bar(1.0f);
#endif // ATTEMPT_TEMPLATE_DELETED_FUNCTION
}

