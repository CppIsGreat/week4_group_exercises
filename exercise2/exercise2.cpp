//
// Created by Tristan Brindle on 24/10/2017.
// Hacked by Neil Burman on 2017-10-31.
//

#include <vector>
#include <string>

#include "exercise2.hpp"

// Requirements:
//   -- given an uppercase character A-Z, shifts that character by 13 places
//   -- spaces, numbers and punctuation should not be changed

char shift_char(char c)
{
    // Set up the character set and find the position of the input character
    const char charset [] {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const char *charPos = strchr(charset, c);

    // The offset MUST be +ve - put it here in case it needs to be changed
    const int offset {13};

    // If input character found
    if (charPos != nullptr)
    {
        // Get the size of the character set array - makes it easier for adding new elements
        const int sizeOfArray = static_cast<int>((sizeof(charset) / sizeof(charset[0]))) - 1;

        // Get the position of the next character - wrapping around
        const auto nextChar = ((charPos - charset) + offset) % sizeOfArray;

        // We're done
        return (charset[nextChar]);
    }

    // Character not found so return what was passed in
    return (c);
}

// Shameless overload :)
char shift_char(char c, const int& offset)
{
    // Set up the character set and find the position of the input character
    const char charset [] {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const char *charPos = strchr(charset, c);

    // If input character found
    if (charPos != nullptr)
    {
        // Get the size of the character set array - makes it easier for adding new elements
        const int sizeOfArray = static_cast<int>((sizeof(charset) / sizeof(charset[0]))) - 1;

        // Get the position of the next character - wrapping around
        auto nextChar = ((charPos - charset) + offset) % sizeOfArray;

        // Adjust if negative
        if (nextChar < 0)
            nextChar += sizeOfArray;

        // We're done
        return (charset[nextChar]);
    }

    // Character not found so return what was passed in
    return (c);
}


// Requirements:
//   -- given a string consisting of uppercase characters and punctuation,
//      returns a new string with each character shifted by 13 places
//   -- spaces, numbers and punctuation should not be changed
std::string rot13(std::string str)
{
    // The output vector
    std::string newString {};

    for (auto iCount = 0; iCount < str.size(); iCount++)
    {
        // Keep this on two lines for easier debugging
        const char s = shift_char(str.at(iCount));
        newString.push_back(s);
    }

    return (newString);
}

// Requirements:
//   -- given a string consisting of uppercase characters and punctuation,
//      returns a new string with each character shifted by n places
std::string encode(std::string str, int n) {
    // The output vector
    std::string newString{};

    for (auto iCount = 0; iCount < str.size(); iCount++)
    {
        // Keep this on two lines for easier debugging
        const char s = shift_char(str.at(iCount), n);
        newString.push_back(s);
    }

    return (newString);
}

// Requirements:
//   -- given a string generated by encode(str, n), returns the original string
std::string decode(std::string str, int n)
{
    // Negate the offset and encode
    return (encode(str, -n));
}