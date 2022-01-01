using System;
using System.Collections.Generic;

public class NumberAndNumberAlphabet 
{
    public int solution(string s) 
    {
        Dictionary<string, string> numberDic = CreateNumberDic();

        char[] seperatedText = s.ToCharArray();

        string numberingtext = string.Empty;
        string answerText = string.Empty;

        for (int i = 0; i < seperatedText.Length; i++)
        {
            if (numberDic.ContainsValue(seperatedText[i].ToString())) // 숫자일 때
            {                
                answerText += seperatedText[i].ToString();
            }
            else // 영어일 때
            {
                numberingtext += seperatedText[i].ToString();

                if (numberDic.ContainsKey(numberingtext))
                {
                    answerText += numberDic[numberingtext];
                    numberingtext = string.Empty;
                }
            }
        }

        int answer = Int32.Parse(answerText);
        
        return answer;
    }

    public Dictionary<string, string> CreateNumberDic()
    {
        Dictionary<string, string> dic = new Dictionary<string, string>();

        dic.Add("zero", "0");
        dic.Add("one", "1");
        dic.Add("two", "2");
        dic.Add("three", "3");
        dic.Add("four", "4");
        dic.Add("five", "5");
        dic.Add("six", "6");
        dic.Add("seven", "7");
        dic.Add("eight", "8");
        dic.Add("nine", "9");

        return dic;
    }
}