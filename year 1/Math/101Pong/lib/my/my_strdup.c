/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *str)
{
	int len;
	char* newstr;

	len = my_strlen(str) + 1;
	newstr = malloc(len);
	if(newstr == NULL)
		return (NULL);
	newstr = my_strcpy(newstr, str);
	return (newstr);
}