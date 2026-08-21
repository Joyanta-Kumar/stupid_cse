#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define JOB_COUNT 5


// define the job
typedef struct Job
{
    char id;
    unsigned int profit;
    unsigned int deadline;
} Job;


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


void showTable(const char *title, Job jobs[], unsigned int count)
{
    printf("\n\e[1;32m%s\e[0m\n", title);

    const unsigned int length = 33;

    hr(length, true);
    printf("| \e[1midx\e[0m\t| \e[1mid\e[0m\t| \e[1mprt\e[0m\t| \e[1mdln\e[0m\t|\n");
    hr(length, true);

    for (unsigned int i = 0; i < count; i++)
    {
        printf("| %d\t| %c\t| %d\t| %d\t|\n", i, jobs[i].id, jobs[i].profit, jobs[i].deadline);
        hr(length, true);
    }
    printf("\n");
}



int main()
{
    // initiage jobs
    Job jobs[JOB_COUNT] = {
        {'a', 25, 2},
        {'b', 17, 2},
        {'c', 6, 1},
        {'d', 13, 1},
        {'e', 30, 3}
    };

    showTable("Input", jobs, JOB_COUNT);

    unsigned max_deadline = 0;

    // sort and get max deadline for the slot array length.
    for (unsigned int i = 0; i < JOB_COUNT; i++)
    {

        if (jobs[i].deadline > max_deadline)
        {
            // max deadline
            max_deadline = jobs[i].deadline;
        }

        for (unsigned int j = 0; j < JOB_COUNT - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                // bubble sort
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    // define slots and it's vacancy.
    Job *slots = calloc(max_deadline, sizeof(Job));
    bool *slotUsed = calloc(max_deadline, sizeof(bool));

    // fill up the slots with greed
    for (unsigned int i = 0; i < JOB_COUNT; i++)
    {
        for (int j = jobs[i].deadline; j >= 0; j--)
        {
            if (!slotUsed[j])
            {
                slotUsed[j] = true;
                slots[j] = jobs[i];
                break;
            }
        }
    }

    showTable("Scheduled", slots, max_deadline);

    return 0;
}
