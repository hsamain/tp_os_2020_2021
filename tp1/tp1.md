 # Concepts des systèmes d'exploitation - TP

## 1.

```
$ mkdir exo
$ cd exo
$ pwd
/home/hsamain/exo
```

## 2.

```
$ cd exo
$ touch es1
$ mkdir essai2
```

## 3.

```
$ cp es1 essai2
$ cd essai2
$ mv es1 es1-copie
```

Pour obtenir ce résultat en une seule opération :

```
$ cp es1 essai2/es1-copie
```

## 4.

```
$ mkdir -p /tmp/tp/prog1
```

## 5.

la commande `ls *` affiche tous les fichier du répértoire courant ainsi que les fichiers de ses sous-répertoires.

```
$ ls *
es1

essai2:
es1-copie
```

Pour les fichier dont le nom commance par `es`, il faut utiliser `ls es*` 

## 6.

`rm -i <fichier>` permet de supprimer un fichier avec demande de confirmation. L'option `-r` permet de supprimer les répertoires et sous-répertoires récursivement.

## 7.

On utilise la commande `head -n 51` 

## 8.

Il faut soit ce mettre en super utilisateur avec les commande `sudo`, soit utiliser l'option `-s` 

```
$ sudo grep passwd /etc/* | grep passwd /etc/* -s
```

## 9.

```
$ find "stdio.h"
```

## 10.

```
$ find -name "[Aa]*"
```

## 11.

```
find -newer <fichier> 
```

## 12.

```
$ find -name "*.o" -delete
```

## 13.

`d` signifie que c'est un répertoire 

`r` signifie le droit de lecture

`w` signifie le droit d'écriture

`x` signifie le droit d’exécution

`rwx` signifie que le propriétaire a tous les droits.

`r-x` signifie que le groupe possède les droits de lecture et d’exécution.

`r-x` signifie que les autres utilisateur ont les droits de lecture et d’exécution 

```
$ chmod 700
```

## 14.

```
$ echo "Hello World" > hello.txt
```

## 15.

`cat hello` affiche le texte contenu dans hello, en l'occurence `Hello World` 

`grep -v bonjour` recherche une chaîne de caractère dans un fichier qui ne contient pas "bonjour" et l'affiche, en l'occurence `Hello World` 

`wc -l` affiche le nombre de ligne d'un fichier, en l'occurence `1` 

## 16.

```
$ cd
$ mkdir -p ./tp/system
$ cd tp/system
$ touch Makefile
$ cp -r /usr/shre/vim
$ rm Makefile
```

## 17.

`ps` "process status" affiche les processus actif et ses ressources utilisées, mais ps n'est quasiment jamais utilisé sans aucune option.

`ps -ef ` permet de lister tous les processus sur le système avec l'affichage en format complet (full-format).

## 18.

On utilise la combinaison de `ps` avec `wc` 

```
$ ps -e | wc -l
```

Le nombre trouvé est différent car par defaut `ps` affiche les commande qui sont actuellement utilisé dans le terminal au moment de l'utilisation de la commande.









