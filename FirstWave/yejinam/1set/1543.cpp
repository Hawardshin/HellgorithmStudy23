#include <iostream>

#include <string>

int main()

{

    std::string str;

    std::string target;

    int pos = 0;

    int n = 0;

    std::getline(std::cin, str);

    std::getline(std::cin, target);

    while(str.find(target, pos) != std::string::npos)

    {

      pos = str.find(target,pos) + target.size();

       n++;

    }

    std::cout << n;

}
