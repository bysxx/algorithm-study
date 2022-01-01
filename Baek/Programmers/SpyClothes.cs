using System;
using System.Linq;
using System.Collections.Generic;

public class SpyClothes 
{
    public int solution(string[,] clothes) // 0: 이름, 1: 종류
    {
        Dictionary<string, int> clothDic = new Dictionary<string, int>();

        for (int i = 0; i < clothes.GetLength(0); i++)
        {
            if (clothDic.ContainsKey(clothes[i, 1]) == true) // 이미 있으면
            {
                clothDic[clothes[i, 1]]++;
            }
            else // 없으면
            {
                clothDic.Add(clothes[i, 1], 1);
            }
        }

        int result = 1;

        foreach (var item in clothDic)
        {
            result *= (item.Value + 1); // 안 입는 Case 추가
        }
        
        return result - 1; // 전부 벗는 Case 제거
    }
}