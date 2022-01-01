using System;
using System.Linq;
using System.Collections.Generic;

public class FunctionDevelopment
{
    public int[] solution(int[] progresses, int[] speeds) 
    {
        Queue<int> progressQueue = new Queue<int>(); // 남은 날짜

        for (int i = 0; i < progresses.Length; i++)
        {
            progressQueue.Enqueue(FindRemainingDays(progresses[i], speeds[i]));
        }

        int nowDay = -1;
        int progressDay;

        List<int> progressDays = new List<int>();
        
        while (progressQueue.TryDequeue(out progressDay)) // 맨앞에 일 처리 시점
        {
            if (progressDay <= nowDay) // 끝남?
            {
                progressDays[progressDays.Count - 1]++;
            }
            else // 더해야함?
            {
                nowDay = progressDay;
                progressDays.Add(1);
            }
        }

        return progressDays.ToArray();
    }

    public int FindRemainingDays(int progress, int speed)
    {
        int remainProgress = 100 - progress;
        double day = System.Math.Ceiling((double)remainProgress / speed);

        return (int)day;
    }
}
