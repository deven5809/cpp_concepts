/**
 * @file main.cpp
 * @author Daniel Even
 * @brief This is the main file for a demonstration of the C++ feature of 
 * function templates. This feature allows the programmer to create a template
 * (surprise) for a function that is independent of the types used and can be
 * generated at compile time.
 * 
 * @note This covers sections 11.6 to 11.9 from learncpp.com.
 */
#include <iostream>
#include <type_traits> // Required to use std::common_type_t

// Uncomment this define to see the error thrown when you use two distinct types
// to call a templated function that calls for two of the same type.
// #define TWO_TYPES_ERROR

// Uncomment this define to include the more flexible definition of max that 
// will resolve the TWO_TYPES_ERROR above.
// #define AUTO_MAX_FUNCTION

/**
 * @brief This is a basic templated add function that will be 'instantiated' to
 * an actual function if it is needed. The type 'T' is a stand in for whatever
 * type might be needed.
 * 
 * @note Function template parameters can also have default values, but in this
 * case the type is now explicitly declared.
 */
template <typename T>
T add(const T a, const T b)
{
    return a + b;
}

/**
 * @brief This deletion tells the compiler to throw an error if a function call
 * is matched to this signature. This is a way of disallowing auto generating
 * functions that would cause errors or otherwise fail.
 */
template <>
std::string add(std::string a, std::string b) = delete;

// This section covers function templates with multiple template types.

/**
 * @brief This templated max function takes two parameters that MUST be of the 
 * same type. If this is violated, a compiler error will be generated (as 
 * demonstrated below). 
 */
template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

#ifdef AUTO_MAX_FUNCTION
/**
 * @brief This is the full declaration for the max function that uses the auto
 * return type. 
 * 
 * @note A full declaration is required for any function using an
 * automatic type as a return type.
 * 
 * @note This uses the trailing return type syntax which was introduced in
 * C++11.
 * 
 * @note std::common_type will return a type that both T and U can be safely
 * promoted to (a.k.a. the common type).
 * 
 */
template<typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>;

template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>
{
    return (x < y) ? y : x;
}
#endif // AUTO_MAX_FUNCTION

int main()
{
    // We can now use the 'add' function to add any types for which the add 
    // operator is allowed! The overloaded function will be 'instantiated' on
    // a case by case basis.
    std::cout << "Adding integers: 1 + 2 = " << add(1, 2) << std::endl;
    std::cout << "Adding doubles: 1.0f + 2.5f = " << add(1.0f, 2.5f) << std::endl;
    std::cout << "Adding chars: 'A' + ' ' = " << add('A', ' ') << std::endl;

    // This section uses the 'max' function to demonstrate the use of multiple
    // parameters/types.

    // Either of these examples will work as they both use two parameters of the
    // same type.
    std::cout << "The maximum of 3 and 7 is " << max(3, 7) << std::endl;
    std::cout << "The maximum of 2.2 and 2.3 is " << max(2.2, 2.3) << std::endl;

#ifdef TWO_TYPES_ERROR
    // This attempts to call the max function with two distinct types. We might
    // assume that the compiler would simply cast either of the types to the
    // type of the other, but this is not the case. A compiler error will be
    // generated here as no matching function call can be found. Templates 
    // require an EXACT match.
    std::cout << "The max of 3 and 2.3 is " << max(3, 2.3) << std::endl;
#endif // TWO_TYPES_ERROR

    // We can avoid the TWO_TYPES_ERROR situation above by explicitly casting
    // the arguments into common types by using static_cast. This resolves any
    // ambiguity.
    std::cout << "The max of 3 and 2.3 is " << max(3, static_cast<int>(2.3)) 
        << std::endl;

    // Alternatively, we can avoid ambiguity by explicitly stating the type of
    // templated function that we would like generated as follows:
    std::cout << "The max of 3 and 2.3 is " << max<int>(3, 2.3) << std::endl;
    
    // These are workarounds though, and another way to solve this problem is to
    // create a template that allows for multiple types to begin with. Uncomment
    // AUTO_MAX_FUNCTION above to see how this can be done.
}