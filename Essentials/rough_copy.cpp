class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        bool answer = false;

        if (ransomNote.length() > magazine.length())
        {
            return false;
        }

        for (int r = 0; ransomNote[r] != '\0'; r++)
        {
            for (int m = 0; magazine[m] != '\0'; m++)
            {
                if (ransomNote[r] == magazine[m])
                {
                    // answer=true;
                    magazine[m] = '#';
                    break;
                }
            }
            if (answer == false)
            {
                return false;
            }
        }
        return answer;
    }
};