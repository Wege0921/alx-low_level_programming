#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getRandomChar()
{
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];
}

void generateRandomPassword(char *password, int length)
{
    for (int i = 0; i < length; i++)
    {
        password[i] = getRandomChar();
    }
    password[length] = '\0';
}

int isValidPassword(char *password)
{
    int length = 0;
    while (password[length] != '\0')
    {
        length++;
    }
    return length >= 6;
}

int main()
{
    srand(time(0));

    char password[50];

    do
    {
        generateRandomPassword(password, 10);
    } while (!isValidPassword(password));

    printf("Random Password: %s\n", password);

    return 0;
}
