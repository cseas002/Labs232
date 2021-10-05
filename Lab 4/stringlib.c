/** @file stringlib.c
 *  @brief Implemets different operation on strings
 *
 * This program implements different operation on strings
 *
 * @author 
 * @bug No known bugs.
 */ 

#include <stdio.h>
#include <stdlib.h>


// Macro for converting an uppercase character to lowercase.
#define lcase(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + ('a' - 'A') : (x))


/** @brief Returns the length of string cs, including the '\0' character
 *
 * @param cs The string
 * @return The string length 
 */
int strlength(const char *cs);


/** @brief Copies string ct to string s and returns s.
 *
 * @param cs The string to copy
 * @param ct The string to be copied
 * @return Returns the new string
 */
char *strcopy(char *s, const char *ct);


/** @brief Concatenates string ct to the end of string s. Returns s.
 *
 * @param cs The first string 
 * @param ct The string to concatenate to the first string
 * @return Returns the new string
 */
char *strconcat(char *s, const char *ct);


/** @brief Case INSENSITIVE comparison of two strings
 *
 * @param cs The first string 
 * @param ct The second string
 * @return Returns -1 if cs < ct, 0 if cs == ct and 1 if cs > ct.
 */
int strcompare(const char *cs, const char *ct);


/** @brief Substring finding
 *
 * @param cs The first string 
 * @param ct The second string
 * @return A pointer to the first occurrence of string ct in string cs, or NULL if not found.
 */
char *stringstring(const char *cs, const char *ct);


/** @brief String parsing
 *
 * @param cs The  string 
 * @return  Returns the numeric value of string cs.
 */
double val(const char *cs);


/*
 * Define the functions below
 */


int main(void) {

  char *s1 = "String";
  char *s2 = "ring";
  
  char *s3 = (char *) malloc(11 * sizeof(char));
  char *s4;
  int l, c;
  
  s3 = strcopy(s3, s1);
  printf("strcopy(s3, \"%s\") = \"%s\"\n", s1, s3);
  
  c = strcompare(s3, s1);
  printf("strcompare(\"%s\", \"%s\") = %d\n", s3, s1, c);
  
  s3 = strconcat(s3, s2);
  printf("strconcat(s3, \"%s\") = \"%s\"\n", s2, s3);
  
  l = strlength(s3);
  printf("strlength(\"%s\") = %d\n", s3, l);
  
  c = strcompare(s1, s2);
  printf("strcompare(\"%s\", \"%s\") = %d\n", s1, s2, c);
  
  c = strcompare(s2, s1);
  printf("strcompare(\"%s\", \"%s\") = %d\n", s2, s1, c);
  
  s4 = stringstring(s1, s2);
  printf("stringstring(\"%s\", \"%s\") = ", s1, s2);
  
  if (s4) printf("\"");
  
  printf("%s", s4 ? s4 : "NULL");
  
  if (s4) printf("\"");
  
  printf("\n");
  
  s4 = stringstring(s3, s1);
  printf("stringstring(\"%s\", \"%s\") = ", s3, s1);
	
  if (s4) printf("\"");
  
  printf("%s", s4 ? s4 : "NULL");
  
  if (s4) printf("\"");
  
  printf("\n");
  
  s4 = stringstring(s1, s3);
  printf("stringstring(\"%s\", \"%s\") = ", s1, s3);
  
  if (s4) printf("\"");
  
  printf("%s", s4 ? s4 : "NULL");
  
  if (s4) printf("\"");
  
  printf("\n");
  
  printf("val(\"%s\") = %lf\n", "+11111.000005", val("+11111.000005"));
  printf("val(\"%s\") = %lf\n", "-11111.000005", val("-11111.000005"));
  printf("val(\"%s\") = %lf\n", "11111.000005", val("11111.000005"));
  printf("val(\"%s\") = %lf\n", "12345", val("12345"));
  
  return 0;
}

int strlength(const char *cs)
{
	int i, length = 0;
	for (i = 0; i < 9999999999999; i++)
		if (*(cs + i) == '\0')
			return length;
		else
			length++;
	
	return -1;
}

char *strcopy(char *s, const char *ct)
{
	int i;
	char* str = (char *) malloc(strlength(ct) + 1);
	for (i = 0; i < strlength(ct); i++)
		*(str + i)= *(ct + i);
	
	*(str + strlength(ct)) = '\0';
	
	return str;
}

char *strconcat(char *s, const char *ct)
{
	int i;
	char* str = (char *) malloc(strlength(s) + strlength(ct) + 1);
	for (i = 0; i < strlength(s); i++)
		*(str + i) = *(s + i);
	
	for (i = 0; i < strlength(ct); i++)
			*(str + i + strlength(s)) = *(ct + i);
	*(str + strlength(s) + strlength(ct)) = '\0';
	
	return str;
	
}

int strcompare(const char *cs, const char *ct)
{
	int result;
	if (strlength(cs) > strlength(ct))
		result = 1;
	else if (strlength(cs) < strlength(ct))
		result = -1;
	else
		result = 0;
	
	return result;
}

char *stringstring(const char *cs, const char *ct)
{
	int i, j;
	for (i = 0; i < strlength(cs); i++)
		if (*(cs + i) == *ct)
			for (j = 0; j < strlength(ct); j++)
 				if (*(cs + i + j) != *(ct + j))
 					break;
 				else if (j == strlength(ct) - 1)
 					return (cs + i);
	
	return NULL;
} 

double pow(double x, double y)
{
	int i;
	double ans = 1;
	if (y >= 0)
		for (i = 0; i < y; i++)
			ans *= x;
	else
		for (i = 0; i > y; i--)
			ans /= x;
	return ans;
}

double val(const char *cs)
{
	int i, negative = 0, foundSign = 0;
	double value = 0, decimalPlaces = 0;
	char* decimals = stringstring(cs, ".");
	for (i = 1; i < strlength(decimals); i++)
		decimalPlaces += (*(decimals + i) - 48) * pow(10, -i);
	for (i = 0; i < strlength(cs) - strlength(decimals); i++)
		if (*(cs + i) == '+')
		{
			foundSign = 1;
			continue;
		}
		else if (*(cs + i) == '-')
		{
			foundSign = 1;
			negative = 1;
		}
			else if (foundSign == 0)
				value += (*(cs + i) - 48) * pow(10, i);
				else
					value += (*(cs + i) - 48) * pow(10, i - 1);
	value += decimalPlaces;

	if (negative)
		value = -value;
	
	return value;
}
