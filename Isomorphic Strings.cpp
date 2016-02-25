bool isIsomorphic(string s, string t)
{
    unordered_map<char, int> record;
    for (int i = 0; i < s.size(); i++)
    {
        if (record.find(s[i]) != record.end())
        {
            int index = record[s[i]];
            if (t[i] != t[index])
            {
                return false;
            }
            record[s[i]] = i;
        }
        else
        {
            record[s[i]] = i;
        }
    }

    record.clear();
    for (int i = 0; i < t.size(); i++)
    {
        if (record.find(t[i]) != record.end())
        {
            int index = record[t[i]];
            if (s[i] != s[index])
            {
                return false;
            }
            record[t[i]] = i;
        }
        else
        {
            record[t[i]] = i;
        }
    }

    return true;
}
