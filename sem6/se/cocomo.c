#include <stdio.h>
#include <math.h>

double effort(double kloc, double constants[]) {
    return constants[0] * pow(kloc, constants[1]);
}

double timefordev(double effort, double constants[]) {
    return 2.5 * pow(effort, constants[2]);
}

void organic(double kloc, double results[]) {
    double constants[] = {2.4, 1.05, 0.38};
    results[0] = effort(kloc, constants);
    results[1] = timefordev(results[0], constants);
}

void semidetached(double kloc, double results[]) {
    double constants[] = {3.0, 1.12, 0.35};
    results[0] = effort(kloc, constants);
    results[1] = timefordev(results[0], constants);
}

void embedded(double kloc, double results[]) {
    double constants[] = {3.6, 1.2, 0.32};
    results[0] = effort(kloc, constants);
    results[1] = timefordev(results[0], constants);
}

void print_results(const char* mode, double results[]) {
    printf("\nMode: %s\n", mode);
    printf("Effort: %f\n", results[0]);
    printf("Time: %f\n", results[1]);
}

int main() {
    double kloc;
    printf("Enter number of KLOC: ");
    scanf("%lf", &kloc);

    double results[2];

    if (kloc >= 2 && kloc < 50) {
        organic(kloc, results);
        print_results("Organic", results);
    } else if (kloc >= 50 && kloc < 300) {
        semidetached(kloc, results);
        print_results("Semi-detached", results);
    } else if (kloc >= 300) {
        embedded(kloc, results);
        print_results("Embedded", results);
    }

    return 0;
}
