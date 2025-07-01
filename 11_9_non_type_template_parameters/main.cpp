/**
 * @file main.cpp
 * @author Daniel Even
 * @brief This file contains examples for how to utilize template parameters for
 * things other than types. A non-type template parameter serves as a placeholder
 * for constexpr value that is passed as a template argument. These can be any 
 * of the following types: 
 * * int
 * * enum
 * * std::nullptr_t
 * * pointer or reference to an object
 * * pointer or reference to a function
 * * pointer or reference to a member function
 * * literal class type (C++20)
 * * floating point type (C++20)
 * 
 * The primary use case for non-type template parameters is to pass a constexpr
 * to a function. This allows for the use of static_assert of parameters.
 */
#include <iostream>
#include <cmath>

// We want to enforce the usage of C++20 in this section.
#if __cplusplus < 202002L
#error "This should be compiled as C++20 code"
#endif

// Uncomment this section to demonstrate a static assert error (at compile time)
// when using an improper function template argument in the example below.
// #define DEMO_STATIC_ASSERT_ERROR

/**
 * @brief A trivial example of using an integer as a function template parameter. 
 */
template <int N>
void print()
{
    std::cout << N << std::endl;
}

/**
 * @brief This function is an example of how to use function template parameters
 * instead of function parameters as a workaround on the restriction against
 * using constexpr parameters.
 */
template <double D>
double getSqrt()
{
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

    if constexpr (D >= 0)
        return std::sqrt(D);

    return 0.0;
}

int main()
{
    // The integer parameter is passed in to the function template section
    // instead of the function parameter section.
    print<5>();

    // We do the same here for the getSqrt function.
    std::cout << "The square root of 5 is " << getSqrt<5.0>() << std::endl;

#ifdef DEMO_STATIC_ASSERT_ERROR
    // This should fail the static assert in the getSqrt function which can be
    // checked at compile time because function template arguments must be
    // constexpr.
    std::cout << "The square root of -5 is " << getSqrt<-5.0>() << std::endl;
#endif // DEMO_STATIC_ASSERT_ERROR
}