void solve(int ind, string s, string temp, vector<string> &ans, vector<string> dict)
{

    if (ind == s.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        string str = s.substr(ind, i - ind + 1);

        auto it = find(dict.begin(), dict.end(), str);

        if (it != dict.end())
        {
            solve(i + 1, s, temp + str + ' ', ans, dict);
        }
    }
}

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{

    vector<string> ans;
    string temp;

    solve(0, s, temp, ans, dict);
    
    return ans;
}