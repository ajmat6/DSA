vector<int> findLPS(string& pattern) {
    int n = pattern.size();
    vector<int> lps (n, 0);
    int prefix = 0;
    int suffix = 1;
    while(suffix < n) {
        if(pattern[prefix] == pattern[suffix]) {
            lps[suffix] = prefix + 1;
            prefix++; suffix++;
        }
        else {
            if(prefix == 0) {
                lps[suffix] = 0;
                suffix++;
            }
            else prefix = lps[prefix - 1];
        }
    }
    return lps;
}

vector<int> KMP(string& pattern, string& text) {
    vector<int> lps = findLPS(pattern);
    int i =  0, j = 0;
    vector<int> ans; // will store indexes from where pattern matches in text
    while(i < text.size()) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
            // if pattern matched:  this part is optional like if  you just need to check that if pattern is there in text or not, then you can return true from here you don't need ans array:
            if(j == pattern.size()) {
                j = lps[j - 1];
                ans.push_back(i - pattern.size());
            }
        }
        else {
            if(j == 0) i++;
            else j = lps[j - 1];
        }
    }
    return ans;
}