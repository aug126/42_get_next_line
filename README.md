# 42 : get_next_line


## to do

- une fct ```c int get_next_line(int const fd, char **line);``` qui lit une ligne d'un fichier, la stock dans **line et retourne 1 si elle a bien lu. 0 si c'est la fin du fichier. Et -1 si im y a une erreur.
- une ligne de fichier se fini par \n ou EOF.
- Votre fonction get_next_line doit renvoyer son resultat sans le \n ?? 
- la fonction doit etre fonctionnelle avec fichier, entree standard, redirection, ...
- il faut un fichier auteur qui fini par \n. Pas de main et pas de makefile
- le get_next_line.h doit contenir `#define BUFF_SIZE 32` et il doit pouvoir etre modofier en restant fonctionnel.
- il faut utiliser une variable statique


## modification de la libft :

- j'ai du mettre le fichier header dans un dossier includes et ajouter le flag `-I includes` au makefile de la libft.


## questions :

- si on appelle plusieurs fichiers, comment doivent-ils être gérés ? chaque ligne se rajoute à la suite de \*\*line sans prendre en compte de quel fichier elle provient ?
-> il faut que un appel de fonction mette une ligne dans *line[x] et x varie en fonction des files descriptors. (je pense à x = fd - 3 pour que chaque fichier ouvert sauf fd 1, 2 et 3 puissent etre lu et stocké dans **line. Il faudrait donc malloquer line + x de la taille de char*)

## à faire pour le moment : 

- malloquer `line` suivant le fd
___
- on doit copier toute la var statique à la suite de line[x] (à l'intérieur de la boucle). pour ça il faudrait concaténer line[x]+piece_line dans line[x] (avec malloc).
- en dehors de la boucle, il faut copier la var statique jusqu'au \n dans line[x]. (il faudrait concaténer sur un certain nombre de char) Puis il faut copier la suite de la var statique au debut de cette var.

- il faut free tout ce qui a été malloqué et retourner
