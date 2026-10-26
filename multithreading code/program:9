#include <stdio.h>
#include <string.h>

int main() {
    float g; 
    char p[10];
    
    printf("Glucose (mg/dL): "); 
    scanf("%f", &g);
    
    printf("Priority (H/L) = "); 
    scanf("%s", p);
    
    char *s = (g < 70) ? "CRITICAL-HYPOGLYCEMIA" : 
              (g > 180) ? "CRITICAL-HYPERGLYCEMIA" : 
              (g < 100 || g > 140) ? "WARNING" : "NORMAL";
              
    printf("status = %s | priority : %s\n", s, p);
    
    if ((!strcmp(p, "High") || !strcmp(p, "high")) && strstr(s, "CRITICAL")) {
        printf(">>> HIGH PRIORITY ALERT: Immediate action required!\n");
    }
    
    return 0;
}
