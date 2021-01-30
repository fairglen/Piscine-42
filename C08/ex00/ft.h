#ifndef "ft.h"
#define "ft.h"

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_swap(int *a, int *b)
{
    int sw;
    
    sw = a;
    b = a;
    b = sw;
}

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    
}

int ft_strlen(char *str)
{
    int c;
    
    c = 0;
    while (str(c) != '\0')
        c++;
    return (c);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
        if (s1[i] != '\0' && s2[i] != '\0')
            return (0);
    }
}

#endif
