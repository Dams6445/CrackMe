# Obfuscated CrackMe


## Table of contents

- [Obfuscated CrackMe](#obfuscated-crackme)
  - [Table of contents](#table-of-contents)
  - [Presentation](#presentation)
  - [Control Flow obfuscation](#control-flow-obfuscation)
  - [Encrypted Obfuscation](#encrypted-obfuscation)
  - [Time Based Password](#time-based-password)


## Presentation

Élaboration un "crackme" éducatif, un défi de reverse engineering, où l'exécutable affiche "OK\n" sur STDOUT et retourne zéro lorsque le bon mot de passe est entré.

- Exigences de l'exécutable
  - Livrable :  un exécutable ELF pour Linux x64, avec une taille maximale de 16KB.
  - Le fichier binaire doit un script ./BUILD.sh doit le compiler indépendamment.
- Spécification du CrackMe
  - Le mot de passe doit être passé via `argv[1]` OU `argv[2]` OU `argv[1] et argv[2]`.
  - L'exécutable doit afficher "OK\n" sur STDOUT et retourner zéro si le mot de passe est correct.
  - Doit fonctionner sur toute distribution Linux moderne AMD64
- Techniques d'obfuscation (objectif 4) :
  - [Control Flow obfuscation](#Method1)
  - [Encrypted Obfuscation](#Method2)
  - ?
  - ?
- Ethique
  - Aucun comportements malveillants dans l'exécutable.

## Control Flow obfuscation

L'objectif de cette méthode d'obfuscation est de générer des comportements perturbateurs dans le code.
[Présentaion de la méthode](./Control_Flow_Obfucation.c)

## Encrypted Obfuscation

Pour réussir le CrackMe, les utilisateurs devront retrouver le code crypté et sa méthode de cryptage pour valider le challenge.
[Présentaion de la méthode](./Encrypted_Obfuscation.c)

## Time Based Password

Cette méthode permet de changer le mot de passe en fonction de l'heure d'execution.
[Présentaion de la méthode](./Time_changing_password.c)
