
# P4z : Analyse de performances de différents tris

[Grille d'évaluation P4z](https://docs.google.com/spreadsheets/d/1VXeO91rhy04xa0p8KUhWliFl228utHaDir8MstO5Z-M/edit?usp=sharing
)

## Problème

Description du Problème.

Description de tous les paramètres exploratoires du problème

## Dispositif expérimental

### Application

[code source de l'application](chemin)
```
Description de l'application et des arguments
```

### Environnement de test

Description de la plateforme de test
```
Extrait pertinent de /proc/cpuinfo
```

### Description de la démarche systématique

Description de la démarche systématique et de l'espace d'exploration pour chaque paramètres.

```
Suite des commandes, ou script, à exécuter pour produire les données.
```

## Résultats préalables

### Temps d'exécution

| Jeu de test          | Tri par Insertion         | Tri Fusion                | Tri Rapide                |
|----------------------|---------------------------|---------------------------|---------------------------|
| Aléatoire            | ![plot](./TP2/Resultat/graphe_inser_aleatoire.png) | ![plot](./TP2/Resultat/graphe_fusion_aleatoire.png)| ![plot](./TP2/Resultat/graphe_rapide_aleatoire_temps.png) |
| Trié                 | ![plot](./TP2/Resultat/graphe_inser_croissant_temps.png)| ![plot](./TP2/Resultat/graphe_fusion_croissant.png) | ![plot](./TP2/Resultat/graphe_rapide_croissant_temps.png) |
| Tri inversé          | ![plot](./TP2/Resultat/graphe_inser_decroissant.png) | ![plot](./TP2/Resultat/graphe_fusion_decroissant.png) | ![plot](./TP2/Resultat/graphe_rapide_decroissant_temps.png) |

### Consommation mémoire

| Jeu de test          | Tri par Insertion         | Tri Fusion                | Tri Rapide                |
|----------------------|---------------------------|---------------------------|---------------------------|
| Aléatoire            | ![plot](./TP2/Resultat/graphe_inser_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_aleatoire_mem.png) | ![plot](/TP2/Resultat/graphe_rapide_aleatoire_mem.png) |
| Trié                 | ![plot](./TP2/Resultat/graphe_inser_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_croissant_mem.png) |
| Tri inversé          | ![plot](./TP2/Resultat/graphe_inser_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_decroissant_mem.png) |

### Analyse des résultats préalables

Explications précises et succinctes des résultats préalables.

### Discussion des résultats préalables

Explications précises et succinctes des limites des résultats
préalables et ce qu'ils ne permettent pas de vérifier.

## Etude approfondie

### Hypothèse

Expression précise et succincte d'une hypothèse.

### Protocole expérimental de vérification de l'hypothèse

Expression précise et succincte du protocole.

```
Suite des commandes, ou script, à exécuter pour produire les données.
```

### Résultats expérimentaux

### Analyse des résultats expérimentaux

### Discussion des résultats expérimentaux

## Conclusion et travaux futurs
