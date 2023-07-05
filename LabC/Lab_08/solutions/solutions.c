#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure
struct Point {
     float x;
     float y;
};

struct Distance {
     float distance;
};

typedef struct Point Triangle;
typedef struct Point Centroid;
typedef struct Point Orthocenter;
typedef struct Point RandomPoint;
typedef struct Distance Triangle_Side;

// Functions
void input(Triangle *const);
void output(Triangle *const);
int isTriangle(Triangle *const, Triangle_Side *const);
float distance(Triangle const, Triangle const);
int isEqual(Triangle_Side *const, Triangle_Side *const);
float perimeter(Triangle_Side *const);
float area(Triangle_Side *const, float);
struct Point centroid(Triangle *const);
struct Point orthocenter(Triangle *const);
int isInsideTriangle(Triangle *const, RandomPoint *const, float);
float areaSection(float, float, float, float, RandomPoint *const);
int isEquilateral(Triangle_Side *const);
int isIsosceles(Triangle_Side *const);
int isRightTriangle(Triangle_Side *const);

int main() {
     // Declare variables
     Triangle triangle1[3];
     Triangle_Side triangle1_side[3];
     Triangle triangle2[3];
     Triangle_Side triangle2_side[3];
     Centroid center_point1;
     Centroid center_point2;
     Orthocenter orthocenter_point1;
     Orthocenter orthocenter_point2;
     RandomPoint random_point[1];

     // Input the coordinates of the triangle
     printf("Triangle 1\n");
     input(triangle1);
     printf("\nTriangle 2\n");
     input(triangle2);

     // Output the coordinates of the triangle
     printf("Triangle 1\n");
     output(triangle1);
     printf("\nTriangle 2\n");
     output(triangle2);
     printf("\n");

     // Check whether 3 given points form a triangle or not
     if (isTriangle(triangle1, triangle1_side) == -1) {
          printf("Triangle 1 is not a triangle!\n");
     } else {
          printf("Triangle 1 is a triangle!\n");
     }

     if (isTriangle(triangle2, triangle2_side) == -1) {
          printf("Triangle 2 is not a triangle!\n");
     } else {
          printf("Triangle 2 is a triangle!\n");
     }
     printf("\n");

     // Check whether 2 given triangles are equal
     if (isEqual(triangle1_side, triangle2_side) == 1) {
          printf("2 triangles are equals!\n");
     } else {
          printf("2 triangles are not equals!\n");
     }
     printf("\n");

     // Calculate the perimeter of given triangles
     float triangle1_perimeter = perimeter(triangle1_side);
     float triangle2_perimeter = perimeter(triangle2_side);
     printf("The perimeter of triangle 1 is %.1f\n", triangle1_perimeter);
     printf("The perimeter of triangle 2 is %.1f\n", triangle2_perimeter);
     printf("\n");

     // Calculate the area of given triangles
     float triangle1_area = 0, triangle2_area = 0;
     triangle1_area = area(triangle1_side, triangle1_perimeter);
     triangle2_area = area(triangle2_side, triangle1_perimeter);
     printf("The area of triangle 1 is %.1f\n", triangle1_area);
     printf("The area of triangle 2 is %.1f\n", triangle2_area);
     printf("\n");

     // The centroid of the triangle (center point)
     center_point1 = centroid(triangle1);
     printf("The centroid of triangle 1 is (%.1f, %.1f)\n", center_point1.x, center_point1.y);
     center_point2 = centroid(triangle2);
     printf("The centroid of triangle 2 is (%.1f, %.1f)\n", center_point2.x, center_point2.y);
     printf("\n");

     // The orthocenter of the triangle (intersect of 3 heights)
     orthocenter_point1 = orthocenter(triangle1);
     printf("The orthocenter of triangle 1 is (%.1f, %.1f)\n", orthocenter_point1.x, orthocenter_point1.y);
     orthocenter_point2 = orthocenter(triangle2);
     printf("The orthocenter of triangle 2 is (%.1f, %.1f)\n", orthocenter_point2.x, orthocenter_point2.y);
     printf("\n");

     // Calculate the area of each section -> We will compare with the triangle 1
     printf("Random Point\n");

     printf("Print the x coordinate for point random point: ");
     scanf("%f", &random_point[0].x);

     printf("Print the y coordinate for point random point: ");
     scanf("%f", &random_point[0].y);

     if (isInsideTriangle(triangle1, random_point, triangle1_area) == 1) {
          printf("The given random point is in the triangle 1!\n");
     } else {
          printf("The given random point is not in the triangle 1!\n");
     }
     printf("\n");

     // Check whehter the triangle is equilateral
     if (isEquilateral(triangle1_side) == 1) {
          printf("Triangle 1 is equilateral!\n");
     } else {
          printf("Triangle 1 is not equilateral!\n");
     }

     if (isEquilateral(triangle2_side) == 1) {
          printf("Triangle 2 is equilateral!\n");
     } else {
          printf("Triangle 2 is not equilateral!\n");
     }

     printf("\n");

     // Check whehter the triangle is isosceles
     if (isIsosceles(triangle1_side) == 1) {
          printf("Triangle 1 is isosceles!\n");
     } else {
          printf("Triangle 1 is not isosceles!\n");
     }

     if (isIsosceles(triangle2_side) == 1) {
          printf("Triangle 2 is isosceles!\n");
     } else {
          printf("Triangle 2 is not isosceles!\n");
     }
     printf("\n");

     // Check whether the triangle is right triangle
     if (isRightTriangle(triangle1_side) == 1) {
          printf("Triangle 1 is right triangle!\n");
     } else {
          printf("Triangle 1 is not right triangle!\n");
     }

     if (isRightTriangle(triangle2_side) == 1) {
          printf("Triangle 2 is right triangle!\n");
     } else {
          printf("Triangle 2 is not right triangle!\n");
     }
     printf("\n");


     return 0;
}

// Input the coordinates of the triangle
void input(Triangle *const point) {
     for (int i = 0; i < 3; i++) {
          printf("Print the x coordinate for point %d: ", i + 1);
          scanf("%f", &point[i].x);
          printf("Print the y coordinate for point %d: ", i + 1);
          scanf("%f", &point[i].y);
     }
}

// Output the coordinates of the triangle
void output(Triangle *const point) {
     for (int i = 0; i < 3; i++) {
          printf("The x and y coordinate for point %d is (%.1f, %.1f)\n", i + 1, point[i].x, point[i].y);
     }
}

// Check whether 3 given points form a triangle or not
int isTriangle (Triangle *const point, Triangle_Side *const side) {
     side[0].distance = distance(point[0], point[1]);
     side[1].distance = distance(point[0], point[2]);
     side[2].distance = distance(point[1], point[2]);
     if ((side[0].distance + side[1].distance > side[2].distance) && (side[0].distance + side[2].distance > side[1].distance) && (side[1].distance + side[2].distance > side[0].distance)) {
          return 1;
     }
     return -1;
}

// Calculate the distance between 2 cordinates
float distance(Triangle const point_1, Triangle const point_2) {
     float dx = (point_2.x - point_1.x);
     float dy = (point_2.y - point_1.y);
     return sqrt(dx*dx + dy*dy);
}

// Check whether 2 given triangles are equal
int isEqual (Triangle_Side *const side1, Triangle_Side *const side2) {
     int check = 0, perimeter_side1, perimeter_side2;
     for (int i = 0; i < 3; i++) {
          float length_1 = side1[i].distance;
          for (int j = 0; j < 3; j++) {
               float length_2 = side2[j].distance;
               if (length_1 == length_2) {
                    check += 1;
               }
          }
     }

     perimeter_side1 = side1[0].distance + side1[1].distance + side1[2].distance;
     perimeter_side2 = side2[0].distance + side2[1].distance + side2[2].distance;

     if ((check == 3) && (perimeter_side1 == perimeter_side2)) {
          return 1;
     }
     return -1;
}

// Calculate the perimeter of the given triangles
float perimeter(Triangle_Side *const side) {
     return side[0].distance + side[1].distance + side[2].distance;
}

// Calculate the area of the given triangles
float area(Triangle_Side *const side, float triangle_perimeter) {
     float half_perimeter = triangle_perimeter / 2;
     return sqrt(half_perimeter * (half_perimeter - side[0].distance) * (half_perimeter - side[1].distance) * (half_perimeter - side[2].distance));
}

// The centroid of the triangle (center point) 
struct Point centroid(Triangle *const point) {
     struct Point center_point;

     center_point.x = (point[0].x + point[1].x + point[2].x) / 3;
     center_point.y = (point[0].y + point[1].y + point[2].y) / 3;

     return center_point;
}

// The orthocenter of the triangle (intersect of 3 heights)
struct Point orthocenter(Triangle *const point) {
     struct Point orthocenter_point;

     double slope_1 = (point[0].y - point[1].y) / (point[0].x - point[1].x);
     double slope_2 = (point[1].y - point[2].y) / (point[1].x - point[2].x);
     
     orthocenter_point.x = (slope_1 * slope_2 * (point[0].y - point[2].y) + slope_2 * (point[0].x + point[1].x) - slope_1 * (point[1].x + point[2].x)) / (2.0 * (slope_2 - slope_1));
     orthocenter_point.y = (-1.0 / slope_1) * (orthocenter_point.x - (point[0].x + point[1].x) / 2.0) + (point[0].y + point[1].y) / 2.0;
     
     return orthocenter_point;
}

// Calculate the area of each section -> We will compare with the triangle 1
int isInsideTriangle(Triangle *const point, RandomPoint *const randome_point, float triangle_area) {
     float area_section1, area_section2, area_section3, sum_area_sections;

     area_section1 = areaSection(point[0].x, point[0].y, point[1].x, point[1].y, randome_point);
     area_section2 = areaSection(point[0].x, point[0].y, point[2].x, point[2].y, randome_point);
     area_section3 = areaSection(point[1].x, point[1].y, point[2].x, point[2].y, randome_point);

     sum_area_sections = area_section1 + area_section2 + area_section3;

     if (fabs(triangle_area - sum_area_sections) <= 0.0001) {
          return 1;
     }
     return -1;
}

float areaSection(float x1, float y1, float x2, float y2, RandomPoint *const point) {
     return fabsf(((x2 - x1) * (point[0].y - y1) - (point[0].x - x1) * (y2 - y1))) / 2;
}

// Check whehter the triangle is equilateral
int isEquilateral(Triangle_Side *const side) {
     if (side[0].distance == side[1].distance && side[0].distance == side[2].distance) {
          return 1;
     }
     return -1;
}

// Check whehter the triangle is isosceles
int isIsosceles(Triangle_Side *const side) {
     if (side[0].distance == side[1].distance || side[0].distance == side[2].distance || side[1].distance == side[2].distance) {
          return 1;
     }
     return -1;
}

// Check whether the triangle is right triangle
int isRightTriangle(Triangle_Side *const side) {
     if (((side[0].distance * side[0].distance)  + (side[1].distance * side[1].distance)) == (side[2].distance * side[2].distance) || ((side[2].distance * side[2].distance) + (side[1].distance * side[1].distance)) == (side[0].distance * side[0].distance) || ((side[0].distance * side[0].distance) + (side[2].distance * side[2].distance)) == ((side[1].distance * side[1].distance))) {
          return 1;
     }
     return -1;
}