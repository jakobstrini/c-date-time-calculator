#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int hour;
    int minute;
    int second;
} Time;

int leapyear(Date d);
void output(int value);
int daysInMonth (Date* d1);
void addDate(Date *d1);
void addTime (Time *t1);



int main(void)
{
    Date d1 = {21, 2, 2024};
    Date d2 = {1, 1, 2023};

    Time t1 = {12, 16, 23};

    output(leapyear(d1));
    output(leapyear(d2));

    addDate(&d1);
    addTime(&t1);

    return 0;
}

void output(int value)
{
    if (value == 1)
    {
        printf("It's a leap year\n");
    }
    else
    {
        printf("It's not a leap year\n");
    }
}


int leapyear(Date d)
    {
        if (d.year % 400 == 0)
        {
            return 1;
        }
        if (d.year % 100 == 0)
        {
            return 0;
        }
        if (d.year % 4 == 0)
        {
            return 1;
        }
        return 0;
    }


int daysInMonth(Date* d1)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d1->month == 2 && leapyear(*d1) == 1)
    {
        days[1] = 29;
    }

    return days[d1->month - 1];
}

void addDate(Date *d1)
{
    int swap;

    printf("Enter a number to add to the date:\n");
    scanf("%d", &swap);


    d1->day += swap; //zum bestehenden Datum dazu rechnen

    while (d1-> day > daysInMonth(d1)) //solange Tag größer als Monat Tage hat, wird korrigiert
    {
        d1->day -= daysInMonth(d1); //Länge des aktuellen Monat wird abgezogen
        d1->month++;

        if (d1->month > 12) // Wenn Monat > 12 ist, Monat = 1, Jahr =+1
        {
            d1->month = 1; //setzt Monat auf 1
            d1->year++; //erhöht Jahr um 1
        }
    }

    printf("The new date is %d.%d.%d\n", d1->day, d1->month, d1->year);
}

void addTime(Time *t1)
{
    int swap;

    printf("Enter the seconds that you want to add to the time:\n");
    scanf("%d", &swap);

    t1->second += swap; //addiert die Sekunden zu den Bestehenden


    t1->minute += t1->second / 60;     //ckckt wie viele volle Minuten drinnen stecken
    t1->second = t1->second % 60;      //ckeckt was nach subtrahieren der Minuten übrig bleibt

    t1->hour += t1->minute / 60;       //ckeckt wie viele volle Stunden in den Minuten stecken
    t1->minute = t1->minute % 60;      //ckeckt was nach subtrahieren der Stunden übrig bleibt

    t1->hour = t1->hour % 24;          // 10 (nach 23 Uhr wieder 0)

    printf("The new time is %d:%d:%d\n", t1->hour, t1->minute, t1->second);


}



