#include <stdlib.h>


int     ft_ultimate_range (int **range,int min,int max)
{
    int *buffer;
    int size;
    int i;
    
    i = 0;
    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    size = max - min;
    *range = (int *) malloc (size * sizeof(int));
    if (*range == NULL)
        return(-1);
    buffer = *range;
    while (i <= size)
    {
        buffer[i] = min + i;
        i++;
    }
    return (size);
}
