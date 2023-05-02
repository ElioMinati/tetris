/*
** EPITECH PROJECT, 2022
** get_files
** File description:
** functions used to get content inside the tetrimino files
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int get_nb_files(char *directory)
{
    int count = 0;
    DIR *d;
    struct dirent *dir;

    d = opendir(directory);
    dir = readdir(d);
    while (dir != NULL) {
        if (dir->d_name[0] == '.') {
            dir = readdir(d);
            continue;
        }
        ++count;
        dir = readdir(d);
    }
    closedir(d);
    return count;
}

static void get_filenames(char **filenames, struct dirent *dir,
int i)
{
    filenames[i] = malloc(my_strlen(dir->d_name) * sizeof(char));
    filenames[i] = my_strconcat("tetriminos/", dir->d_name);
}

char **get_tetrimino_files(void)
{
    int i = 0;
    DIR *d;
    struct dirent *dir;
    char **filenames = malloc((get_nb_files("tetriminos") + 1)
    * sizeof(char *));

    d = opendir("tetriminos");
    dir = readdir(d);
    while (dir != NULL) {
        if (dir->d_name[0] == '.') {
            dir = readdir(d);
            continue;
        }
        get_filenames(filenames, dir, i);
        dir = readdir(d);
        ++i;
    }
    filenames[i] = NULL;
    closedir(d);
    return filenames;
}

char *get_file_content(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buf;
    struct stat st;

    if (fd == -1)
        return NULL;
    if (stat(path, &st) == -1)
        return NULL;
    buf = malloc(st.st_size * sizeof(char));
    if (read(fd, buf, st.st_size) == -1)
        return NULL;
    close(fd);
    for (int i = st.st_size; buf[i] != '*' && buf[i] != ' '
    && i > 0; buf[i] = '\0', i--);
    return buf;
}
