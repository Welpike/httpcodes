#ifndef UTILS
    #define UTILS

    #include <string>

    namespace Utils
    {
        void start();
        bool listenCommand();
        std::string getNameByKey(int key);
    }

#endif