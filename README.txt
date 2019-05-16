ALors c'est un malloc avec :

	• Une liste chainée triée par ordre croisant de size via un trie par insertion
	• Une fonction permetant de rezize les block quand on recherche un block free et que la size  du n+1
	  du block est inferieur a la size du nouveaux bloque crée par le split du bloque en deux (pour ne pas cassé le trie)
	• Il y a calloc et realloc
	• Il passe le stress test et on peu ls -R pas mal de chose 
	• On peu lancer vim et python xD

Il n'arrive pas a lancer (liste non exhaustive) :

	• Nano
	• NodeJs