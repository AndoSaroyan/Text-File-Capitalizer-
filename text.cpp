#include <iostream>
#include <fstream>

std::string capitalizeCharStr(std::string &givenString)
{
    for (int i = 0; i < givenString.length(); i++)
    {
        if (i == 0 || i == givenString.length() - 1)
        {
            givenString[i] = toupper(givenString[i]);
        }
        else if (givenString[i] == ' ')
        {
            givenString[i - 1] = toupper(givenString[i - 1]);
            givenString[i + 1] = toupper(givenString[i + 1]);
        }
        else if(givenString[i]=='\n'){
            givenString[i - 1] = toupper(givenString[i - 1]);
            givenString[i + 1] = toupper(givenString[i + 1]);
        }
        

        
    }
    return givenString;
}

int main(int argc,char*argv[])
{    
   std::string st;
   std::string str;

    if (argc > 1) {
        std::cout << "argv[1] = " << argv[1] << std::endl; 
    } else {
        std::cout << "Error(existing file)...";
        return -5;
    }
    std::ifstream ifs(argv[1]);
     
    
    if (ifs.is_open()) {

        while(!ifs.eof()){
            getline(ifs,st);
            str+=st+ "\n";
        }
        std::cout<< str;
         
        
        ifs.close();
    } else {
        std::cout << "Unable to open ...";
    }
       
        std::ofstream ofs;
        ofs.open(argv[1]);
    std::cout<< capitalizeCharStr(str);
        ofs << str;
        ofs.close();

}