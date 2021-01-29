#include <stdlib.h>

int     *ft_range(int min,int max)
{
    int *dest;
    int size;
    int i;
    
    i = 0;
    if (min >= max)
        return(0);
    size = max - min;
    dest = (int *) malloc (size * sizeof(int));
    while (i <= size)
    {
        dest[i] = min + i;
        i++;
    }
    return (dest);
}
