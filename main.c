#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animalstyle.h"
#include "processfunc.h"

int main(void)
{
    animal_t animal[MAX_ANIMAL];
    uint8_t type[10];
    uint8_t animal_num = 0;
    uint16_t price = 0;
    for(animal_num = 0;animal_num < MAX_ANIMAL;animal_num++)
    {
        gets(type);
        switch(type)
        {
            case "cat":
            {
                animal[animal_num].price = {"not for sale"};
                animal[animal_num].action = cat_speak;
                break;
            }
            case "dog":
            {
                animal[animal_num].price = {"i am your friend"};
                animal[animal_num].action = dog_speak;
                break;
            }
            case "pig":
            {
                animal[animal_num].price = {"500000"};
                price = convert_string_to_int(animal[animal_num].price);
                animal[animal_num].action = pig_speak(price);
                break;
            }
            default :
            {
                printf("wrong animal \n");
                break;
            }
        }
    }
    return 0;
}