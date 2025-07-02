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

// Uncomment this section to demonstrate how a constexpr int to constexpr double
// conversion is not automatically allowed for a function template parameter.
// #define DEMO_TYPE_CONVERSION_ERROR

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

/**
 * @brief Since C++17, the auto keyword may be used in place of an actual type
 * in order to indicate the the compiler should determine the type.
 */
template <auto N>
void print_auto()
{
    std::cout << N << std::endl;
}

int main()
{
    // The integer parameter is passed in to the function template section
    // instead of the function parameter section.
    std::cout << "Printing the integer 5: ";
    print<5>();

    // We can also see here that implicit casting can be performed on function
    // template parameters in certain cases.
    std::cout << "Printing the character 'a': ";
    print<'a'>();

    // We do the same here for the getSqrt function.
    std::cout << "The square root of 5 is " << getSqrt<5.0>() << std::endl;

#ifdef DEMO_TYPE_CONVERSION_ERROR
    // Note here that if a constexpr int is passed where a constexpr double is
    // expected, a promotion will not occur and an error will be generated.
    std::cout << "The square root of 5 is " << getSqrt<5>() << std::endl;
#endif // DEMO_TYPE_CONVERSION_ERROR

#ifdef DEMO_STATIC_ASSERT_ERROR
    // This should fail the static assert in the getSqrt function which can be
    // checked at compile time because function template arguments must be
    // constexpr.
    std::cout << "The square root of -5 is " << getSqrt<-5.0>() << std::endl;
#endif // DEMO_STATIC_ASSERT_ERROR

    // This section demonstrates the use of a function template with a non-type
    // parameter specified with the type auto. In the example the type is 
    // deduced by the compiler.
    std::cout << "Printing the integer 5: ";
    print_auto<5>();
    std::cout << "Printing the character 'c': ";
    print_auto<'c'>();
}