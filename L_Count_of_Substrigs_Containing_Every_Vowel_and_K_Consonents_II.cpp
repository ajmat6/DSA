// 4n time and constant space:
class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    void increaseVowel(char ch, vector<long long>& freq) {
        if(ch == 'a') freq[0]++;
        if(ch == 'e') freq[1]++;
        if(ch == 'i') freq[2]++;
        if(ch == 'o') freq[3]++;
        if(ch == 'u') freq[4]++;
    }

    void decreaseVowel(char ch, vector<long long>& freq) {
        if(ch == 'a') freq[0]--;
        if(ch == 'e') freq[1]--;
        if(ch == 'i') freq[2]--;
        if(ch == 'o') freq[3]--;
        if(ch == 'u') freq[4]--;
    }

    bool checkFullfilment(int con, vector<long long>& freq, int& k) {
        if(con < k) return false;
        for(auto i: freq) {
            if(i == 0) return false;
        }
        return true;
    }

    long long countSubstrings(string& word, int k) {
        long long ans = 0;
        int n = word.size();
        vector<long long> freq (5, 0);
        int con = 0, low = 0, high = 0;

        while(high < n) {
            if(!isVowel(word[high])) con++;
            else increaseVowel(word[high], freq);

            while(checkFullfilment(con, freq, k) && low <= high) {
                ans += (long long)(n - high);
                if(ans < 0) cout << high << endl;
                if(isVowel(word[low])) decreaseVowel(word[low], freq);
                else con--;
                low++;
            }

            high++;
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return countSubstrings(word, k) - countSubstrings(word, k + 1);
    }
};





// TC is 3n and space is n:
class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    void increaseVowel(char ch, vector<int>& freq) {
        if(ch == 'a') freq[0]++;
        if(ch == 'e') freq[1]++;
        if(ch == 'i') freq[2]++;
        if(ch == 'o') freq[3]++;
        if(ch == 'u') freq[4]++;
    }

    void decreaseVowel(char ch, vector<int>& freq) {
        if(ch == 'a') freq[0]--;
        if(ch == 'e') freq[1]--;
        if(ch == 'i') freq[2]--;
        if(ch == 'o') freq[3]--;
        if(ch == 'u') freq[4]--;
    }

    bool checkFullfilment(int con, vector<int>& freq, int& k) {
        if(con < k || con > k) return false;
        for(auto i: freq) {
            if(i == 0) return false;
        }
        return true;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> nextConso (n, n);
        for(int i=n-2; i>=0; i--) {
            if(!isVowel(word[i + 1])) nextConso[i] = i + 1;
            else nextConso[i] = nextConso[i + 1];
        }

        int con = 0;
        vector<int> freq (5, 0);
        int low = 0;
        int high = 0;
        long long ans = 0;

        while(high < n) {
            if(!isVowel(word[high])) con++;
            else increaseVowel(word[high], freq);

            while(con > k) {
                if(isVowel(word[low])) decreaseVowel(word[low], freq);
                else con--;
                low++;
            }

            while(checkFullfilment(con, freq, k)) {
                ans += (1 + nextConso[high] - high - 1);
                if(isVowel(word[low])) decreaseVowel(word[low], freq);
                else con--;
                low++;
            }

            high++;
        }
        return ans;
    }
};