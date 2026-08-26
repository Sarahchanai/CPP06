j'ai une str de char -> je comprends ce qu'elle représente -> je la transforme -> je l'affiche ds plusieurs types

NB but du days : rigueur de gest. des cas limites

NB = cast = convers° d'1 type vers 1 autre
Mais le compilateur ne verif jms que le result a du sens -> il fait ce que je demande ^m si c absurde/dangereux
but du module -> apprendre à faire cette verif moi ^m

3 facons differentes pour lesquelles 1 convers° peut mal se passer :

1) valeur hors borne = valeur trop grande/petite pour la boite cible (ex : un double ne va pas rentrer dans un int)
2) la valeur n'a ps de sens pr cette boite (ex : l'inf ou un nan n'existent ps pr un char ou un int )
3) la convers° réussit ms perd de l'info silencieusement (ex : un double très précis qui va devenir un float - précis ss mess d'errreur)

NB : les types forment des hierarchies basees s/ la precision & la generalite


argument (texte brut)
   │
   ▼
ÉTAPE 1 : est-ce un seul caractère non-numérique ?  ──oui──▶ on garde son code ASCII
   │ non
   ▼
ÉTAPE 2 : est-ce un des 6 mots imposés (nan, +inf...) ? ──oui──▶ on garde sa valeur spéciale
   │ non
   ▼
ÉTAPE 3 : est-ce composé uniquement de chiffres/signe/point ? ──oui──▶ on garde le nombre
   │ non
   ▼
ÉTAPE 4 : aucune porte ne s'est ouverte → "Invalid input", on s'arrête là



SI VALEUR NUMERIQUE TROUVEE LORS DES ETAPES 1 A 3 -> 
valeur numérique (stockée en double, la "boîte universelle")
   │
   ├──▶ tentative de convers° vers char
   ├──▶ tentative de convers° vers int
   ├──▶ tentative de convers° vers float
   └──▶ tentative de convers° vers double


   Ces 4 tentatives st indépendantes les unes des autres : chacune pose ses propres questions, avec ses propres règles

   


Exemple :

+ specifique      + large

    int	i			double d
 
	42				 i




static_cast permet de caster des types de même famille

6 mots magiques : 

exemple : cas pratique :
si je tape ./convert "citron"
-> le pg recoit "citron", 6 lettres mais ne sait ps ce que sait -> questions
3 portes/possibilités : un char, un nan(not a number), un nombre
exemple : "c" 
-> étape 1 : 1 seul char 
-> étape 2 : transformation de "c" en 99 (posiition ds table ASCII) donc la valeur = 99.0
-> étape 3 : 




