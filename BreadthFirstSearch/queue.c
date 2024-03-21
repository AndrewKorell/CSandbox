#include <stdio.h>
#include <stdbool.h>
#include "node.h"


#define SIZE 10
void enqueue(int n);
int dequeue();
void show();
bool isholding();
int inp_arr[SIZE];
int Rear = -1;
int Front = -1;

// main()
// {
//     int ch;
//     while (1)
//     {
//         printf("1.Enqueue Operation\n");
//         printf("2.Dequeue Operation\n");
//         printf("3.Display the Queue\n");
//         printf("4.Exit\n");
//         printf("Enter your choice of operations : ");
//         scanf("%d", &ch);
//         switch (ch)
//         {
//             case 1:
//             enqueue();
//             break;
//             case 2:
//             dequeue();
//             break;
//             case 3:
//             show();
//             break;
//             case 4:
//             exit(0);
//             default:
//             printf("Incorrect choice \n");
//         }
//     }
// }

void enqueue(int n)
{
    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else
    {
        if (Front == -1)
            Front = 0;

        printf("\nenqueing node %d", n);
        Rear = Rear + 1;
        inp_arr[Rear] = n;

    }
}

int dequeue()
{
    if (Front == -1 || Front > Rear)
    {

        printf("Underflow \n");
        return -1 ;
    }
    else
    {
        int n = inp_arr[Front];
        Rear = Rear - 1; 
        if(Rear == -1)
        {
            Front = -1;
        }
        else 
        {
            for(int x = 0; x < Rear+1; x++)
            {
                inp_arr[x] = inp_arr[x+1];
            }
        }
        return n;
    }
}

void show()
{

    if (Front == -1)
        printf("\nEmpty Queue \n");
    else
    {
        printf("\nQueue:\n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}

bool isholding()
{
    return Front > -1;
}