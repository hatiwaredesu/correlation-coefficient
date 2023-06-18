#include<stdio.h>
#include<math.h>


int main(void)
{

  int imax=30, i, iy, ia;

  float a[imax], x[imax], c[imax], y[imax], temp_sum, snow_sum, temp_snow_sum, aa, s1, ave_temp, bb, s2, ave_snow, s, r;

  FILE *fp;

  fp = fopen("temp_sapporo.txt", "r");

  for (i=0; i<=imax-1; i++)
    {

      fscanf(fp, "%d %f", &iy, &aa);
      a[i] = aa;
    }

  fclose(fp);

  s1 = 0.;

  for (i=0; i<=imax-1; i++)
    {

      s1 = s1 + a[i];

    }

  temp_sum = 0;

  ave_temp = s1 / imax;

  
  fp = fopen("snow_sapporo.txt", "r");

  for (i=0; i<=imax-1; i++)
    {

      fscanf(fp, "%d %f", &ia, &bb);
      c[i] = bb;
    }

  fclose(fp);

  s2 = 0.;

  for (i=0; i<=imax-1; i++)
    {

      s2 = s2 + c[i];

    }

  temp_snow_sum = 0;

  snow_sum = 0;

  ave_snow = s2 / imax;

  for (i=0; i<=imax-1; i++)
    {
      x[i] = a[i] - ave_temp;

      y[i] = c[i] - ave_snow;

      temp_snow_sum = temp_snow_sum + x[i] * y[i];

      x[i] = x[i] * x[i];
      
      temp_sum = temp_sum + x[i];
      
      y[i] = y[i] * y[i];

      snow_sum = snow_sum + y[i];

    }

  temp_sum = sqrt(temp_sum);

  snow_sum = sqrt(snow_sum);

  s = temp_sum * snow_sum;
  
  r = temp_snow_sum / s;

  
    printf("%3.3f\n", r);



  return 0;
}

     

