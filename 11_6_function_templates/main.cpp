/**
 * @file main.cpp
 * @author Daniel Even
 * @brief This is the main file for a demonstration of the C++ feature of 
 * function templates. This feature allows the programmer to create a template
 * (surprise) for a function that is independent of the types used and can be
 * generated at compile time.
 */
#include <iostream>


/**
 * @brief This is a basic templated add function that will be 'instantiated' to
 * an actual function if it is needed. The type 'T' is a stand in for whatever
 * type might be needed.
 */
template <typename T>
T add(const T a, const T b)
{
    return a + b;
}

int main()
{
    // We can now use the 'add' function to add any types for which the add 
    // operator is allowed! The overloaded function will be 'instantiated' on
    // a case by case basis.
    std::cout << "Adding integers: 1 + 2 = " << add(1, 2) << std::endl;
    std::cout << "Adding doubles: 1.0f + 2.5f = " << add(1.0f, 2.5f) << std::endl;
    std::cout << "Adding chars: 'A' + ' ' = " << add('A', ' ') << std::endl;
}