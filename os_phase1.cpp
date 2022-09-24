#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
vector<string> M(100);
char R[4] = {-1};
char IR[4] = {-1};
char IC[4] = {-1};
bool C = false;
void init()
{
    M[100];
    R[4];
    IR[4];
    IC[2];
    C = false;
    
}
void memory()
{
    for (int i = 0; i < M.size(); i++)
    {
        cout << "M[" << i << "]" << M[i] << "\n";
    }
}

void loadToMemory(string buffer)
{
    int N = buffer.length();
    int trav = (N / 4) + 1;
    int i = 0;
    int j = 0;
    while (trav--)
    {
        string temp2 = buffer.substr(i, 4);
        i += 4;
        M[j] = temp2;
        j++;
    }
}

int main(int argc, char const *argv[])
{
    int counter = 0;
    ifstream input_file;
    input_file.open("input.txt");
    string buffer;
    while (!input_file.eof())
    {
        getline(input_file, buffer);
        string temp = buffer.substr(0, 4);
        if (temp == "$AMJ")
        {
            cout << "This is control card : ";
            cout << temp << "\n";
            counter++;
            init();
            continue;
            
        }
        else if (temp == "$DTA")
        {
            counter++;
            cout << "Program loaded successfully\n";
            memory();
        }
        else if (temp == "$END")
        {
            cout << "Program ended successfully\n";
        }
        else if (counter != 2 && temp != "$AMJ" && temp != "$DTA" && temp != "$END")
        {
            cout << "This is program card\n";
            loadToMemory(buffer);
            // memory();
            continue;
        }
        else if (counter == 2 && temp != "$AMJ" && temp != "$DTA" && temp != "$END")
        {
            cout << "This is data card\n";
        }
    }

    return 0;
}
