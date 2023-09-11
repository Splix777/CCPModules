#include <iostream>
#include <fstream>
#include <string>

std::string readReplace(std::string line, std::string& old, std::string& _new)
{
    // Declare a string to hold the final result after replacements
    std::string result;
    // Initialize a variable 'i' to keep track of the current position in 'line'
    size_t      i;
    
    i = 0;
    // Loop through each character in the 'line' string
    while (i < line.length())
    {
        // Check if the substring starting from the current position matches 'old'
        if (line.substr(i, old.size()) == old)
        {
            // If a match is found, append the replacement string '_new' to 'result'
            result += _new;
            // Move the current position 'i' forward by the length of 'old'
            i += old.size();
        }
        else
        {
            // If no match is found, append the current character to 'result'
            result += line[i];
            // Move the current position 'i' forward by one
            i++;
        }
    }
    // Return the final 'result' string after replacements
    return (result);
}

int main(int argc, char **argv)
{

    if (argc != 4 || argv[1] == NULL || argv[2] == NULL || argv[3] == NULL)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string line;
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Error opening input file" << std::endl;
        return (1);
    }
    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cout << "Error opening output file" << std::endl;
        inputFile.close();
        return (1);
    }
    while (std::getline(inputFile, line))
        outFile << readReplace(line, s1, s2) << std::endl;
    inputFile.close();
    outFile.close();
    std::cout << "Replacement completed successfully!" << std::endl;
    return (0);
}
