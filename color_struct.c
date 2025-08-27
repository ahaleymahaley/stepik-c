#include <stdio.h>

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

// считать RGB-формат с консоли
Color getColor() {
	Color z;
	scanf("%hhd%hhd%hhd", &z.red, &z.green, &z.blue);
	return z;
}

// перевод из RGB-формата в число
unsigned long long convertToHTML(Color z) {
	unsigned long long res;
	res = z.blue % 16 + \
	      (z.blue / 16) * 16 + \
	      (z.green % 16) * 16 * 16 + \
	      (z.green / 16) * 16 * 16 * 16 + \
	      (z.red % 16) * 16 * 16 * 16 * 16 + \
	      (z.red / 16) * 16 * 16 * 16 * 16 * 16;
	return res;
}

// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long h) {
	Color z;
	z = (Color){h / (256 * 256), (h % (256 * 256)) / 256, h % 256};
	return z;
}

// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue:
// 255 128 222
// Печатать только числа через пробел и \n в конце!!!
void printRGB(Color z) {
	printf("%d %d %d\n", z.red, z.green, z.blue);
}

// печать цвета в HTML-формате и \n в конце.
// Примеры: FFA902 0AA3FF
void printHTML(Color z) {
	printf("%06llX\n", convertToHTML(z));
}

int main(){
    Color z, z2;
    unsigned long long html;

    z = getColor();
    printRGB(z);

    html = convertToHTML(z);
    printf("%llu\n", html);
    printHTML(z);

    z2 = convertToRGB(html);
    printRGB(z2);

    return 0;
}

