# 42 : get_next_line

## to do
- une fct ```c int get_next_line(int const fd, char **line);``` qui lit une ligne d'un fichier, la stock dans **line et retourne 1 si elle a bien lu. 0 si c'est la fin du fichier. Et -1 si im y a une erreur.
- une ligne de fichier se fini par \n ou EOF.
- Votre fonction get_next_line doit renvoyer son resultat sans le \n ?? 
- la fonction doit etre fonctionnelle avec fichier, entree standard, redirection, ...
- il faut un fichier auteur qui fini par \n. Pas de main et pas de makefile
- le get_next_line.h doit contenir `#define BUFF_SIZE 32` et il doit pouvoir etre modofier en restant fonctionnel.
- il faut utiliser une variable statique
