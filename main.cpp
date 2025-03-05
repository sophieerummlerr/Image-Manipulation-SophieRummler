#include <fstream>
#include <iostream>
using namespace std;

// Different OSs use different CLI commands to run Python
#ifdef _WIN32
// TODO: If your Windows machine runs Python in CLI with "python" instead of "py", update this line.
const string python = "py";
#else
// TODO: If your Mac/Linux machine runs Python in CLI with "python3" instead of "python", update this line.
const string python = "python3";
#endif

/*
 * Prompts the user for a filename.
 * Allows the user to enter nothing to use the default pic (autumn.jpg).
 * If the file has extension jpg, jpeg, jpe, or png
 * and it exists in the project folder, return it.
 * Otherwise, return the default pic filename.
 * Hint: Use ../ before the filename when trying to open it.
 */
string get_filename()
{
    string filename;
    cout << "Enter an image filename (or press Enter to use the default 'autumn.jpg'): ";
    getline(cin, filename);

    if (filename.empty())
    {
        return "autumn.jpg";
    }

    ifstream file("../" + filename);
    if (!file)
    {
        cout << "File not found! Using default image.\n";
        return "autumn.jpg";
    }

    return filename;
}

/*
 * Prints the main menu of options:
 * (a) flip, (b) mirror, (c) invert, or (d) exit
 */
void print_menu()
{
    cout << "Choose an imagine manipulation option:\n";
    cout << "(a) Flip\n";
    cout << "(b) Mirror\n";
    cout << "(c) Invert\n";
    cout << "(d) Exit\n";
}

char get_manip_choice()
{
    char choice;
    while (true)
    {
        cout << "Enter your choice (a/b/c/d): ";
        cin >> choice;
        cin.ignore();

        if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')
        {
            return choice;
        } else
        {
            cout << "Invalid input! Please enter a, b, c, or d.\n";
        }
    }
}

int main() {
    cout << "Welcome to the image manipulator!" << endl;
    string filename = get_filename();
    cout << "Using file " << filename << "." << endl;
    print_menu();
    char choice = get_manip_choice();

    if (choice == 'd')
    {
        cout << "Exiting program. Bye bye!" << endl;
        return 0;
    }

    cout << "Processing. Go to Python program when it opens. May ake a few seconds." << endl;
    string command;

    switch (choice)
    {
    case 'a':
        command = python + " render.py " + filename + " flip";
        break;
    case 'b':
        command = python + " render.py " + filename + " mirror";
        break;
    case 'c':
        command = python + " render.py " + filename + " invert";
        break;
    default:
        cout << "Unexpected error!" << endl;
        return 1;
    }
    system(command.c_str());
    return 0;
}
