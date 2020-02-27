#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>

void displayFile();
void swapTxt(std::string, std::string);

int main()
{
    std::string choice = "d";

    do
    {
        std::cout << "Welcome to Mo's Todo List" << std::endl;
        std::cout << "a) Display" << std::endl;
        std::cout << "b) Add" << std::endl;
        std::cout << "c) Archive" << std::endl;
        std::cout << "d) Exit" << std::endl;

        std::cin >> choice;

        if(choice=="a")
        {
            displayFile();
        }
        else if(choice=="b")
        {
            std::ofstream myfile;
            std::string addcontent;
            myfile.open("todo.txt", std::ofstream::out | std::ofstream::app);
            if (myfile.is_open())
            {
                std::cout << "What would you like to add?" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, addcontent);
                myfile << addcontent << "\n";
                myfile.close();
            }
        }
        if(choice=="c")
        {
            int neededLine, currLine = 0;
            std::ifstream outfile;
            std::string changecontent;
            std::ofstream editThis("swap.txt");
            outfile.open("todo.txt", std::ofstream::out | std::ofstream::app);

            displayFile();
            std::cout << std::endl;
            std::cout << "Which would you like to archive?" << std::endl;
            std::cin >> neededLine;

            while(std::getline(outfile, changecontent))
            {
                currLine++;
                if(currLine==neededLine)
                    editThis << "(archived) " << changecontent << "\n";
                else
                    editThis << changecontent << "\n";
            }
            editThis.close();
            swapTxt("todo.txt", "swap.txt");
        }

        system("PAUSE > null");
        system("CLS");
    }while(choice!="d");

    return EXIT_SUCCESS;
}

void displayFile()
{
    int num = 0;
    std::ifstream outfile;
    std::string getcontent;
    outfile.open("todo.txt", std::ofstream::out | std::ofstream::app);
    while(std::getline(outfile, getcontent))
    {
        num++;
        if(getcontent.find("(archived)")==std::string::npos)
            std::cout << num << ") " << getcontent << std::endl;
    }
    outfile.close();

    return;
}

void swapTxt(std::string name1, std::string name2)
{
    std::ofstream swapThis(name1);
    std::string changecontent;
    std::ifstream inputfile;
    inputfile.open(name2, std::ofstream::out | std::ofstream::app);

    while(std::getline(inputfile, changecontent))
    {
        swapThis << changecontent << std::endl;;
    }

    return;
}
