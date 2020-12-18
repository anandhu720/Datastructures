#include <stdio.h>
#include <string.h>

struct census
{
    char city[100];
    int population;
    float literacy;
};

int main()
{
    struct census c[10], temp;

    for (int i = 0; i < 5; i++)
    {
        printf("enter the city name\n");
        scanf("%s", &c[i].city);
        printf("enter the population\n");
        scanf("%d", &c[i].population);
        printf("enter the literacy rate\n");
        scanf("%f", &c[i].literacy);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(c[i].city, c[j].city) > 0)
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("the city is %s\nthe population is %d\nthe literacy is %f\n\n", c[i].city, c[i].population, c[i].literacy);
    }
    return 0;
}