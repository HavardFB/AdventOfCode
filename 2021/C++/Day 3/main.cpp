#include <iostream>
#include <vector>
#include <fstream>

int powerConsumption (std::vector<std::string> inputs)
{
    std::string mostCommons ="";
    std::string leastCommons="";

    //Loops through each character in the fist line
    for (int i = 0; i < inputs[0].size(); i++)
    {
        int ones = 0;
        //Loops through each line
        for (int j = 0; j < inputs.size(); j++)
        {
            if (inputs[j][i] == '1')
                ones++;
        }
        if (ones > (inputs.size() / 2))
            mostCommons += "1";
        else
            mostCommons += "0";
    }
    //Flips bits in mostCommons to set leastCommons:
    for (int i = 0; i < mostCommons.size(); i++)
    {
        if (mostCommons[i] == '1')
            leastCommons += "0";
        else
            leastCommons += "1";
    }

    int gamma = std::stoi(mostCommons, 0 , 2);
    int epsilon = std::stoi(leastCommons, 0 , 2);

    return gamma*epsilon;
}

int main()
{
    std::ifstream inputFile("day3_input.txt");
    std::vector<std::string> inputs;
    std::string line;

    while(std::getline(inputFile, line))
        inputs.push_back(line);

    // Part 1
    std::cout << "Solution: " << powerConsumption(inputs) << "\n";
    return 0;
}
