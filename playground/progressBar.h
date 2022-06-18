#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Prints a progress bar, open in another thread
 * @param[in] curr         Required  : Address in which the current iteration is stored
 * @param[in] total        Required  : total iterations
 * @param[in] prefix       Optional  : prefix string
 * @param[in] suffix       Optional  : suffix string
 * @param[in] fill         Optional  : bar fill character
 * @param[in] empty        Optional  : bar empty character
 * @param[in] container    Optional  : pair of characters used to container the bar
 * @param[in] length       Optional  : length of progress bar
 * @return None
 */
void progressbar(int *curr, const int total,
                 const char *prefix = "", const char *suffix = "",
                 const char fill = '>', const char empty = ' ', const char *container = "[]",
                 const int length = 50)
{
    if (strnlen(container, 3) != 2)
    {
        perror("\nprogressbar(): Error: Container must be a pair of characters\n");
        exit(1);
    }

    char *bar = (char *)calloc(length + 1, sizeof(char));

    while (*curr <= total)
    {
        int percent = 100 * *curr / total, filledLength = length * *curr / total;

        memset(bar, fill, filledLength);
        memset(bar + filledLength, empty, length - filledLength);

        printf("\r%s %c%s%c %d%% %s", prefix, container[0], bar, container[1], percent, suffix);
        fflush(stdout);

        usleep(10000);
    }

    memset(bar, fill, length);
    printf("\r%s %c%s%c %d%% %s\n", prefix, container[0], bar, container[1], 100, suffix);
    fflush(stdout);
    free(bar);
    return;
}
