/*
 Programmer: Sharon Tender
 Description: Customer Statistics
 Date: 3/23/15
 Input: zip code, age, numItems, custCounter, zipCounter
 Output: avgCustomerAge, customer count for local zip, customer count for non-local zip,
 Item count for customers over 30, Item count for customers under 30
 calculations: avgCustomerAge=totalAge/CustCounter & zipNonLocal=custCounter-zipLocalCounter 
 */

#include <stdio.h>
#define ZIPCODE 54984
#define HIGH_AGE 110
#define MED_AGE 30
#define LOW_AGE 10
#define FLAG 0
#define HIGH_ITEMS 12
#define LOW_ITEMS 1

int main()
{
    int zipcode, numItems, i=0, totalItems=0, localItemCounter=0, itemCounter=0;
    int age, under30counter=0, over30counter=0, totalAge=0;
    int under30Items, over30Items, custCounter=0, localZipCounter=0, zipCounter=0;
    float avgCustAge;

    // program description
    printf("\n  Customer Statistics\n");
    printf("  Enter zip code, age, and number of items \n");
    printf("  purchased to find shopping statistics.\n");
    printf("  Enter '0' for zip code to end program.\n ");
    printf("  ............................................\n");
	
    do
    {
        // get customer zip code
        printf("\n  Enter zip code: ");
        scanf("%d", &zipcode);
        if (zipcode==FLAG) {
            break;
        }
        if (zipcode>99999) {
            do {
                printf("  *** Invalid, try again: ");
                scanf("%d", &zipcode);
            } while (zipcode>99999);
        }

        // get customer age
        printf("  Enter customer age: ");
        scanf("%d", &age);

        if ((age<LOW_AGE) || (age>HIGH_AGE)) {
            do{
                printf("  *** Invalid, try again: ");
                scanf("%d", &age);
            } while ((age<LOW_AGE) || (age>HIGH_AGE));
        }

        // get number of purchased items
        printf("  Enter number of items: ");
        scanf("%d", &numItems);

        // get data totals
        totalAge = age + totalAge;
        totalItems = numItems + totalItems;

        if (zipcode==ZIPCODE){
            localZipCounter++;
            localItemCounter += numItems;
        }
        else {
            zipCounter++;
            itemCounter += numItems;
        }
        if (age<MED_AGE) {
            under30counter++;
            under30Items += numItems;
        }
        else {
            over30counter++;
            over30Items += numItems;
        }
        numItems = 0;
        age = 0;

    }while(zipcode != 0);
	
    custCounter = zipCounter + localZipCounter;
    avgCustAge = totalAge/custCounter;
    zipCounter = custCounter - localZipCounter;

    // display statistics
    printf("  Results \n");
    printf("  ............................................\n");
    printf("  Customers under 30 years old: %d\n", under30counter);
    printf("  Items: %d\n", under30Items);

    printf("\n  Customers 30 years old or over: %d\n", over30counter);
    printf("  Items: %d\n", over30Items);

    printf("\n  Average custormer age: %.1f\n", avgCustAge);

    printf("\n  Customers in local area: %d\n", localZipCounter);
    printf("  Items: %d\n", localItemCounter);

    printf("\n  Customers out of area: %d\n", zipCounter);
    printf("  Items: %d\n", itemCounter);

    return 0;
}