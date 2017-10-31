#include <vector>       // std::vector
#include <functional>   // std::greater

#include "exercise1.hpp"

// Requirements:
//   -- if i is even, returns true
//   -- if i is odd, returns false
bool is_even(int i)
{
    return ((i % 2) == 0);
}

// Requirements:
//   -- returns the number of odd numbers in the given vector
int count_odd(const std::vector<int>& vec)
{
    int numCount {0};

    for ( const auto number : vec )
    {
        if (!is_even(number))
            numCount++;
    }

    return (numCount);
}

// Requirements:
//   -- returns the sum of the even numbers in the vector
int even_sum(const std::vector<int>& vec)
{
    int numSum {0};

    for ( const auto number : vec )
    {
        if (is_even(number))
            numSum += number;
    }
    return (numSum);
}

// Requirements:
//   -- returns a new vector containing only the elements of vec which are
//      divisible by p
std::vector<int> copy_if_divisible_by(const std::vector<int>& vec, int p)
{
    std::vector<int> outputVec {};

    for ( const auto number : vec )
    {
        if ( number % p == 0)
            outputVec.push_back(number);
    }

    return (outputVec);
}

// Requirements:
//   -- returns the largest number in the vector which is divisible by 3, or
//      zero if there are no such numbers
int largest_div_by_three(const std::vector<int>& vec)
{
    // Initialise the return value
    int bigNum {0};

    // Copy the vector and sort into descending order
    std::vector<int> workCopy = vec;
    std::sort(workCopy.begin(), workCopy.end(), std::greater<int>());

    // Find the first number divisible by 3 then exit
    for ( const auto number : workCopy )
    {
        if (number % 3 == 0)
        {
            bigNum = number;
            break;
        }
    }
    return (bigNum);
}

// Requirements:
//   -- returns true if the elements in vec are sorted, and false otherwise
bool is_sorted(const std::vector<int>& vec)
{
    return (std::is_sorted(vec.begin(), vec.end()));
}