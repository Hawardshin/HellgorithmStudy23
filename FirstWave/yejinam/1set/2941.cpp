#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::string target;
    std::string arr[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    int i = 0;
  int n = 0;
    std::getline(std::cin, str);
    while(i < str.size())
    {
      int j;
      for(j = 0; j < 8; j++)
        {
        if (str.find(arr[j], i) == i)
        {
//        std::cout<<i;
          i += arr[j].size() - 1;
          n++;
          break;
        }
        }
      if(j == 8)
        n++;
       i++;
    }
    std::cout << n;
}
