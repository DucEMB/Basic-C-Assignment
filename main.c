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
        if(0 == strcmp(type,"cat" ))
        {
            strcpy(animal[animal_num].type,"cat");
            strcpy(animal[animal_num].price,"not for sale");
            animal[animal_num].action = &cat_speak;
            animal[animal_num].action(cat_speak);
            write_to_file(animal[animal_num].type);
        }
        else if(0 == strcmp(type,"dog"))
        {
            strcpy(animal[animal_num].type,"dog");
            strcpy(animal[animal_num].price,"i am your friend");
            animal[animal_num].action = &dog_speak;
            animal[animal_num].action(dog_speak);
            write_to_file(animal[animal_num].type);
        }
        else if(0 == strcmp(type,"pig"))
        {
            strcpy(animal[animal_num].type,"pig");
            strcpy(animal[animal_num].price,"500000");
            printf("my price is 500000\n");
            animal[animal_num].action = &pig_speak;
            write_to_file(animal[animal_num].type);
        }
    }
    return 0;
}