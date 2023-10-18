#include "main.h"

/**
 * excutels_l - Searches for the command in PATH with arguments.
 * @buf: User entry containing command and arguments.
 *
 * Return: A dynamically allocated string containing the full command path
 * with arguments, or NULL if the command is not found in PATH.
 */
char *excutels_l(char *buf) {
    char *value = _getenv("PATH");
    char *command = strtok(buf, " ");
    char *arguments = strtok(NULL, "\n");

    if (value != NULL && command != NULL && arguments != NULL) {
        char *str = strtok(value, ":");
        while (str != NULL) {
            char full[MAX_PATH_LENGTH];
            snprintf(full, sizeof(full), "%s/%s", str, command);

            if (access(full, F_OK) == 0) {
                size_t len = _strlen(full) + _strlen(arguments) + 2;
                char *com_wiz_arg = malloc(len);
                if (com_wiz_arg != NULL) {
                    snprintf(com_wiz_arg, len, "%s %s", full, arguments);
                    return com_wiz_arg;
                } else {
                    perror("Memory allocation failed");
                    return NULL;
                }
            }

            str = strtok(NULL, ":");
        }
    }

    return NULL;
}

