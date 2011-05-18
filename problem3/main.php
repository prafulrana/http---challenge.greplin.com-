<?
    $sums = 0;
    $count;
    // to check for dups
    $hash = array();
    
    function isBufferValid($buffer)
    {
        $len = count($buffer);
        $leftSums = 0;
        
        if($len < 1)
            return 0;
        
        for ($i = 0; $i < $len-1; $i++)
        {
            $leftSums += $buffer[$i];
        }
        
        if ($leftSums == $buffer[$i])
            return true;
        else
            return false;
    }
    
    function calculateSums($index, $buffer)
    {
        
        $numbers = array(3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99);
        $len = 22;
        
//        $numbers = array(1, 2, 3, 4, 6);
//        $len = 5;
        global $hash;
        global $count;
        
        if ($index > $len)
            return;
        
 
        //echo implode(",", $buffer);
        
        if (isBufferValid($buffer))
        {
            //if ($hash[implode(",", $buffer)] == NULL)
            //{
            $hash[implode(",", $buffer)] = $buffer;
            $count++;
            //echo "\t\t\t\t[x]";
            //}
        }
        
       // echo "\n";
        
        $len = count($buffer);
        
        //next number case
        
        $buffer1 = array();
        
        for ($i = 0; $i < $len; $i++)
        {
            $buffer1[$i] = $buffer[$i];
        }
        
        //crucial diff
        $buffer1[$len] = $numbers[$index];
        
        calculateSums($index+1, $buffer1);
        
        // no next number case
        
        $buffer2 = array();
        
        for ($i = 0; $i < $len; $i++)
        {
            $buffer2[$i] = $buffer[$i];
        }
        
        calculateSums($index+1, $buffer2);
        
    }

    calculateSums(0, array());
    //print_r($hash);
    echo count($hash);
?>