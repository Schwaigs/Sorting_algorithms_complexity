
# P4z : Analyse de performances de différents tris

[Grille d'évaluation P4z](https://docs.google.com/spreadsheets/d/1VXeO91rhy04xa0p8KUhWliFl228utHaDir8MstO5Z-M/edit?usp=sharing
)

## Problème

Peut-on créer un algorithme de tri qui soit optimal en comparaison, temps d'execution et memoire utilisé

## Dispositif expérimental

### Application

[code source de l'application](./TP2/main.c)
```
./main <nom_tri> <taille> <type_tab> <min> <max>
```
Notre main permet de lancer n'importe quel tri sur n'importe quel type et taille de tableau. On peut
aussi choisir la valeur minimal et maximal du tableau.

Type de tri possible : [i : insertion]  [f : fusion]  [r : rapide]  [x : radix]

Type de tableau possible : [a : aleatoire]  [c : croissant]  [d : decroissant]

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
flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse
sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cp
uid aperfmperf pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid dca sse4_1 sse4_2
x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb cat_l3 cdp_l3
 invpcid_single pti tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 hle avx2 smep bmi2 erms invpci
d rtm cqm rdt_a rdseed adx smap intel_pt xsaveopt cqm_llc cqm_occup_llc cqm_mbm_total cqm_mbm_local dtherm ida arat pln
pts
bugs            : cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs taa itlb_multihit
bogomips        : 4396.18
clflush size    : 64
cache_alignment : 64
address sizes   : 46 bits physical, 48 bits virtual
power management:
```

### Description de la démarche systématique

Notre workflow s'éxecute de la manière suivante:
execution de perf.sh avec la ligne suivante :

```
./perf.sh <nbRepetition> <tailleTableau> <minVal> <maxVal>  >> <nom_du_fichier>
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

| Jeu de test          | Tri par Insertion         | Tri Fusion                | Tri Rapide                | Tri Radix                 |
|----------------------|---------------------------|---------------------------|---------------------------|---------------------------|
| Aléatoire            | ![plot](./TP2/Resultat/graphe_inser_aleatoire.png) | ![plot](./TP2/Resultat/graphe_fusion_aleatoire.png)| ![plot](./TP2/Resultat/graphe_rapide_aleatoire_temps.png) | ![plot](./TP2/Resultat/graphe_radix_aleatoire_temps.png)|
| Trié                 | ![plot](./TP2/Resultat/graphe_inser_croissant_temps.png)| ![plot](./TP2/Resultat/graphe_fusion_croissant.png) | ![plot](./TP2/Resultat/graphe_rapide_croissant_temps.png) |  ![plot](./TP2/Resultat/graphe_radix_croissant_temps.png)|
| Tri inversé          | ![plot](./TP2/Resultat/graphe_inser_decroissant.png) | ![plot](./TP2/Resultat/graphe_fusion_decroissant.png) | ![plot](./TP2/Resultat/graphe_rapide_decroissant_temps.png) | ![plot](./TP2/Resultat/graphe_radix_decroissant_temps.png) |

### Consommation mémoire

| Jeu de test          | Tri par Insertion         | Tri Fusion                | Tri Rapide                | Tri Radix                 |
|----------------------|---------------------------|---------------------------|---------------------------|---------------------------|
| Aléatoire            | ![plot](./TP2/Resultat/graphe_inser_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_aleatoire_mem.png) | ![plot](./TP2/Resultat/graphe_radix_aleatoire_mem.png)|
| Trié                 | ![plot](./TP2/Resultat/graphe_inser_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_croissant_mem.png) | ![plot](./TP2/Resultat/graphe_radix_croissant_mem.png)|
| Tri inversé          | ![plot](./TP2/Resultat/graphe_inser_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_fusion_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_rapide_decroissant_mem.png) | ![plot](./TP2/Resultat/graphe_radix_decroissant_mem.png)|

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
