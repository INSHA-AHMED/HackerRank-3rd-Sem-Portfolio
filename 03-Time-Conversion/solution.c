#include <stdio.h>

int main()
{
    char s[11];

    scanf("%s", s);

    int hour = (s[0] - '0') * 10 + (s[1] - '0');

    if (s[8] == 'A')
    {
        if (hour == 12)
            hour = 0;
    }
    else
    {
        if (hour != 12)
            hour += 12;
    }

    printf("%02d%c%c%c%c%c%c\n",
           hour,
           s[2], s[3], s[4],
           s[5], s[6], s[7]);

    return 0;
}
