# INFOB231 Concepts des systèmes d'exploitation : TP 5 - exercice 3

## Question 1

*Que se passe-t-il si le processus père envoie le signal SIGSTOP au lieu de SIGUSR1 ? La situation est-elle différente avec le signal SIGINT ?*

Comme le programme ne définit pas de fonction par défaut pour la signal `SIGSTOP`, il se mettra en pause. Avec le signal `SIGINT`, il sera interrompu.

## Question 2

*Comment améliorer le programme pour que le processus père ne soit pas interrompu lorsque l’on tape un CTRL-C ?*

Il faut définir une fonction par défaut pour le signal `SIGTERM` pour qu'il ne mette pas fin à l'éxécution.
