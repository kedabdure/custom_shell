#include "main.h"
/**
 * excutels_l - Searches for the command in PATH with arguments.
 * @buf: User entry containing command and arguments.
 *
 * Return: A dynamically allocated string containing the full command path
 * with arguments, or NULL if the command is not found in PATH.
 */
char *find_path(char *buf) {
    char *value = _getenv("PATH");
    char *command = strtok(buf, " ");
    char *arguments = strtok(NULL, "\n");

    if (value != NULL && command != NULL) {
        char *str = strtok(value, ":");
        while (str != NULL) {
            char full[MAX_PATH_LENGTH];
            snprintf(full, sizeof(full), "%s/%s", str, command);

            if (access(full, F_OK) == 0) {
                if (arguments) {
                    size_t len = _strlen(full) + _strlen(arguments) + 2;
                    char *com_wiz_arg = malloc(len);
                    if (com_wiz_arg != NULL) {
                        snprintf(com_wiz_arg, len, "%s %s", full, arguments);
                        return com_wiz_arg;
                    } else {
                        perror("Memory allocation failed");
                        return NULL;
                    }
                } else {
                    // No arguments, return just the full path
                    char *com_wiz_arg = _strdup(full);
                    if (com_wiz_arg != NULL) {
                        return com_wiz_arg;
                    } else {
                        perror("Memory allocation failed");
                        return NULL;
                    }
                }
            }

            str = strtok(NULL, ":");
        }
    }

    return NULL;
}


/**
 * find_path - Finds the command in the PATH environment variable and returns the path.
 * @command: The command to be located in the PATH.
 *
 * Return: A dynamically allocated string containing the full path to the command,
 * or NULL if the command is not found in the PATH.
 */
/*
char *find_path(char *command) {
    if (strchr(command, ' ')) {
        // If there are spaces in the command, execute it directly
        excutels_l(command);
        return NULL; // Return NULL as the path is not found
    } else {
        char *path_copy, *token;
        char *path = _getenv("PATH");
        if (path == NULL || command == NULL) {
            return NULL;
        }

        path_copy = _strdup(path);
        if (path_copy == NULL) {
            perror("Memory allocation failed");
            return NULL;
        }

        token = strtok(path_copy, ":");
        while (token != NULL) {
            char executablePath[MAX_PATH_LENGTH];
            snprintf(executablePath, MAX_PATH_LENGTH, "%s/%s", token, command);

            if (access(executablePath, F_OK) == 0) {
                char *fullPath = _strdup(executablePath);
                free(path_copy);
                if (fullPath == NULL) {
                    perror("Memory allocation failed");
                    return NULL;
                }
                return fullPath;
            }

            token = strtok(NULL, ":");
        }

        free(path_copy);
        return NULL; // Return NULL as the path is not found
    }
}
*/
