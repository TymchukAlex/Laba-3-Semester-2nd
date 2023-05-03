#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


typedef struct Circle{
   float rad;
   float square;
   float length;
   bool umova;
} circle;

float input_formula();
float calculate_length(float radius);
float calculate_square(float radius);
void output_characteristics_of_circle(circle *ss, int i);
float execute();
void check_umovu(circle *ss, int n);

void main()
{
    execute();
}

float input_radius(){
    float rad;
    
    printf("dlia vikonannia rozrahunkiv vistachaie tilki radiuse, tomu vvedit yogo:  ");
    scanf("%f",&rad);
    
    return rad;
}

float calculate_length(float radius){
    float x;
    
    x = 2*M_PI*radius;
    
    return x;
}

float calculate_square(float radius){
    float x;
    
    x = M_PI*radius*radius;
    
    return x;
}

float execute(){
    int n,i;
    float x;
    
    printf("input number of circles ");
    scanf("%d",&n);
    
    circle* qq = (circle*)malloc(n*sizeof(circle));
    
    for(i = 0;i < n;i++){
        
        printf("\n\n%d)",i);
        
        qq[i].rad = input_radius();
        x = qq[i].rad;
        qq[i].square = calculate_square(x);
        qq[i].length = calculate_length(x);
        
        output_characteristics_of_circle(qq,i);
        
        if(qq[i].square  < qq[i].length){
            qq[i].umova = true;
        }
        else{qq[i].umova = false;}
    }
    
    check_umovu(qq,n);

    free(qq);
}

void output_characteristics_of_circle(circle *ss, int i){
    
    printf("\n%f",ss[i].rad);
    printf("\n%f",ss[i].square);
    printf("\n%f",ss[i].length);
    
}

void check_umovu(circle *ss, int n){
    
    int i;
    
    printf("\nUmovu zadovilnaut kola №:   ");
    
    for(i=0;i<n;i++){
        if(ss[i].umova==true){
            printf(" %d ",i);
        }
    }
}
