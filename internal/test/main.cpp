#include <test/run>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

void anykey()
{
    std::cout << "\n > Press any key to exit... ";
    getch();
}

int main()
{
    atexit(anykey);
    test::run();
    return 0;
}
