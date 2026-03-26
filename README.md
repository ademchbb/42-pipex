*This project has been created as part of the 42 curriculum by adchebbi.*

# Pipex

## Description

Pipex est un projet qui consiste à reproduire le comportement du mécanisme de pipe UNIX en C. Le programme prend deux commandes shell et les connecte via un pipe, en redirigeant l'entrée depuis un fichier et la sortie vers un autre fichier.

L'objectif est de comprendre en profondeur le fonctionnement des processus (`fork`), des redirections de file descriptors (`dup2`), de l'exécution de programmes (`execve`) et de la communication inter-processus via `pipe`.

Le programme reproduit le comportement de :

```bash
< file1 cmd1 | cmd2 > file2
```

## Instructions

### Compilation

```bash
make        # Compile la libft puis le binaire pipex
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et le binaire
make re     # Recompile entièrement le projet
```

Le projet compile avec `cc` et les flags `-Wall -Wextra -Werror`.

### Exécution

```bash
./pipex file1 "cmd1" "cmd2" file2
```

Le programme prend 4 arguments :
- `file1` : fichier d'entrée (redirigé sur stdin de cmd1)
- `cmd1` : première commande shell avec ses paramètres
- `cmd2` : deuxième commande shell avec ses paramètres
- `file2` : fichier de sortie (reçoit stdout de cmd2)

### Exemples

```bash
./pipex infile "ls -l" "wc -l" outfile
# Équivalent à : < infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
# Équivalent à : < infile grep a1 | wc -w > outfile
```

## Resources

### Références classiques

- `man 2 pipe` — création de pipes
- `man 2 fork` — création de processus enfants
- `man 2 dup2` — duplication de file descriptors
- `man 2 execve` — exécution de programmes
- `man 2 wait` / `man 2 waitpid` — attente de fin de processus
- `man 2 access` — vérification des permissions d'un fichier
- [Pipes in C (tutoriel)](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
- [Communicating between processes (using pipes) in C](https://youtu.be/Mqb2dVRe0uo?si=A28mciZjL201lclp)

### Utilisation de l'IA

L'IA (Claude) a été utilisée pour :
- La rédaction de ce fichier README.md.
- La validation de la logique de l'implémentation.
- Suivi de l'avancement du projet et des étapes de développement.