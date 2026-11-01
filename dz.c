#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float area_deltoid(float R, float a);
void print_definition();
void draw_deltoid_dynamic(int h, int w); 

int main() {
    float R, a;
    int choice;

    printf(" Домашнее задание: Личная фигура (Дельтоид)\n");
    printf("Введите R: ");
    scanf("%f", &R);
    printf("Введите длину стороны a: ");
    scanf("%f", &a);

    printf("\nМеню операций:\n");
    printf("1) Рассчитать площадь\n");
    printf("2) Вывести определение фигуры\n");
    printf("3) Нарисовать фигуру\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    if (choice == 1) {
        float S = area_deltoid(R, a);
        if (S > 0) {
            printf("\nПлощадь дельтоида: %.3f\n", S);
        }
    } 
    else if (choice == 2) {
        print_definition();
    } 
    else if (choice == 3) {
        if ((2 * R) > a) {
            float b = sqrtf(4 * R * R - a * a);
           
            int height = (int)(2 * R * 2); 
            int width = (int)(a * 2);
            
            
            if (height < 5) height = 7;
            if (width < 5) width = 7;
            if (width % 2 == 0) width++; 

            draw_deltoid_dynamic(height, width);
        } else {
            printf("Ошибка размеров, невозможно нарисовать.\n");
        }
    } 
    else {
        printf("Неверный пункт меню.\n");
    }

    return 0;
}


float area_deltoid(float R, float a) {
    if ((2 * R) <= a) {
        printf("Ошибка: диаметр 2R должен быть больше стороны a!\n");
        return 0;
    }
    float b = sqrtf(4 * R * R - a * a);
    return a * b;
}


void print_definition() {
    printf("\n Определение фигуры \n");
    printf("Дельтоид - это четырехугольник, у которого две пары смежных сторон равны.\n");
}


void draw_deltoid_dynamic(int h, int w) {
    printf("\n Рисунок фигуры (Контур %dx%d) \n", w, h);
    int mid_x = w / 2; 
    int mid_y = h / 2; 

    for (int y = 0; y <= h; y++) {
        for (int x = 0; x <= w; x++) {
           
            if (y <= mid_y) {
              
                int dx = (x - mid_x);
                if (dx < 0) dx = -dx;
                
                
                if (dx == (y * mid_x) / mid_y) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } 
            
            else {
                int dx = (x - mid_x);
                if (dx < 0) dx = -dx;
                
            
                if (dx == ((h - y) * mid_x) / (h - mid_y)) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

