# Obfuscated CrackMe

<!-- TODO: Rajouter les techniques d'obfuscation que vous avez implémentées dans la présentation -->

## Table of contents

- [Obfuscated CrackMe](#obfuscated-crackme)
  - [Table of contents](#table-of-contents)
  - [Presentation](#presentation)
  - [Control Flow obfuscation](#control-flow-obfuscation)
  - [Plan fonctions raph adds](#plan-fonctions-raph-adds)
  - [Encrypted Obfuscation](#encrypted-obfuscation)
  - [Time Based Password](#time-based-password)
  - [pTrace](#ptrace)
  - [Options gcc](#options-gcc)
  - [Pistes d'amélioration](#pistes-damélioration)

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
  - [Time Based Password](#time-based-password)
  - [pTrace](#ptrace)
  - fonction and variable name randomised
- Ethique
  - Aucun comportements malveillants dans l'exécutable.

## Control Flow obfuscation

L'objectif de cette méthode d'obfuscation est de générer des comportements perturbateurs dans le code.
[Présentaion de la méthode](./Control_Flow_Obfucation.c)

## Plan fonctions raph adds

- [function001](./raph_adds/func001) -> vide
- [function002](./raph_adds/func002) -> chaine de caractère "crack_en"
- [function003](./raph_adds/func003) -> vide
- [function004](./raph_adds/func004) -> chaine de caractère "$ε₳₹¢hHι̇d€η₭e¥₣or₮he₩i₦" -> search hiden key for the win -> A FAIRE
- [function005](./raph_adds/func005) -> caractère changeant chaque minute (offset 0x20)
- [function006](./raph_adds/func006) -> vide
- [function007](./raph_adds/func007) -> Xor encrypt
- [function008](./raph_adds/func008) -> vide
- [function009](./raph_adds/func009) -> récupération du répertoire HOME
- [function010](./raph_adds/func010) -> vide
- [function011](./raph_adds/func011) -> caractère changeant chaque minute (offset 0x43)
- [function012](./raph_adds/func012) -> vide
- [function013](./raph_adds/func013) -> Xor decrypt
- [function014](./raph_adds/func014) -> vide


## Encrypted Obfuscation

Pour réussir le CrackMe, les utilisateurs devront retrouver le code crypté et sa méthode de cryptage pour valider le challenge.
[Présentaion de la méthode](./Encrypted_Obfuscation.c)

## Time Based Password

Cette méthode permet de changer le mot de passe en fonction de l'heure d'execution.
[Présentaion de la méthode](./Time_changing_password.c)

## pTrace

Cet appel système est utilisé par tous les debugger sous Linux. 
Pour vérifier si un debugger est en train d'être utilisé sur notre CrackMe, il suffit de faire un appel à ce dernier au début de notre programme : 
  - S'il renvoi une erreur (-1), alors il y a un debugger (exemple: gdb) qui est utilisé et le programme devra s'interrompre
  - S'il renvoi autre chose, le porgramme n'est pas en cours de debuggage et peut donc être utilisé normalement

## Options gcc

Pour dissimuler des techniques d'obfuscation, on pourrait utiliser les options d'optimisation -02 et -03 : 

```powershell
gcc -O2 -o votre_programme votre_source.c
```
et
```powershell
gcc -O3 -o votre_programme votre_source.c
```

## Pistes d'amélioration

- Obfuscation de Contrôle de Flux: Modifiez la structure de contrôle du programme pour la rendre moins linéaire et plus difficile à suivre. Par exemple, l'utilisation de sauts indirects, de tables de sauts, ou l'insertion de code mort. (A améliorer)

- Obfuscation des Données: Changez la façon dont les données sont stockées et utilisées. Par exemple, utiliser des encodages personnalisés pour les chaînes de caractères ou diviser des variables en plusieurs morceaux stockés séparément.

- Cryptage de Chaînes: Les chaînes de caractères peuvent être cryptées dans le code binaire et déchiffrées en temps réel lors de l'exécution. Cela rend difficile la compréhension du but de certaines parties du code sans exécuter le programme. (A améliorer)

- Incorporation de Code Auto-Modifiant: Le code qui modifie son propre comportement en cours d'exécution peut semer la confusion et compliquer le reverse engineering.

- Utilisation de Macros et de Fonctions Inline Complexes: L'utilisation intensive de macros et de fonctions inline peut rendre le code source visuellement complexe et difficile à suivre.

- Anti-Debugging et Anti-Tampering: Des techniques telles que la vérification de l'intégrité du code ou l'introduction de routines de détection de débogage peuvent rendre l'analyse plus compliquée.

- Packers et Compresseurs: Utiliser des packers ou des compresseurs pour réduire la lisibilité du code binaire. Cependant, des outils comme Ghidra sont souvent capables de décompresser ou de déballer ces programmes.