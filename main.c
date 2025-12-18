#include <stdio.h>
#include <stdlib.h>

/* Calcul du PGCD avec l'algorithme d'Euclide */
int pgcd(int a, int b) {
    if (b == 0)
        return abs(a);
    return pgcd(b, a % b);
}

/* Algorithme d'Euclide étendu */
int euclide_etendu(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int d = euclide_etendu(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return d;
}

/* Résolution de l'équation ax + by = c */
void equation_diophantienne(int a, int b, int c) {
    int d = pgcd(a, b);

    printf("\nPGCD(%d, %d) = %d\n", a, b, d);

    /* Vérification de l'existence des solutions */
    if (c % d != 0) {
        printf("❌ Pas de solution entiere.\n");
        return;
    }

    printf("✅ Il existe des solutions entieres.\n");

    int x0, y0;
    euclide_etendu(a, b, &x0, &y0);

    /* Solution particulière */
    int xp = x0 * (c / d);
    int yp = y0 * (c / d);

    printf("Solution particuliere :\n");
    printf("x = %d, y = %d\n", xp, yp);

    /* Solution générale */
    printf("\nSolution generale :\n");
    printf("x = %d + k * %d\n", xp, b / d);
    printf("y = %d - k * %d\n", yp, a / d);
    printf("avec k ∈ Z\n");
}

int main() {
    int a, b, c;

    printf("Resolution de l'equation ax + by = c\n\n");

    printf("Entrer a : ");
    scanf("%d", &a);

    printf("Entrer b : ");
    scanf("%d", &b);

    printf("Entrer c : ");
    scanf("%d", &c);

    equation_diophantienne(a, b, c);

    return 0;
}
