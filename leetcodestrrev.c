#include <stdio.h>

int main()
{
    char word[100], ch[100];
    int i, index = -1;
    char temp;

    printf("Enter word: ");
    scanf("%s", word);

    printf("Enter character: ");
    scanf("%s", ch);

    for (i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ch[0])
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (i = 0; i < (index + 1) / 2; i++)
        {
            temp = word[i];
            word[i] = word[index - i];
            word[index - i] = temp;
        }
    }

    printf("Result: %s\n", word);

    return 0;
}