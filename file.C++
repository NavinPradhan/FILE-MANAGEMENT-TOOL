#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char ch;
    fstream file;
    file.open("demo.txt",ios::in);
    while(file.get(ch))
    {
        cout << ch;
    }
    cout << endl;
    return 0;
}
