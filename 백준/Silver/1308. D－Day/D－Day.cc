#include <stdio.h>

int isyoon(int n)

{

  int result = 0;

  if (n % 4 == 0)

  {

    result = 1;

    if (n % 100 == 0) result = 0;

    if (n % 400 == 0) result = 1;

  }

  return result;

}

int main()

{

  int year, month, day, dyear, dmonth, dday, yoon = 0, out=0;

  int dayofmonth[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31}}, dayofyear[2] = { 365,366 };

  long long result = 0;

  scanf("%d %d %d", &year, &month, &day);

  scanf("%d %d %d", &dyear, &dmonth, &dday);

  if (dyear - year > 1000) out = 1;

  else if (dyear - year == 1000) if ((dmonth > month) || (dmonth == month && dday >= day)) out = 1;

    

  if (out == 1) printf("gg");

  else

  {

    for (int i = year + 1; i < dyear; i++) result += dayofyear[isyoon(i)];

    if (dyear == year)

    {

      yoon = isyoon(dyear);

      for (int i = month + 1; i < dmonth; i++) result += dayofmonth[yoon][i - 1];

      if (dmonth == month) result += dday - day;

      else

      {

        result += dayofmonth[yoon][month - 1] - day;

        result += dday;

      }

    }

    else

    {

      yoon = isyoon(year);

      result += dayofmonth[yoon][month - 1] - day;

      for (int i = month + 1; i <= 12; i++) result += dayofmonth[yoon][i - 1];

      yoon = isyoon(dyear);

      result += dday;

      for (int i = 1; i < dmonth; i++) result += dayofmonth[yoon][i - 1];

    }

    printf("D-%lld", result);

  }

}