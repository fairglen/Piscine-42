#include <stdlib.h>

int     ft_strlen (char *str)
{
    int     count;
    
    count = 0;
    while (str[count] != '\0')
        count++;
    return (count);
}

char    *ft_strdup  (char *src)
{
    int     i;
    int     size;
    char    *dest;
    
    i = 0;
    size = ft_strlen (src);
    dest = (char *) malloc (size++ * sizeof (char));
    if (dest == NULL)
        return (0);
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
