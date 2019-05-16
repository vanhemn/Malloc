# Malloc


Ce projet consiste en la réécriture des fonctions malloc et free de la libc.

Prototypes des fonctions, à respecter impérativement :

void*   malloc(size_t size);
void    free(void *ptr);Copy
Pour ce faire, vous devez utiliser les appels système brk et/ou sbrk.

Les informations dont vous avez besoin se trouvent dans le cours, ainsi que dans les pages de man de malloc(3), brk(2) et sbrk(2).

Il peut également être intéressant de jeter un oeil aux implémentations passées de malloc, par exemple le malloc écrit par Chris Kingsley en 1982 que vous pourrez trouver, entre autres, sur le CVS de FreeBSD.

Je vous invite également, à titre de comparaison, à regarder le code de malloc aujourd'hui utilisé dans la libc.
