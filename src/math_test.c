#include <math.h>
#include <stdio.h>

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    float x, y;
} Point2D;

Point3D rotateX(Point3D p, float angle) {
    float rad = angle * M_PI / 180.0; // Converte para radianos
    float cosA = cos(rad);
    float sinA = sin(rad);

    Point3D rotated;
    rotated.x = p.x;
    rotated.y = p.y * cosA - p.z * sinA;
    rotated.z = p.y * sinA + p.z * cosA;

    return rotated;
}

Point3D rotateY(Point3D p, float angle) {
    float rad = angle * M_PI / 180.0; // Converte para radianos
    float cosA = cos(rad);
    float sinA = sin(rad);

    Point3D rotated;
    rotated.x = p.x * cosA + p.z * sinA;
    rotated.y = p.y;
    rotated.z = -p.x * sinA + p.z * cosA;

    return rotated;
}

Point3D rotateZ(Point3D p, float angle) {
    float rad = angle * M_PI / 180.0; // Converte para radianos
    float cosA = cos(rad);
    float sinA = sin(rad);

    Point3D rotated;
    rotated.x = p.x * cosA - p.y * sinA;
    rotated.y = p.x * sinA + p.y * cosA;
    rotated.z = p.z;

    return rotated;
}

Point2D projectIsometric(Point3D p) {
    Point2D projected;

    projected.x = (sqrt(3) / 2.0) * p.x - (sqrt(3) / 2.0) * p.y;
    projected.y = 0.5 * p.x + 0.5 * p.y - p.z;

    return projected;
}

int main() {
    // Defina um ponto 3D
    Point3D point = {1.0, 1.0, 1.0};

    // Rotacione o ponto ao redor dos eixos (exemplo: 45 graus em Y)
    Point3D rotated = rotateY(point, 45.0);

    // Projete o ponto rotacionado em isometria
    Point2D projected = projectIsometric(rotated);

    // Exiba o resultado
    printf("Ponto original: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    printf("Ponto rotacionado: (%.2f, %.2f, %.2f)\n", rotated.x, rotated.y, rotated.z);
    printf("Ponto projetado: (%.2f, %.2f)\n", projected.x, projected.y);

    return 0;
}
