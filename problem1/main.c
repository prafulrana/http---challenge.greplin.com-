#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//-------------------
/*
    [a][b][c][d][e] [len = 5]
    [0][1][2][3][4]
 
    this will return true
 
    [0][b][c][d][d]
 
    this will return false
 
    algo:
    
    all the way through is
    a[n] == a[len - n - 1]
*/
//--------------------

int isSameBackwardForward (char* a, int len) 
{
    int i = 0;
    
    if (i%2 == 0)
    {
        for (i = 0; i < len/2; i++)
        {
            if(a[i] != a[len - i - 1])
                return 0;
        }
    }
    else
    {
        for (i = 0; i <= len/2; i++)
        {
            if (a[i] != a[len - i - 1])
                return 0;            
        }
    }

    return 1;
}

void testIsSameBackwardForward()
{
    printf("___a is %d\n", isSameBackwardForward("a", 1));
    printf("_aaa is %d\n", isSameBackwardForward("aaa", 3));
    printf("aaab is %d\n", isSameBackwardForward("aaab", 4));
    printf("aaaa is %d\n", isSameBackwardForward("aaaa", 4));
}

//----------------------------------------------------------
// dp step
/*
 sweep from a[0] -> a[n] as i
    sweep from i -> a[n] as j
        keep global max of length that fits
            isSameBackwardForward(substr(a, i, j))
    end of sweep
 end of sweep
 
 O[N^2] [not that bad]
*/
//----------------------------------------------------------

char * dpStep (char * input, int len)
{
    int i = 0;
    int j = 0;
    
    //temporary length holder
    int t_len = 0;
    
    //longest char sequence len
    int max_len = 0;
    
    //longest char sequence
    char* cs = (char*) malloc (len * sizeof(char));
    
    //temporary char sequence for working
    char* ts = (char*) malloc (len * sizeof(char));
    
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
           
            
            strncpy(ts, input + i, j-i);
            ts[j-i-1] = '\0';            
            t_len = strlen(ts);
            
            //debug
            printf("the different substrings are %s\n", ts);
            
            
            //if its the same backwarsd or forwards
            if (isSameBackwardForward(ts, t_len))
            {
                printf("string identified %s\n", ts);
                
                //if indeed its that big
                if (t_len > max_len)
                {
                    //copy it as our new max
                    strncpy(cs, ts, t_len);
                    ts[t_len-1] = '\0';
                    max_len = t_len; //dont forget to update the max_len!
                }
            }
        }
    }
    
    //free temp buffer
    free(cs);
    
    printf("dpStep conluded with a string of length %d\n", max_len);
    
    return cs;
}


int main()
{
    //test isSameBackwardForward
    testIsSameBackwardForward();
    
    char* test = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    
    
    printf("%s\n", dpStep(test, strlen(test)));
    
    //answer was ranynar
    
    return 0;
}