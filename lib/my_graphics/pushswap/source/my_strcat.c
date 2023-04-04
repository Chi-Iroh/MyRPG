/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_strcat.c
*/

void my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return;
}

int my_strcat(char *dest, char const *src, int i)
{
    int j;
    for (; dest[i] != '\0'; i++){
    }
    for (j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return i;
}
