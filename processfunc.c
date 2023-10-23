#include "processfunc.h"

uint16_t convert_string_to_int(uint8_t animal_price[])
{
    uint8_t length = strlen(price);
    uint8_t i = 0;
    uint16_t res_price = 0;
    uint16_t n = 0;
    for(i = length;i >= 0;i++)
    {
        res_price += price[i]*pow(10,0);
        n++;
    }
}

void write_to_file(uint8_t animal_type[])
{
    uint8_t i = 0;
    FILE * file = fopen("output.txt","w+");
    for(i = 0;i < strlen(animal_type);i++)
    {
        fprintf(file,"%c",animal_type[i]);
    }
    fclose(file);
}