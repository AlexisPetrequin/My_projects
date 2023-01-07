/*
** EPITECH PROJECT, 2019
** my_lib
** File description:
** library
*/

void my_putchar (char c) ;
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char const *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int nb);
char *my_strupcase(char *str) ;
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_calc(int nb1, int nb2, char op);
char *modstr(char *str, int posi, int i, int res);
char *str_modif(char *src);
char *numstr(int res);
int number(char *str);
char *plus(char *str, int i, char *bases);
char *modulo(char *str, int i, char *bases);
char *divs(char *str, int i, char *bases);
char *times(char *str, int i, char *bases);
int my_cnbr_int(char *str, int num, int len1, int len2);
char *my_infnbr(char *str, int len);
void display_number(float i);
