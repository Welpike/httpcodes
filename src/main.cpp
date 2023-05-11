#include <iostream>

#include "includes/utils.hpp"
#include "includes/commands.hpp"

int main()
{
    bool loop {true};

    Utils::start();

    do
    {
        loop = Utils::listenCommand();
    } while(loop);

    return 0;
}