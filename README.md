# Tp.Equtions-diophantiennes-lineaires
Introduction

Une équation diophantienne linéaire est une équation de la forme :

ax + by = c

où a, b, c sont des entiers relatifs donnés, et où l’on cherche toutes les solutions entières (x, y) \in \mathbb{Z}^2.

Ces équations apparaissent souvent en mathématiques discrètes, en algorithmique et en cryptographie.
La résolution repose essentiellement sur le PGCD et l’algorithme d’Euclide étendu.

⸻

Méthode de résolution

Étape 1 : Vérification de l’existence des solutions

On calcule :
d = \gcd(a, b)
	•	Si d \nmid c → ❌ aucune solution entière
	•	Si d \mid c → ✅ au moins une solution entière

⸻

Étape 2 : Recherche d’une solution particulière

À l’aide de l’algorithme d’Euclide étendu, on trouve :
ax_0 + by_0 = d

Alors une solution particulière de ax + by = c est :
x_p = x_0 \cdot \frac{c}{d}, \quad y_p = y_0 \cdot \frac{c}{d}

⸻

Étape 3 : Solution générale

Toutes les solutions sont données par :

\begin{cases}
x = x_p + k \cdot \frac{b}{d} \\
y = y_p - k \cdot \frac{a}{d}
\end{cases}
\quad \text{avec } k \in \mathbb{Z}
