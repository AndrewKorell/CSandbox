#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//reference version
void get_message3(char *s);

//dynamic memory version
char *get_message4();

void main()
{

    char *msg1 = "Message 1";

    char *msg2[] = {"Message 2"}; //{ 'M', 'e', 's', 's', 'a', 'g', 'e', ' ', '2' };

    char msg3[256];
    get_message3(msg3);
    // *msg3[1] = 'M';

    char *msg4 = get_message4();

    //msg1 and msg2 are string literals that cannot be modifed
    //should define as const 

    msg3[1] = 'E'; //we can modify the locally created varialable
    msg4[2] = 'S'; //we can modify the string that's in dynamic memory 

    printf("msg1 is %s\n", msg1);
    printf("msg2 is %s\n", *msg2);

    printf("msg3 is %s\n", msg3);

    printf("msg4 to %s\n", msg4);


    printf("sizeof(msg1) is %d\n", sizeof(msg1));
    printf("sizeof(*msg1) is %d\n", sizeof(*msg1));
    printf("sizeof(msg2) is %d\n", sizeof(msg2));
    printf("sizeof(msg3) is %d\n", sizeof(msg3));

    //remember to free dynamic memory 
    free(msg4);
}

void get_message3(char *s)
{
    //string copy is ncessary
    strcpy(s, "message 3");
}

char *get_message4()
{
    char *string = malloc(10);
    strcpy(string, "message 4");
    return string;
}