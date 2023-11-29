/* Change to test repo */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 2000
#define TIME_STEP 0.1

float Smooth_Derivative(float u, float tau, float T){
    
    /* y_prev and u_prev are static as they need memory */
    static float y_prev = 0;
    static float u_prev = 0;

    /* Output variable */
    float y;

    /* Calculate output */
    y = (u - u_prev + tau*y_prev)/(T + tau);
    
    /* Save input and output for next iteration */
    y_prev = y;
    u_prev = u;

    return y;
}

float Derivative(float u, float T){
    
    /* u_prev static as it needs memory */
    static float u_prev = 0;

    /* Output variable */
    float y;

    /* Calculate output */
    y = (u - u_prev)/T;
    
    /* Save input and output for next iteration */
    u_prev = u;

    return y;
}

int main()
{
    /* Define variables  */
    float t = 0;
    int i = 0;
    float u = 30;
    float y = 0;
    float y_filt = 0;

    /* Open file generated from Xcos */
    FILE *file_in = fopen("data_deriv_input.txt", "r");

    /* Open file for logger */
    FILE *file_out = fopen("data_deriv_output.txt", "w");

    /* Implement iteration using while loop */
    while(i < LENGTH)
    {
        /* Read row from input file */
        if (fscanf(file_in, "%f", &u) < 1)
        {
            printf("End of file");
            exit(0);
        }

        /* Run Smooth_Derivative with tau = 2 */
        y_filt = Smooth_Derivative(u, 2, TIME_STEP);

        /* Run Smooth_Derivative with tau = 0, no filter */
        y = Derivative(u, TIME_STEP);

        /* Log variables in the text file */
        fprintf(file_out,"%f %f %f\n", t, y, y_filt);

        /* Increment time and counter */
        t = t + TIME_STEP;
        i = i + 1;
    }

    fclose(file_in);
    fclose(file_out);
    exit(0);
}
