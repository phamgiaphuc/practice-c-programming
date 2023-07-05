#include <stdio.h>

struct Point {
    float x;
    float y;
};

struct Triangle {
    struct Point A;
    struct Point B;
    struct Point C;
};

struct Point calculateOrthocenter(struct Triangle t) {
    struct Point ortho;
    float slopeAB = (t.B.y - t.A.y) / (t.B.x - t.A.x);
    float slopeBC = (t.C.y - t.B.y) / (t.C.x - t.B.x);
    
    ortho.x = (slopeAB * slopeBC * (t.A.y - t.C.y) + slopeBC * (t.A.x + t.B.x) - slopeAB * (t.B.x + t.C.x)) / (2 * (slopeBC - slopeAB));
    ortho.y = -1 * (1 / slopeAB) * (ortho.x - (t.A.x + t.B.x) / 2) + (t.A.y + t.B.y) / 2;

    return ortho;
}

int main() {
    struct Triangle triangle;
    
    printf("Enter coordinates of point A: ");
    scanf("%f %f", &triangle.A.x, &triangle.A.y);

    printf("Enter coordinates of point B: ");
    scanf("%f %f", &triangle.B.x, &triangle.B.y);

    printf("Enter coordinates of point C: ");
    scanf("%f %f", &triangle.C.x, &triangle.C.y);
    
    struct Point orthocenter = calculateOrthocenter(triangle);
    
    printf("\nCoordinates of Orthocenter: (%.2f, %.2f)\n", orthocenter.x, orthocenter.y);

    return 0;
}
