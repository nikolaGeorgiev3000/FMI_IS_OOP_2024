#include <iostream>
#include <vector>
#include <string>

using namespace std;

void myTestFunc()
{
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Testing my func.\n";
    }
}

int main()
{
    myTestFunc();
    cout << endl;
    // Testing the auto-save feature
}