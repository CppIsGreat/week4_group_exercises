
#include "exercise3.hpp"

// Requirements:
//   -- Given a string containing elements separated by commas, return a
//      vector of strings containing each element
// For example
//    split("a,b,c") -> vector<string>("a", "b", "c");

std::vector<std::string> split(const std::string& str)
{
    // The output vector
    std::vector<std::string> outData {};

    // Check if string is not empty
    if (!str.empty())
    {
        // Make a copy of the input string as it is immutable
        std::string csvString{str};

        // The delimiter
        const std::string delimiter = ",";

        // Initialise
        size_t delimiterPos = 0;

        // While there are delimiters
        while ((delimiterPos = csvString.find(delimiter)) != std::string::npos)
        {
            // Push back to the next delimiter then erase the string to after the delimiter
            outData.push_back(csvString.substr(0, delimiterPos));
            csvString.erase(0, delimiterPos + delimiter.length());
        }
        // push back the last string (i.e. what's left)
        outData.push_back(csvString);
    }

    return {outData};
}

// An element which is enclosed in double quotes should be treated as a single element,
// even if it contains a comma. For example,
//
//  ""a, b",c,d" contains three elements
//
// Requirements:
//   -- Split the given string into its component elements, treating quoted
//      elements as a single unit

std::vector<std::string> quoted_split(const std::string& str) {
    // The output vector
    std::vector<std::string> outData{};

    // Check if string is not empty
    if (!str.empty()) {
        // Make a copy of the input string as it is immutable
        std::string csvString{str};

        // The delimiter
        const std::string comma = ",";
        const std::string quote = "\"";

        // Find the positions of the quote and comma
        size_t commaPos = csvString.find(comma);
        size_t quotePos = csvString.find(quote);

        // Initialise with comma delimiter
        std::string delimiter = comma;
        size_t delimiterPos{0};

        // If quote before comma - set quote as the delimiter
        if (quotePos < commaPos)
            delimiter = quote;

        // While there are delimiters (until the end of the string)
        while ((delimiterPos = csvString.find(delimiter)) != std::string::npos) {

            // If it's a quote, capture to the next quote
            if (delimiter == quote) {
                // Erase the quote
                csvString.erase(0, delimiterPos + delimiter.length());
                delimiterPos = csvString.find(delimiter);
            }

            // Get the string ready to store
            std::string dataString = csvString.substr(0, delimiterPos);

            // If something to store - do it - removing any leading and trailing spaces
            if (!dataString.empty())
                outData.push_back(std::regex_replace(dataString, std::regex("^ +| +$"), ""));

            // Erase that bit of the string
            csvString.erase(0, delimiterPos + delimiter.length());

            // See which comes next
            commaPos = csvString.find(comma);
            quotePos = csvString.find(quote);

            if (quotePos < commaPos)
                delimiter = quote;
            else
                delimiter = comma;

        }
        // push back the last string (i.e. what's left - if anything) - removing any leading and trailing spaces
        if (!csvString.empty())
            outData.push_back(std::regex_replace(csvString, std::regex("^ +| +$"), ""));
    }

    return {outData};
}

// A CSV file consists of multiple lines, each of which should be split
// according to the above rules. Given an input stream istream, return
// a `csv_file` containing each line of the input, split correctly
csv_file parse_csv(std::istream& istream)
{
    std::string str {};

    // For storing the output result
    std::vector<std::vector<std::string>> csvFile {};
    csv_file outFile {};

    // For each line of input
    while (std::getline(istream, str))
    {
        csvFile.push_back(quoted_split(str));
    }

    // Copy the result to the struct
    outFile.lines = csvFile;

    return (outFile);
}