#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    FILE *input;
    input = fopen("data.csv", "r");
    char chain[100];
    char chain2[100];
    float avg = 0.0, x, xi, sum = 0.0;

    if (input == NULL) {
        printf("Error, can't open file \n");
        exit(1);
    }

    while (fgets(chain, 98, input) != NULL) {
        if (sscanf(chain, "%f", &x) == 1) {
            avg += x;
        }
    }

    avg = avg / 100;
    input = fopen("data.csv", "r");

    while (fgets(chain, 98, input) != NULL) {
        if (sscanf(chain, "%f", &x) == 1) {
            sum += (x - avg) * (x - avg);
        }
    }


    //printf("Avg: %f \n", avg);
    //printf("xi - avg: %f \n", sum);
    float h = sqrt((sum) / 100);
    printf("Desviacion: %f", h);

    return 0;
}