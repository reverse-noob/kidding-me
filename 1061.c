#include <stdio.h>
#include <stdlib.h>

struct intel {
  int day, hour, minute, second;
  char hour_str[3], minute_str[3], second_str[3]; // hour_str = {'1','0','\0'}
};

int main(void){
  // Start day
  struct intel start;
  scanf("Dia %i", &start.day);
  scanf("%s : %s : %s", start.hour_str, start.minute_str, start.second_str);
  start.hour = atoi(start.hour_str), start.minute = atoi(start.minute_str), start.second = atoi(start.second_str);

  // End day
  struct intel end;
  scanf(" Dia %i", &end.day);
  scanf("%s : %s : %s", end.hour_str, end.minute_str, end.second_str);
  end.hour = atoi(end.hour_str), end.minute = atoi(end.minute_str), end.second = atoi(end.second_str);

  // Now, since we have the first and last day on the memory, let's begin

  struct intel event; // the final answer will be stored here
  event.second = ((60 - start.second) + ((59-start.minute)*60) + ((23 - start.hour)*60*60)) + (end.second + (end.minute*60) + (end.hour*60*60)); // (what_have_left_start_day + last_day) *in seconds

  event.minute = event.second / 60, event.second -= event.minute*60;
  if(event.second == 60) event.second -= 60, event.minute += 1;
  event.hour = event.minute / 60, event.minute -= event.hour * 60;
  if(event.minute == 60) event.minute -= 60, event.hour += 1;
  event.day = end.day - start.day - 1;
  if(event.hour >= 24) event.hour -= 24, event.day += 1;

  printf("%i dia(s)\n"
        "%i hora(s)\n"
        "%i minuto(s)\n"
        "%i segundos(s)\n", event.day, event.hour, event.minute, event.second);
  return 0;
}
