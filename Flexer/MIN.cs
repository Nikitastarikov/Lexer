using System;
class Begin{
    static void Main(){
        var array = new int[10]{1, 5, -1, 2, 35, 16, 3, 7, 9, 4};
        int min = array[0];
        for(int i = 0; i < 10; i++){
            if(min > array[i])
                min = array[i];
        }
        Console.WriteLine(min);
    }
}