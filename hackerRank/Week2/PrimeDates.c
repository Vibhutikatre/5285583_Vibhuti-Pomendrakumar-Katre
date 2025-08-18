int main() {
    int date_1, month_1, year_1, date_2, month_2, year_2;
    scanf("%d-%d-%d %d-%d-%d", &date_1, &month_1, &year_1, &date_2, &month_2, &year_2);

    int Total_days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int temp = 0;

    while (year_1 < year_2 || (year_1 == year_2 && (month_1 < month_2 || (month_1 == month_2 && date_1 <= date_2)))) {
        int num = date_1*1000000 + month_1*10000 + year_1;
        if (num % 4 == 0 || num % 7 == 0) temp++;

        int dim = Total_days[month_1];
        if (month_1 == 2 && leap(year_1)) dim = 29;

        date_1++;
        if (date_1 > dim) { date_1 = 1; month_1++; }
        if (month_1 > 12) { month_1 = 1; year_1++; }
    }

    printf("%d\n", temp);
    return 0;
}