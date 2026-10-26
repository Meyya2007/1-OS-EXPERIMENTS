#include <stdio.h>
#include <string.h>

int main() {
    int c, n, q, i;
    int g[5], r[5], t = 0;
    float gl;
    char p[10];
    
    printf("1. priority 2. R.R: ");
    scanf("%d", &c);
    
    if (c == 1) {
        printf("glucose priority: ");
        scanf("%f %s", &gl, p);
        
        char *s = (gl < 70) ? "Critical" : 
                  (gl > 180) ? "CRITICAL" : 
                  (gl < 100 || gl > 140) ? "WARNING" : "NORMAL";
                  
        printf("%s %s\n", s, p);
        
        if (strstr(s, "CRIT") && !strcmp(p, "High")) {
            printf("Alert\n");
        }
    } 
    else {
        printf("N Q: ");
        scanf("%d %d", &n, &q);
        
        for (i = 0; i < n; i++) {
            scanf("%d", &g[i]);
            r[i] = g[i];
        }
        
        printf("T: %d\n", t);
    }
    
    return 0;
}
