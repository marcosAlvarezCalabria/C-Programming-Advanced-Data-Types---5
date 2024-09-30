#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
void readDate(struct date *fecha){
    scanf("%d %d %d", &(*fecha).year, &(*fecha).month, &(*fecha).day);
    
    
}
void printDate(struct date today){

    if(today.day < 10 && today.month < 10){
        printf("0%d/0%d/%d", today.month, today.day, today.year);
    }else if (today.day > 10 && today.month < 10){
        printf("0%d/%d/%d", today.month, today.day, today.year);
    } else if (today.day < 10 && today.month > 10){
        printf("%d/0%d/%d", today.month, today.day, today.year);
    }
    

    
}
