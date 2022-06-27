#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directls.h"

/* include the insertionsort algorithm */
#include "../../Algorithms/QuickSort/qsort.h"


/* compare_dir: Function to compare the directories */
static int compare_dir(const void *key1, const void *key2)
{
    int retval;
    
    if ((retval = strcmp(((const Directory *)key1)->name, ((const Directory *) key2)->name)) > 0)
        return 1;
    
    else if (retval < 0)
        return -1;

    return 0;
}


/* direcotry: Create a sorted list of direcotires and return the amount of direcoties 
   path: The path to list
   dir: Pointer to dump dir
   complexity: Is O(n log n) where n is the amount of direcotor
 */
int directory(const char *path, Directory **dir)
{
    DIR *dirptr;
    Directory *temp;
    struct dirent *curdir;
    int count, i;

    /* open the direcotry and get the  object */
    if ((dirptr = opendir(path)) == NULL)
        return -1;

    *dir = NULL;
    count = 0;

    /* Iterate the directory */
    while ((curdir = readdir(dirptr)) != NULL) {
        count++;
        /* Create the list of directories */
        if ((temp = (Directory *) realloc(*dir, count * sizeof(Directory))) == NULL) {
            free(*dir);
            return -1;
        } else
            *dir = temp;
        
        strcpy(((*dir)[count - 1]).name, curdir->d_name);
    }

    /* close the direcotry */
    closedir(dirptr);

    /* Do the quick sort to sort all the list */
    if (qksort(*dir, count, sizeof(Directory), 0, count - 1, compare_dir) != 0)
        return -1;

    /* return the amount of directories */
    return count;
}

