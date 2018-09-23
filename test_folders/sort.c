//CODE DERIVED FROM: https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C
/* Default: STRING/CHAR */
#define DATA_TYPE char*
#define COMPARE(a,b) (strcmp((a),(b)))

/*QUICKSORT FOR INT*/
//#define DATA_TYPE int
//#define COMPARE(a,b) ((a)-(b))

/*QUICKSORT FOR DOUBLE*/
//#define DATA_TYPE double
//#define COMPARE(a,b) ((b)-(a))

void QuickSort(DATA_TYPE list[], int begin, int end)
{
    DATA_TYPE pivot_element; DATA_TYPE hold;
    
    int  start,last,mid;

    while (begin<end)  
    {
        //Sets list division boundaries 
        start = begin; 
        mid = begin + (end-begin)/2; 
        last = end;
        //Pivot is set to middle element
        pivot_element = list[mid];

        while (1)
        {
            while ( (start<=last) && ( COMPARE(list[start],pivot_element) <= 0 ) ) start++;
            while ( (start<=last) && ( COMPARE(list[last],pivot_element)  > 0 ) ) last--;

            if (start>last) break;

            hold=list[start]; list[start]=list[last]; list[last]=hold;

            if (mid==last) mid=start;
            
            start++; last--;
        }

        list[mid]=list[last]; 
        list[last]=pivot_element;
        last--;

        // Recursion is implemented on shorter portions only, limiting number of elements on recursion 
        if ((last-begin)<(end-start))   
        {
            QuickSort(list, begin, last);
            begin=start;
        }
        else
        {
            QuickSort(list, start, end);
            end=last;
        }
    }   
}