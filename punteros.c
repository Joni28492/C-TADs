/* Invierte un string con punteros*/
#include <stdio.h>
#include <string.h>
int main(void)
{
 char str1[] = "Los punteros son eficaces pero un poco complejos";
 char str2[80], *p1, *p2;
 /*Hacemos que p1 apunte al final de str1 */
 p1 = str1 + strlen(str1) - 1;
 /*Hacemos que p2 apunte a str2 */
 p2 = str2;
 while(p1 >= str1)
     *p2++ = *p1--;
          /* marca fin de cadena a str2 */
 *p2 = '\0';
 printf("%s / %s", str1, str2);
 getchar();
}
