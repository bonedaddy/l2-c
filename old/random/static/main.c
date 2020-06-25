   #include <stdio.h>
   int sum (int num) {
       static int count;
       count = count + num;
       return count;
       /**
       * find sum to n numbers
       */
   }

   int main() {
       printf("%d ",sum(55));
       printf("%d ",sum(45));
       printf("%d ",sum(50));
       return 0;
   }