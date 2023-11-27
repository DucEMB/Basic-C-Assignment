#ifndef ANIMALSTYLE_H
#define ANIMALSTYLE_H

/********* DEFINITION ********/
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

#define MAX_ANIMAL  10u

typedef struct
{
    uint8_t    type[10];
    uint8_t    price[20];
    void       ( *action)(uint32_t);
} animal_t;

#define    CAT    0u
#define    DOG    1u
#define    PIG    2u

/********* END OF DEFINITION *********/

/********* PROTOTYPE *********/
void    cat_speak();
void    dog_speak();
void    pig_speak( uint16_t animal_price);

/********* END OF PROTOTYPE *********/

#endif
/********* END OF FILE *********/