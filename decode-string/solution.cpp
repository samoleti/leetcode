class Solution {
public:
    struct StringFrequency {
    private:
        int frequency;
        string s;
    public:
        StringFrequency(int frequency) 
        {
            this->frequency = frequency;
            this->s = "";
        }
        string getWholeAddition()
        {
            string result = "";
            while(frequency > 0)
            {
                result += s;
                frequency--;
            }
            return result;
        }
        void append(string addition)
        {
            s += addition;
        }
    };
    string decodeString(string s) {
        vector<StringFrequency> string_stack;
        string_stack.push_back(StringFrequency(1));
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '1' && s[i] <= '9')
            {
                int frequency = (int) s[i] - (int) '0';
                int j = i + 1;
                while(s[j] >= '0' && s[j] <= '9')
                {
                    frequency = frequency * 10 + ((int) s[j] - '0');
                    j++;
                }
                i = j;
                string_stack.push_back(StringFrequency(frequency));
            }
            if(s[i] == ']')
            {
                string whole_addition = string_stack.back().getWholeAddition();
                string_stack.pop_back();
                string_stack.back().append(whole_addition);
            }
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                string_stack.back().append(string{s[i]});
            }
        }
        return string_stack[0].getWholeAddition();
    }
};