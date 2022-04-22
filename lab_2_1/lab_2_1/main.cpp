#include <iostream>
#include "Vector.h"
#include <fstream>

using namespace std;

void FillTheFile(const char*  name_file, int SIZE, int N)
{
    

    //srand(time(NULL));
    ofstream fout(name_file);

    for (int i = 0; i < SIZE; i++)
    {
        int element = rand() % N;
        fout << element << endl;
    }
}

int main()
{
    srand(time(NULL));

    Vector<int> vector = 5;
    for (int i = 0; i<5; i++){
       // int el = rand() % 10;
        vector[i] = i;
    }
    cout << vector;
    cout << "\n";
    {
    Vector<int> vector_copy(vector);
    cout << vector_copy << endl;
        vector_copy[0] = 20;
    }
    cout << vector;
    
   /* const unsigned long int SIZE = 15;
    const int N = 10;
    const char* name_file = "/Users/pavelbelanov/Desktop/lab_2_1/numbers.txt";
    
    FillTheFile(name_file, SIZE, N);
    
    ifstream in;
    in.open(name_file);
    int k = 0;
    int array[N]{};

        while (in >> k)
        {
            array[k]++;
        }
    for (int i=0; i < N; i++)
        cout << array[i] << " ";
    
    cout << "\n";
    for (int i = N-1; i >= 0; i--)
        if (array[i] > 0)
            vector.Append(i);
    
    cout << vector << endl;*/
}
