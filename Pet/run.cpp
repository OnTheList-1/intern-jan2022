#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Pet.h"


void run()
{
    int flag = 5;
    std::vector<Cat> cat;
    std::vector<Dog> dog;
    do
    {
        std::cout << "Enter 0 to quit.\n";
        std::cout << "Input type:\n\t[1 for cat]\n\t[2 for dog]\n\t[3 to print all cats]\n\t[4 to print all dogs]\n\t[5 to print all pets]\n";
        std::cin >> flag;

        if (flag == 1)
        {
            Cat kitty;
            float num = 0;
            int num1 = 0;
            Date checkup;
            std::string str = "";
            std::cout << "Enter the cat's info: \n";

            std::cout << "Height: ";
            std::cin >> num;
            kitty.setHeight(num);

            std::cout << "Width: ";
            std::cin >> num;
            kitty.setWidth(num);

            std::cout << "Weight: ";
            std::cin >> num;
            kitty.setWeight(num);

            std::cout << "Fur color: ";
            std::cin >> str;
            kitty.setFurColor(str);

            do
            {
                std::cout << "Latest checkup date (mm/dd/yy): ";
                std::cin >> str;
                checkup.insertDateString(str);
                kitty.setDate(checkup);
            } while (!checkup.insertDateString(str));

            std::cout << "Breed: ";
            std::cin >> std::ws;
            std::getline(std::cin, str);
            kitty.setBreed(str);

            std::cout << "Slept time: ";
            std::cin >> num1;
            kitty.setSleptTime(num1);

            kitty.petInfo();
            cat.push_back(kitty);
            std::cout << "Pushed kitty in vector.\n\n";
        }

        if (flag == 2)
        {
            Dog doggo;
            float num = 0;
            int num1 = 0;
            Date checkup;
            std::string str = "";
            std::cout << "Enter the dog's info: \n";

            std::cout << "Height: ";
            std::cin >> num;
            doggo.setHeight(num);

            std::cout << "Width: ";
            std::cin >> num;
            doggo.setWidth(num);

            std::cout << "Weight: ";
            std::cin >> num;
            doggo.setWeight(num);

            std::cout << "Fur color: ";
            std::cin >> str;
            doggo.setFurColor(str);

            do
            {
                std::cout << "Latest checkup date (mm/dd/yy): ";
                std::cin >> str;
                checkup.insertDateString(str);
                doggo.setDate(checkup);
            } while (!checkup.insertDateString(str));

            std::cout << "Breed: ";
            std::cin >> std::ws;
            std::getline(std::cin, str);
            doggo.setBreed(str);

            std::cout << "Play time: ";
            std::cin >> num1;
            doggo.setPlayTime(num1);

            doggo.petInfo();
            dog.push_back(doggo);
            std::cout << "Pushed doggo in vector.\n\n";
        }

        if (flag == 3)
        {
            std::cout << "\n";
            for (int i = 0; i < cat.size(); ++i)
            {
                std::cout << i << ". ";
                cat[i].petInfo();
            }

            std::cout << "\n";
        }

        if (flag == 4)
        {
            std::cout << "\n";
            for (int i = 0; i < dog.size(); ++i)
            {
                std::cout << i << ". ";
                dog[i].petInfo();
            }

            std::cout << "\n";
        }

        if (flag == 5)
        {
            int count = 1;
            std::cout << "\n";
            for (int i = 0; i < cat.size(); ++i)
            {
                std::cout << i << ". ";
                cat[i].petInfo();
            }

            std::cout << "\n";

            for (int i = 0; i < dog.size(); ++i)
                dog[i].petInfo();

            std::cout << "\n";
        }


    } while (flag != 0);
}