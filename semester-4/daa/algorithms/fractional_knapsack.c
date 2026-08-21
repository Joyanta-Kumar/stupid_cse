#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OBJ_COUNT 5
#define CAPACITY 6.5F

// define the Obj
typedef struct Obj
{
    char id;
    float profit;
    float weight;
    float ratio;
    float taken;
} Obj;

void hr(unsigned int length, bool newLine)
{
    for (unsigned int i = 0; i < length; i++)
    {
        printf("-");
    }
    if (newLine)
    {
        printf("\n");
    }
}

void showTable(const char *title, Obj obj[], unsigned int count)
{
    printf("\n\e[1;32m%s\e[0m\n", title);

    const unsigned int length = 1 + 6 * 8;

    hr(length, true);
    printf("| \e[1mindex\e[0m\t| \e[1mid\e[0m\t| \e[1mproft\e[0m\t| \e[1mwegt\e[0m\t| \e[1mrato\e[0m\t| \e[1mtakn\e[0m\t|\n");
    hr(length, true);

    for (unsigned int i = 0; i < count; i++)
    {
        printf("| %d\t| %c\t| %.1f\t| %.1f\t| %.1f\t| %.1f\t|\n",
               i, obj[i].id, obj[i].profit, obj[i].weight, obj[i].ratio, obj[i].taken);
        hr(length, true);
    }
    printf("\n");
}

int main()
{
    // initiage objs
    Obj objects[OBJ_COUNT] = {
        {'a', 25, 4},
        {'b', 17, 3},
        {'c', 6, 1},
        {'d', 13, 2},
        {'e', 30, 3}};

    Obj knapsack[OBJ_COUNT];

    for (unsigned int i = 0; i < OBJ_COUNT; i++)
    {
        objects[i].ratio = objects[i].profit / objects[i].weight;
        objects[i].taken = 0.0;
    }

    float remainingCapacity = CAPACITY;
    float totalProfit = 0.0F;
    showTable("Input", objects, OBJ_COUNT);
    printf("Total weights: %g\n", CAPACITY);
    printf("Total profits: %g\n", totalProfit);

    // sort desc by profit / weight
    for (unsigned int i = 0; i < OBJ_COUNT; i++)
    {
        for (unsigned int j = 0; j < OBJ_COUNT - i - 1; j++)
        {
            if (objects[j].ratio < objects[j + 1].ratio)
            {
                // bubble sort
                Obj temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }

    for (unsigned int i = 0; i < OBJ_COUNT && remainingCapacity > 0; i++)
    {
        if (objects[i].weight <= remainingCapacity)
        {
            // take full
            objects[i].taken = objects[i].weight;
        }
        else
        {
            // take fraction
            objects[i].taken = remainingCapacity;
        }
        remainingCapacity -= objects[i].taken;
        totalProfit += objects[i].taken * objects[i].ratio;
    }

    showTable("Output", objects, OBJ_COUNT);
    printf("Total weights: %g\n", CAPACITY);
    printf("Total profits: %g\n", totalProfit);

    return 0;
}
