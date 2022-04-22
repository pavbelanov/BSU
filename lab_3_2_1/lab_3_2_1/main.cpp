#include <iostream>
#include <vector>
#include <fstream>


std::string file_for_read = "/Users/pavelbelanov/Desktop/lab_3_2_1/lab_3_2_1/numbers.txt";

void FillTheFile()
{
    const unsigned long int SIZE = 100000;
    const int N = 10000;

    std::ofstream fout(file_for_read, std::ios::out);

    for (int i = 0; i < SIZE; i++)
    {
        int element = rand() % N;
        fout << element << std::endl;
    }
}

void FillTheVector(std::vector<int> &vectorForNumbers)
{
    std::ifstream in;
    in.open(file_for_read);
    int k = 0;
    int numbersArray[10001]{};

    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> k;
            numbersArray[k]++;
        }
    }

    for (int i = 10000; i > 0; i--)
        if (numbersArray[i] != numbersArray[i + 1])
            vectorForNumbers.push_back(i - 1);
}

void PrintTheVector(const std::vector<int> &vectorWithNumbers)
{
    for (auto c : vectorWithNumbers)
        std::cout << c << " ";
}

int main()
{
    srand(time(NULL));
    
    std::vector<int> vectorForNumbers;
    
    FillTheFile();
    
    FillTheVector(vectorForNumbers);
    
    PrintTheVector(vectorForNumbers);

    return 0;
}
