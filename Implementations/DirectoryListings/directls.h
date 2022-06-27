#ifndef __DIRECTLS_H__
#define __DIRECTLS_H__

#include <dirent.h>


typedef struct Directory_ {
    char name[MAXNAMLEN + 1];
} Directory;


/* direcotry: Create a sorted list of direcotires and return the amount of direcoties 
   path: The path to list
   dir: Pointer to dump dir
   complexity: Is O(n log n) where n is the amount of direcotor
 */
int directory(const char *path, Directory **dir);


#endif
