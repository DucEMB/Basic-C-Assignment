#include "processfunc.h"

void write_to_file(uint8_t animal_type[])
{
    FILE * file = fopen("output.txt","w+");
    fprintf(file,"%s\n",animal_type);
    fclose(file);
}