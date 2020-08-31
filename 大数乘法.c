char * multiply(char * num1, char * num2)
{
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int total = length2 + length1;
    int *value = (int *)malloc(sizeof(int) * total);
    int i, j, valueIndex = 0, charIndex = 0;
    memset(value, 0, sizeof(int) * total);
    char *res = (char *)malloc((total + 1) * sizeof(char));
    for (i = length1 - 1; i >= 0;i--)
    {
        for ( j = length2 - 1; j >= 0 ; j--)
        {
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (i = total - 1; i > 0 ; i--)
    {
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }
    res[total] = '\0';
    while (total--)
        res[total] = value[total] + '0';
    for (i = 0; res[i] == '0'; i++)
        ;
    free(value);
    return (i == strlen(res)) ? "0":(res + i);
    
}