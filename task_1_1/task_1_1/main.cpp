#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

// создание текстового файла cлучайных целых чисел
void create_F_file(ofstream &fileF, int n)
{
    for (int i = 1; i <= n;  i++)
    {
        int v = rand()%200 - 100;
        fileF.write((char*)&v, sizeof(int));
        //fileF << v << endl;    // запись целых чисел в файл
                               // каждое число в новой строке
    }
}

void create_G_plus(ifstream &file_two_F, ofstream &fileG)
{
    int x;
    while (file_two_F >> x)
    //while (file_two_F.read((char*)&x, sizeof(int)))
    {
        if (x > 0) {
            fileG << x << "\n";
        }
    }
}

void create_G_minus(ifstream &file_three_F, ofstream &fileG)
{
    int x;
    while (file_three_F >> x)
    {
        if (x < 0) {
            fileG << x << "\n";
        }
    }
}

void file_for_terminal (file_name)
{
    ifstream fileF(file_name);
    cout << "file " << fileF << ":\n";
    int y;
    while (fileF >> y) {
        cout << y << " ";
    }
    cout << endl;
}

int main()
{
    string file_f_str = "/Users/pavelbelanov/Desktop/task_1_1/task_1_1/F.txt";
    string file_g_str ="/Users/pavelbelanov/Desktop/task_1_1/task_1_1/G.txt";
    srand((unsigned)time(NULL));
    int n;
    cout << "enter n -  ";
    cin >> n;               // количество чисел файла
    cout << endl;
                       // cоздадим текстовый файл cл. чисел
    //ofstream fileF(file_f_str);
    ofstream fileF(file_f_str);
    if (!fileF)
       {
           cout << "Error1" << endl;
        return 1;
       }
    
    create_F_file(fileF, n);
    fileF.close();
    
    ifstream file_two_F(file_f_str);
    ofstream fileG(file_g_str);
    if (!fileG)
    {
        cout << "Error2" << endl;
        return 1;
    }

    create_G_plus(file_two_F, fileG);
    file_two_F.close();
    
    file_two_F.open(file_f_str);
    create_G_minus(file_two_F, fileG);
    file_two_F.close();
    fileG.close();
    
    file_for_terminal(file_f_str);
    
    file_for_terminal(file_g_str);
    
    cout << "runtime = " << clock()/1000.0 << endl;
    return 0;
    
}
