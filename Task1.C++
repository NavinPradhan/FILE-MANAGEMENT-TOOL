#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

void createFile(const string &filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        cout << "File '" << filename << "' created successfully.\n";
        file.close();
    }
    else
    {
        cout << "Error creating file.\n";
    }
}

void writeFile(const string &filename)
{
    ofstream file(filename);
    string content;
    cout << "Enter text to write into the file (end with ';'):\n";
    cin.ignore(); // clear buffer
    getline(cin, content, ';');
    file << content;
    file.close();
    cout << "Data written successfully.\n";
}

void readFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "File not found.\n";
        return;
    }
    string line;
    cout << "File Content:\n";
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void appendFile(const string &filename)
{
    ofstream file(filename, ios::app);
    string content;
    cout << "Enter text to append (end with ';'):\n";
    cin.ignore(); // clear buffer
    getline(cin, content, ';');
    file << content;
    file.close();
    cout << "Data appended successfully.\n";
}

void deleteFile(const string &filename)
{
    if (remove(filename.c_str()) == 0)
    {
        cout << "File deleted successfully.\n";
    }
    else
    {
        cout << "Error deleting the file.\n";
    }
}

int main()
{
    int choice;
    string filename;

    do
    {
        cout << "\n--- File Management Tool ---\n";
        cout << "1. Create File\n";
        cout << "2. Write to File\n";
        cout << "3. Read File\n";
        cout << "4. Append to File\n";
        cout << "5. Delete File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "Enter filename: ";
        cin >> filename;

        switch (choice)
        {
        case 1:
            createFile(filename);
            break;
        case 2:
            writeFile(filename);
            break;
        case 3:
            readFile(filename);
            break;
        case 4:
            appendFile(filename);
            break;
        case 5:
            deleteFile(filename);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
