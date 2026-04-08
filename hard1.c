#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    //enter odd order for single origin 
    int arena[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            arena[i][j] = 1; 
        }
    }
     printf("Enter the number of obstacles: ");
    scanf("%d", &m);
    
    int ox,oy;
    if (n%2!=0) {
        ox = n / 2;
        oy = n / 2;
        printf("Odd Matrix detected. Origin set at [%d, %d]\n", ox, oy);
    } else {
  // 4 centers will be detected here 
        ox = ((n / 2) - 1); 
        oy = ((n / 2) - 1);
        printf("Even Matrix detected. Origin set at [%d, %d]\n", ox, oy);
    }
    
    int obst[m][4];
    for(int i = 0; i < m; i++) {
        printf("Enter the 4 coordinates for obstacle north, east, south, west %d: ", i + 1);
        for(int j = 0; j < 4; j++) {
            scanf("%d", &obst[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        
        int x_final = ox +(obst[i][1] -obst[i][3]);
        int y_final = oy + (obst[i][0] - obst[i][2]);

        if(x_final >= 0 && x_final < n && y_final >= 0 && y_final < n) {
            arena[x_final][y_final] = 0; 
        }
        else {
            printf("Obstacle %d at calculated position [%d, %d] is outside the %dx%d matrix!\n", 
                    i + 1, x_final, y_final, n, n);
        }
    }
    printf("\n");
//considering horizontal line as y axis and vertical as x axis here
    printf("Generated Arena:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           
            if(arena[i][j] == 0) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
}