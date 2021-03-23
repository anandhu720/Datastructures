#include <iostream>
#include <string>
using namespace std;

string Capitalize_first_letter(string text)
{
    for (int x = 0; x < text.length(); x++)
    {
        if (x == 0)
        {
            text[x] = toupper(text[x]);
        }
        else if (text[x - 1] == ' ')
        {
            text[x] = toupper(text[x]);
        }
    }

    return text;
}

int main()
{

    string originalName;
    char name;
    int count = 0;

    cout << "Enter your name: " << endl;
    getline(std::cin, originalName);
    originalName = Capitalize_first_letter(originalName);

    size_t found = originalName.find(" ");
    if (found > originalName.length())
    {
        cout << originalName << endl;
    }
    else
    {
        for (int i = 0; i < originalName.rfind(' '); i++)
        {
            for (name = 65; name <= 90; name++)
            {
                if (originalName[i] == name)
                {
                    cout << name << ".";
                }
            }
        }

        for (int i = originalName.rfind(' ') + 1; i < originalName.size(); i++)
        {
            cout << originalName[i];
        }
    }

    cout << endl;
    return 0;
}
