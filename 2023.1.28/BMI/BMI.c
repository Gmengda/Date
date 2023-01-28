#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int weight = 0, height = 0;
    float BMI = 0.0;

    while (scanf("%d %d", &weight, &height) != EOF) {

        BMI = weight / (height / 100.0 * height / 100.0);

        if (BMI < 18.5)
            printf("Underweight\n");
        else if (BMI >= 18.5 && BMI <= 23.9)
            printf("Normal\n");
        else if (BMI > 23.9 && BMI <= 27.9)
            printf("Overweight\n");
        else
            printf("Obese\n");
    }
    return 0;
}