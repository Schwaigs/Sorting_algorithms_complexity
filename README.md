
# P4z : Analyse de performances de différents tris

[Grille d'évaluation P4z](https://docs.google.com/spreadsheets/d/1VXeO91rhy04xa0p8KUhWliFl228utHaDir8MstO5Z-M/edit?usp=sharing
)

## Problème

Comment les differents algorithmes de tris fonctionnent-ils pour les différents cas ? A quoi leur efficacité et leur complexité sont-elles liées ?

## Dispositif expérimental

### Application

[code source de l'application](./TP2/main.c)
```
./main <nom_tri> <taille> <type_tab> <min> <max>
```
Notre main permet de lancer n'importe quel tri sur n'importe quel type et taille de tableau. On peut
aussi choisir la valeur minimal et maximal du tableau.

Type de tri possible : [i : insertion]  [f : fusion]  [r : rapide]  [x : radix]

Type de tableau possible : [a : aleatoire]  [c : croissant]  [d : decroissant] [m : combineTab]

La taille d'un tableau peut aller jusqu'a 2.147 milliard. De même que pour le min et le max avec les valeur
 negative possible pour le min.

### Environnement de test

Tout les test on etait éffectué sur les serveur de l'iut et plus précisement sur phoenix.
Phoenix est constitué de 40 coeurs ainsi que de 126Go de RAM. De plus phoenix est un serveur tres
peu utilisé par l'iut. Il possede donc la capacité de faire simultanément plusieur tri sans qu'il 
se derange pour autant.
```
/proc/cpuinfo
processor       : 39
vendor_id       : GenuineIntel
cpu family      : 6
model           : 79
model name      : Intel(R) Xeon(R) CPU E5-2630 v4 @ 2.20GHz
stepping        : 1
microcode       : 0xb000021
cpu MHz         : 1285.323
cache size      : 25600 KB
physical id     : 1
siblings        : 20
core id         : 12
cpu cores       : 10
apicid          : 57
initial apicid  : 57
fpu             : yes
fpu_exception   : yes
cpuid level     : 20
wp              : yes
bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs taa itlb_multihit
bogomips        : 4396.18
clflush size    : 64
cache_alignment : 64
address sizes   : 46 bits physical, 48 bits virtual
power management:
```

### Description de la démarche systématique

Notre workflow s'éxecute de la manière suivante:  
Execution de perf.sh avec la ligne suivante :

```
./perf.sh <nbRepetition> <tailleMaxTableau> <minVal> <maxVal>  >> <nom_du_fichier>
```
On retrouvera des données dans le fichier créé de la maniere suivante :

````$xslt
iTest	taille	min	max	nom_tri	type_tab	temps	mem
8	599252509	-1000	10000	f	a	350.34	12115420
10	903965294	-1000	10000	f	a	513.06	18821600
9	947720439	-1000	10000	f	a	537.55	17013596
10	903965294	-1000	10000	f	d	395.72	19912064
10	903965294	-1000	10000	f	c	389.97	20478056
9	947720439	-1000	10000	f	d	404.63	21942660
9	947720439	-1000	10000	f	c	412.85	21675896
...
````

Le script perf.sh nous permet de tirer aléatoirement une taille de tableau pour chaque répétition. On crée alors un tableau avec des valeurs contenues entre min et max que nous avons passés en lignes de commandes.
On appel ensuite chaque algorithme de tri pour le type de tableau souhaité. Enfin, on récupère le temps d'execution et la consommation mémoire de chaque test.

Une fois les données verifié, on lance R et on tape les commande suivante :

````$xslt
library(ggplot2)
````
(import d'une librairie pour de plus beau graphique)

````$xslt
perf <- read.table("nom_du_fichier", header = TRUE)
````
(import des données)

````$xslt
ggplot(perf,aes(x=taille, y=temps)) + geom_point() + geom_smooth() + ggtitle("titre du tableau")
````
(créer un graphique à partir des données importé qui compare la taille avec le temps d'execution. Le temps peut etre remplacer par la memoire )

````$xslt
ggsave("nom_du_tableau.png")
````
(créer une image a partir du graphique)

## Résultats préalables

### Temps d'exécution

Dans un premier temps, voici deux graphiques permettant de comparer les performances de nos 4 algorithmes selon les différents types de tableaux à l'aide d'une même échelle. Le 2e a été réalisé sans le tris insertion et sans les tableaux à valeur unique afin de pouvoir mieux voir les 3 autre. Puis, des graphiques plus précis pour chaque cas se trouvent dans un tableau juste après.

| Tout les algorithmes de tris | Sans l'insertion et tableaux constants|
|------------------------------|-----------------|
| ![plot](./TP2/Resultat/graphe_commun_avec_uni_temps.png) | ![plot](./TP2/Resultat/graphe_commun_sans_insertion_temps.png) |


| Jeu de test          | Tri par Insertion         | Tri Fusion                | Tri Rapide                | Tri Radix                 |
|----------------------|---------------------------|---------------------------|---------------------------|---------------------------|
| Aléatoire            | ![plot](./TP2/Resultat/graphe_inser_aleatoire.png) | ![plot](./TP2/Resultat/graphe_fusion_aleatoire.png)| ![plot](./TP2/Resultat/graphe_rapide_aleatoire_temps.png) | ![plot](./TP2/Resultat/graphe_radix_aleatoire_temps.png)|
| Trié                 | ![plot](./TP2/Resultat/graphe_inser_croissant_temps.png)| ![plot](./TP2/Resultat/graphe_fusion_croissant.png) | ![plot](./TP2/Resultat/graphe_rapide_croissant_temps.png) |  ![plot](./TP2/Resultat/graphe_radix_croissant_temps.png)|
| Tri inversé          | ![plot](./TP2/Resultat/graphe_inser_decroissant.png) | ![plot](./TP2/Resultat/graphe_fusion_decroissant.png) | ![plot](./TP2/Resultat/graphe_rapide_decroissant_temps.png) | ![plot](./TP2/Resultat/graphe_radix_decroissant_temps.png) |
| Valeur unique        | ![plot](./TP2/Resultat/graphe_inser_uni_temps.png) | ![plot](./TP2/Resultat/graphe_fusion_uni_temps.png) | ![plot](./TP2/Resultat/graphe_rapide_uni_temps.png) | ![plot](./TP2/Resultat/graphe_radix_uni_temps.png) |

### Consommation mémoire

Tout d'abord, voici deux graphique permettant de comparer la consommation mémoire de nos 4 algorithmes selon les différents types de tableaux à l'aide d'une même échelle. Les tableaux à valeur unique sont sur un graphique à part car la consommation  du tri rapide est d'un ordre de grandeur beaucoup plus grand que les autres ce qui empèche de voir une différence. Puis, des graphiques plus précis pour chaque cas se trouvent dans un tableau juste après.

| Tout les algorithmes de tris sans tableaux constant | Tout les algorithmes de tris sur tableaux constants |
|------------------------------|-----------------|
| ![plot](./TP2/Resultat/graphe_commun_mem.png) | ![plot](./TP2/Resultat/graphe_commun_uni_mem.png) |

| Jeu de test          | Tri par Insertion         | Tri Fusion                | Tri Rapide                | Tri Radix                 |
|----------------------|---------------------------|---------------------------|---------------------------|---------------------------|
| Aléatoire            | ![plot](./TP2/Resultat/graphe_inser_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_radix_aleatoire_mem.png)|
| Trié                 | ![plot](./TP2/Resultat/graphe_inser_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_radix_croissant_mem.png)|
| Tri inversé          | ![plot](./TP2/Resultat/graphe_inser_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_radix_decroissant_mem.png)|
| Valeur unique        | ![plot](./TP2/Resultat/graphe_inser_uni_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_uni_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_uni_mem.png) | ![plot](./TP2/Resultat/graphe_radix_uni_mem.png) |

### Analyse des résultats préalables
 
- Tri insertion :

    Niveau du temps d'execution, le tri par insertion va être le plus rapide pour trier un tableau trié. Il va consommer seulement le temps de verifier chaque element 2 à 2. Autrement sur d'autre tableau comme aléatoire ou décroissant il va prendre beaucoup de temps car si un élément est mal placé il va le déplacer cran par cran. De plus, le tri insertion est aussi très efficace pour les tableau constant (ne contenant qu'une seule et même valeur dans toute les cases), puisque ce type de tableau est un cas particulier des tableaux triés.

    Niveau mémoire, le tri insertion reste trés optimisé. De par son fonctionnement il execute le tri directement dans le tableau donné en entée. Ainsi il consommera la memoire de manière linéaire et en petite quantité par rapport au autre tri.


- Tri fusion :

    Ce tri a un temps d'execution uniforme entre tout les type de tableau. Il est plutot efficace par rapport au tri par insertion sauf avec un tableau croissant ou il est beaucoup moins rapide (10x plus long).

    Cette version n'est pas encore tres optimisé niveau mémoire car c'est le plus gourmand de tous avec le radixSort. Il utilise 13x plus de memoire que le tri par insertion et 1.3x plus que le tri rapide.


- Tri Rapide :  
    
    Le tri rapide est plus efficace au niveau temps d'execution parmis ceux sur lesquels nous avons travailler, la seule exeception étant le tri insertion pour les tableaux déjà triés. Ce tri est particulièrement efficace sur des tableaux croissants, en effet c'est dans ce cas ci que nous avons obtenu les meillleurs résultats. Cependant, même si le tableau constant est un cas particulier ce ceux triés, le tri rapide n'est pas particulièrement efficace pour celà.
    
    Au niveau de la consommation mémoire celle ci reste relativement contante quelque soit le type de tableau donné en paramètre.


-  Tri Radix :

    Le tri radix est assez efficace puisque son temps d'execution se rapproche fortement du tri fusion. Cependant, on note qu'il semble être un peu plus lent pour les tableaux aléatoire comparer aux croissants/décroissants. Le pire des cas étant pour lui les tableaux constant. Cependant, une amélioration simple pour y pallier est décrite dans la section "Discussion des résultats".

    Sa consommation est elle aussi constante quelque soit le tableau passé en paramètre. En effet, dans le code on utilise un unique malloc faisant exactement la taille du tableau à trié. Les autres tableaux utilisés faisant tous 10 cases de la taille d'un long, leur utilisation est négligable.


### Discussion des résultats préalables
 
- Tri insertion :

    Pour ce qui est de la complexité de l'algorithme de tri insertion, voici ce que l'on obtient :

    Dans le pire des cas (tableau décroissant):
        3(n-1) + 1/2 * (n-1)(n-2) + 2 = O(n²)
    
    Dans le meilleur des cas (tableau croissant):
        3(n-1) + 2(n-1) = 5(n-1) = O(n)

    Niveau amélioration on peut amélioré ce tri en regardant directement où il doit placer la nouvelle valeur d'indice i avec un parcours pour ensuite faire le décalage plutot que de la déplacer cran par cran en remplaçant les valeurs à chaque fois jusqu'a ce qu'on ne puisse plus.

    Le tri insertion étant particulièrement efficace pour les tableaux presque triés mais très lent pour le reste, il serait possible de l'utiliser en complément d'un autre tri. Ce tri ferais la première partie du travail et on lancerais ensuite le tri insertion pour optimiser le temps d'execution de la fin de l'algorithme.

- Tri fusion :

    Le tri fusion à 2 différent défaut. Tout d'abord le tri d'un tableau aléatoire et constant sera ~16% plus long que sur des tableaux croissant et décroissant. Ensuite ce tri est pour le moment tres gourmand en mémoire. En effet pour chaque subdivision il va créer un un nouveau tableau et donc rajouter uttiliser 2 tableau qui font chacun la moitié du tableau de la subdivision précédente.
    
    Pour résoudre le problème de la mémoire on peut implementer la solution suivante: Au lieu de recréer un tableau a chaque subdivision on pourrait juste recréer un seul tableau de la meme taille que le tableau à trié et trié les données de l'un vers l'autre à chaque subdivision. Un ainsi on utiliserai seulement le double de memoire que le tableau.

- Tri Rapide :

    Le tri rapide à different defaut qui se révelant surtout lors du tri de tableau croissant, décroissant et constant. En effet, le pivot étant toujours la dernière valeur du tableau, si notre tableau est déjà trié, alors l'algorithme va passé en revu tout le tableau et chaque appel récusif se fera sur un tableau de taille_k+1 égale à taille_k - 1. Le tri rapide est alors extrêmement lent sur ces cas de figures.

    Pour résoudre ce problème plusieurs choix s'offrent à nous. Mélanger le tableau passé en paramètre pour effectuer le tri sur un aléatoire, choisir le pivot aléatoirement, prendre la médiane pour pivot... Nous avons choisit d'implémenter un pivot aléatoire ce qui a grandement optimisé notre algorithme.

    Le pire cas que peut renconter le tri rapide est donc le tableau constant qui lui fait atteindre une compléxite de O(n²).

- Tri Radix :

    Le tri radix n'est à la base pas prévu pour des tableaux prennant des valeurs négatives en compte. En effet, le tri radix à l'effet inverse sur les valeurs négatives puisqu'il va les triés dans l'odre décroissant. Le résultat dans le cas d'un tableau mélant valeur négatives et positives n'est alors trié dans aucun des deux ordres.
    
    La première solution à laquel nous avons pensé était de séparer le tableau en deux afin de trier les valeurs positives d'une part et les négatives de l'autre. Il s'agissait soit, d'inverser l'ordre de la partie négative à sa sortie, soit de modifier l'algo pour lui donner l'effet inverse. Enfin on aurait mis les deux parties bout à bout. Cependant, cette méthode semblait être gourmande en temps et en mémoire, c'est pourquoi nous avons appliqué autre chose.

    La solution privilégiée fut d'étendre notre tableau gérant l'histogramme des valeurs à des chiffres négatifs. Ainsi au niveau consommation mémoire on utilise seulement 10 long en plus et il n'est pas nécessaire de séparer ou inverser notre tableau ce qui est beaucoup moins gourmand en temps.

    Enfin, le pire des cas pour le tri radix est le tableau constant. Cependant, ce dernier cas peut facilement être amélioré. En effet, au début de l'algorithme on cherche le minimum et le maximum du tableau pour connaitre le nombre de boucle à effectuer. Il suffit de comparer les deux et si les valeurs sont les mêmes c'est que le tableau est constant et donc déjà trié.

## Etude approfondie

### Hypothèse

Les tableaux qui possèdent une partie d'un certain type (croissant, décroissant, constant, aléatoire) et une deuxième d'un autre type sont optimisés pour le tri fusion car il utilise une partition. Comme d'autres tris sont plus performant que le tri fusion pour certains type de tableaux, le sont-ils aussi lors d'un mélange de type ? Ce mélange pourrait être hétérogène, c'est-à-dire, deux types de tableaux différents dans chaque partie, ou homogène, le même type dans les deux sous-parties mais qui au global ne correspond pas à un tableau de ce type (par exemple deux sous parties triés mais indépendantes).

### Protocole expérimental de vérification de l'hypothèse

Nous allons nous concentrer sur les types de tableaux et tris qui nous ont donnés les meilleurs résultats lors de la phase une pour crées les données et les tris que nous mettrons en concurences avec le tri fusion.

- Tri insertion :

    Le tri insertion est extrêmement efficace pour les tableaux croissants et constants mais vraiement très lent pour le reste. Ainsi on le testeras sur des tableaux suivants :

    - deux sous-parties croissantes
    - deux sous-parties constantes
    - partie croissante + partie constante
  
  
- Tri rapide :

    Le tri rapide est plus rapide que le fusion pour les tableaux aléatoires, croissants et décroissants.
    Ainsi on le testeras sur des tableaux suivants :

    - deux sous-parties croissantes
    - deux sous-parties décroissantes
    - partie croissante + partie décroissante
    - partie croissante + partie aléatoire
    - partie décroissante + partie aléatoire
  
  
- Tri radix :

    Le tri radix a un temps d'execution assez proche du fusion pour tout les type de tableau et il est plus rapide pour les constants. Cependant l'amélioration éffectuée pour les tableaux constants ne va pas fonctionner pour les mélanges de types car elle se base de la comparaison du plus grand et du plus petit élément du tableau. On peut donc éliminer ce type qui nous donneras forcément des résultats moins bons que ceux du fusion.
    Ainsi on le testeras sur des tableaux suivants :
    
    - deux sous-parties croissantes
    - deux sous-parties décroissantes
    - partie croissante + partie décroissante
    - partie croissante + partie aléatoire
    - partie décroissante + partie aléatoire
  
  
Notre procèdure d'execution reste sensiblement la même qu'auparavant.  
En premier lieu vient l'execution de perf2.sh avec la ligne suivante :

```
./perf.sh <nbRepetition> <tailleMaxTableau> <minVal> <maxVal> <premierType> <deuxiemeType> >> <nom_du_fichier>
```

Les paremètres que nous utilisons sont toujours les mêmes et ont été définis comme suit :  
Nombre de tests : 30  
Taille maximale des tableaux : 1 000 000  
Valeur minimale : -10 000  
Valeur maximale : 10 000  

On retrouvera des données dans le fichier créé de la maniere suivante :

````$xslt
iTest	taille	min	max	nom_tri	type_tab	indexChange	premierType	deuximeType	temps	mem
1	222813	-10000	10000	f	m	15263	c	a	0.12	4856
1	222813	-10000	10000	r	m	15263	c	a	0.07	3320
1	222813	-10000	10000	x	m	15263	c	a	0.09	4740
2	514531	-10000	10000	f	m	371204	c	a	0.23	9404
2	514531	-10000	10000	r	m	371204	c	a	0.14	5628
2	514531	-10000	10000	x	m	371204	c	a	0.18	9388
3	616549	-10000	10000	f	m	82911	c	a	0.32	10940
````

Une fois les données verifié, on lance R et on tape les commande suivante :

````$xslt
library(ggplot2)
````
(import d'une librairie pour de plus beau graphique)

````$xslt
perf <- read.table("nom_du_fichier", header = TRUE)
````
(import des données)

````$xslt
ggplot(perf,aes(x=taille, y=temps, group=nom_tri, colour=as.character(nom_tri))) + geom_point() + geom_smooth() + ggtitle("titre du tableau")
````
(créer un graphique à partir des données importé avec une courbe par tri)

````$xslt
ggsave("nom_du_tableau.png")
````
(créer une image a partir du graphique)  


### Résultats expérimentaux

| Jeu de test                                | Temps d'execution par tris       |
|--------------------------------------------|----------------------------------|
| deux sous-parties croissantes              | ![plot](./TP2/Resultat/graphe_c_c.png) |
| deux sous-parties décroissantes            | ![plot](./TP2/Resultat/graphe_d_d.png) |
| deux sous-parties constantes               | ![plot](./TP2/Resultat/graphe_u_u.png) |
| partie croissante + partie décroissante    | ![plot](./TP2/Resultat/graphe_c_d.png) |
| partie croissante + partie aléatoire       | ![plot](./TP2/Resultat/graphe_c_a.png) |
| partie décroissante + partie aléatoire     | ![plot](./TP2/Resultat/graphe_d_a.png) |
| partie croissante + partie constante       | ![plot](./TP2/Resultat/graphe_c_u.png) |

### Analyse des résultats expérimentaux

- Mélanges hétérogènes :

    On observe sur nos différents graphiques que le tri fusion qui se trouve être la courbe en rouge prends toujours plus de temps lors de son execution que les tris radix et rapide. Cependant, dans le cas d'un mélange croissant / constant, le tri fusion est alors bien plus rapide que le tri insertion.

    Ainsi, même si le tri fusion semblait être mieux adapté aux tableaux mélangeant deux types de par sa technique de partition, il s'avère que les tris rapides et radix sont plus optimisés dans les cas sans partie constante.
  

- Mélanges homogènes :

### Discussion des résultats expérimentaux

- Mélanges hétérogènes :

    La différence de temps d'execution du tri fusion est très faible par rapport à celui des deux autres. Cela pourrais s'expliquer notemment par le fait que les partitions de tri fusion prennent du temps en terme de copie des valeurs dans les nouveaux tableaux.
  

- Mélanges homogènes :

## Conclusion et travaux futurs

Les tests que nous avons fait dans le cadre de notre hypothèses pourraient être améliorés dans des travaux futurs. En effet, il reste de nombreuses choses que nous n'avons pas eu le temps de traiter. Voici donc 4 pistes d'améliorations que nous avons identifiées.

Pour chaque jeu de test il serait pertinant de comparer l'influence de la position de séparation entre les deux sous-parties du tableau en la faisant variée à l'aide de nombreux tests et en comparant sur des graphiques.

De même, on pourrais étudier si l'ordre de nos sous-parties influent le temps d'execution. On doublerais alors notre jeu de test pour faire la distinction entre la première et la deuxième partie en inversant les types.

La consommation mémoire de nos tris est une données que nous n'avons pas eu le temps d'étudier dans notre étude approfondie mais elle y a autant sa place que le temps d'executon sur lequel nous nous sommes concentrés.

Enfin, il serait aussi possible d'étudier le cas de tableaux composés de plus de 2 sous-parties.