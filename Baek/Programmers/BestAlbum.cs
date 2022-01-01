using System;
using System.Linq;
using System.Collections.Generic;

public class BestAlbum 
{
    public class AlbumBook
    {
        public Dictionary<int, int> albums = new Dictionary<int, int>(); // index, plays
        public int totalPlays = 0;

        public void AddAlbum(int index, int plays)
        {
            totalPlays += plays;
            albums.Add(index, plays);
        }

        public void GetAlbumIndexes(List<int> albumIndexs)
        {
            var queryDesc = albums.OrderByDescending(x => x.Value);
            int count = 0;
            
            foreach (var item in queryDesc)
            {
                albumIndexs.Add(item.Key);

                if (++count == 2)
                {
                    break;
                }
            }
        }
    }

    public int[] solution(string[] genres, int[] plays)
    {
        Dictionary<string, AlbumBook> musicDic = new Dictionary<string, AlbumBook>();

        for (int i = 0; i < genres.Length; i++)
        {
            if (musicDic.ContainsKey(genres[i]))
            {
                musicDic[genres[i]].AddAlbum(i, plays[i]);
            }
            else
            {
                AlbumBook book = new AlbumBook();

                book.AddAlbum(i, plays[i]);
                musicDic.Add(genres[i], book);
            }
        }

        var queryDesc = musicDic.OrderByDescending(x => x.Value.totalPlays);

        List<int> albumIndexs = new List<int>();

        foreach (var item in queryDesc)
        {
            item.Value.GetAlbumIndexes(albumIndexs);
        }

        return albumIndexs.ToArray();
    }
}

