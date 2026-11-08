#include <stdio.h>
#include <locale.h>

void z1();
void z2();
void z3();
double power(double x, int p);

int main() {
    setlocale(LC_CTYPE, "Rus");

    printf("Задание 1\n\n");
    z1();

    printf("\nЗадание 2\n\n");
    z2();

    printf("\nЗадание 3\n\n");
    z3();

    return 0;
}

void z1() {
    char c;

    printf("Введите один символ: ");
    scanf(" %c", &c);  

    switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            printf("Это цифра\n");
            break;
        default:
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (unsigned char)c >= 128)
                printf("Это буква\n");
            else
                printf("Неизвестный символ\n");
    }
}

void z2() {
    float x, y;
    char op;

    printf("Введите выражение без пробелов (например 2.5*4): ");
    scanf("%f%c%f", &x, &op, &y);

    switch (op) {
        case '+':
            printf("=%f\n", x + y);
            break;
        case '-':
            printf("=%f\n", x - y);
            break;
        case '*':
            printf("=%f\n", x * y);
            break;
        case '/':
            if (y != 0)
                printf("=%f\n", x / y);
            else
                printf("Ошибка: деление на ноль\n");
            break;
        case '^':   
            printf("=%f\n", power(x, (int)y));
            break;
        default:
            printf("Неизвестная операция '%c'\n", op);
    }
}

double power(double x, int p) {
    double r = 1.0;
    int i, neg = 0;

    if (p < 0) { neg = 1; p = -p; }
    for (i = 0; i < p; i++)
        r *= x;

    if (neg) r = 1.0 / r;   
    return r;
}

void z3() {
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int n, d, m, year, day, dim;

    printf("Сколько месяцев прошло с января 2000 года: ");
    scanf("%d", &n);
    printf("Сколько дней прошло: ");
    scanf("%d", &d);

    if (n < 0 || d < 0) {
        printf("Числа должны быть неотрицательными\n");
        return;
    }

    m    = n % 12;            
    year = 2000 + n / 12;     
    day  = d + 1;             

    while (1) {
        dim = months[m];
        if (m == 1 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
            dim = 29;        
        if (day <= dim)
            break;
        day -= dim;
        m++;
        if (m == 12) { m = 0; year++; }
    }

    printf("Прошло %d мес. и %d дн. -> %d ", n, d, day);

    switch (m) {
        case 0:  printf("января");   break;
        case 1:  printf("февраля");  break;
        case 2:  printf("марта");    break;
        case 3:  printf("апреля");   break;
        case 4:  printf("мая");      break;
        case 5:  printf("июня");     break;
        case 6:  printf("июля");     break;
        case 7:  printf("августа");  break;
        case 8:  printf("сентября"); break;
        case 9:  printf("октября");  break;
        case 10: printf("ноября");   break;
        case 11: printf("декабря");  break;
    }
    printf(" %d года\n", year);
}
