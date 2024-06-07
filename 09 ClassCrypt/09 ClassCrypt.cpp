#include <iostream>
#include "ClassCrypt.h"

int main()
{
    std::cout << "09 ClassCrypt\n";
    ClassCrypt* pCrypt = new ClassCrypt();
    pCrypt->Crypt();
    pCrypt->Decrypt();
}
