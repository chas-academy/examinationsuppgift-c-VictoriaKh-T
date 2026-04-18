#include <stdio.h> 
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void format_name(char name[]) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {
  int count_names = 5;
  int count_rages = 13;
  int best_index = 0;
  char names[5][11]; 
  float max_avg = 0;
  float averages[5];
  float total_sum = 0;
  
  for(int i = 0; i < count_names; i++){
    float sum = 0;
    
    scanf("%10s", names[i]); 
    format_name(names[i]);
   
    for(int j = 0; j < count_rages; j++) {
      int rage; 
      scanf("%d", &rage);
      sum += rage;
    }
     
    averages[i] = sum / count_rages;
    if (max_avg < averages[i]) {
      max_avg = averages[i]; 
      best_index = i; 
    }

    total_sum += averages[i]; 
  }
  
  printf("%s\n", names[best_index]);

  float total_avg = total_sum / count_names;
  for(int i = 0; i < count_names; i++) {
    if (averages[i] < total_avg) {
      printf("%s\n", names[i]);
    }
  }
  return 0;
}

