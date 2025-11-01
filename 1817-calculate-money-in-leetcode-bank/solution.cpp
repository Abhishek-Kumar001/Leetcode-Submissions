class Solution {
public:
    int totalMoney(int n) {
        int firstWeakSaving = 0;
        for(int i=1; i<=7; i++) firstWeakSaving+=i;

        int noOfWeaks = n / 7;
        int noOfDays = n % 7;
         
        // calculating total saving
        
        // if he save same amount of money every week
        int totalSaving = noOfWeaks * firstWeakSaving;
        // but since every week, he same 7 extra than previous week
        int seven = 7;
        for(int i=1; i<noOfWeaks; i++){
          totalSaving += seven;
          seven+=7;
        }
        // now in the current week, the money he save.. we will add that
        for(int i=1; i<=noOfDays; i++) totalSaving += (++noOfWeaks);

        return totalSaving;
    }
};
