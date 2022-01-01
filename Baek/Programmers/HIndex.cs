using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] citations) 
    {
        List<int> citList = citations.ToList();

        int count = 0;

        while (true)
        {
            int overCount = citList.FindAll(x => x >= count).Count;
            Console.WriteLine(overCount);

            if (overCount < count)
            {
                break;
            }

            count ++;
        }

        return count - 1;
    }
}