#include <iostream>
#include <string>
#include <array>

#include <fstream>
#include <filesystem>  // for getting the datas.txt path

#include "includes/utils.hpp"
#include "includes/commands.hpp"

void Utils::start()
{
    std::cout << "--------------------- httpcodes ---------------------" << std::endl;

    std::cout << "Commands : " << std::endl;

    std::cout << "- name\n- help\n- credits\n- exit" << std::endl;
}

bool Utils::listenCommand()
{
    using namespace std::literals;

    bool loop {true};
    
    std::cout << "httpcodes> ";
    std::string cmd;
    std::cin >> cmd;
    
    if(cmd == "name"s)
    {
        Commands::name();
    }
    else if(cmd == "help"s)
    {
        Commands::help();
    }
    else if(cmd == "credits"s)
    {
        Commands::credits();
    }
    else if(cmd == "exit"s)
    {
        Commands::exit();
        loop = false;
    }
    else{
        std::cout << "Unknown command." << std::endl;
    }

    return loop;
}

std::string Utils::getNameByKey(int key)
{
    std::fstream file;
    std::string name{""};

    file.open(std::filesystem::current_path().string() + "\\src\\datas\\table.txt", std::ios::in);

    if (file.is_open()){
        std::string tp;
        while(getline(file, tp)){
            std::string delimiter{"|"};
            std::string tp_key{ tp.substr(0, tp.find(delimiter)) };

            if(atoi(tp_key.c_str()) == key)
            {
                name = tp.substr(4, tp.length());
            }
        }
        file.close();
    }
    else
    {
        std::cout << "An error occured during the opening of the datas file." <<std::endl;
    }

    return name;
}
