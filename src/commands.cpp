#include <iostream>

#include "includes/commands.hpp"
#include "includes/utils.hpp"

void Commands::name()
{
    std::string input;
    int http_status;

    std::cout << "\n-- Name --\n";

    std::cout << "\nCode : ";

    std::cin >> input;
    std::cin.ignore(255, '\n');

    http_status = atoi(input.c_str());  // convert std::string -> int

    if(http_status >= 100 && http_status <= 599)  // if user input -> 99 < x < 600
    {
        std::string name{ Utils::getNameByKey(http_status) };
        std::cout << "\nHTTP Status : " << name << " \nMore informations at https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/" << input << std::endl;
    }
    else
    {
        std::cout << "This is not a correct http status code." << std::endl;
    }
}

void Commands::help()
{
    std::cout << "\n-- Help --\n";
    std::cout << "- name -> ask for an code\n- help -> shows this message\n- credits -> shows credits\n- exit -> exits properly" << std::endl;
}

void Commands::credits()
{
    std::cout << "\n-- Credits --\n";
    std::cout << "License : MIT \nAuthor : Welpike (https://github.com/Welpike) \nMade with C++20 and compiled with g++.\nDatas from MDN web docs (https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)." << std::endl;
}

void Commands::exit()
{
    std::cout << "\n-- Exit --\n";
    std::cout << "Bye." << std::endl;
}
