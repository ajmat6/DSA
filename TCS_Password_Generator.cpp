#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

// Function to get the scientific notation of a number
string scientificNotation(double number) {
    stringstream ss;
    ss << scientific << setprecision(9) << number;
    string sci_notation = ss.str();
    return sci_notation;
}

// Function to reduce a number to a single digit
int reduceToSingleDigit(int num) {
    if (num < 10) return num;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return reduceToSingleDigit(sum);
}

// Function to get the string S1
string getS1(string& sci_notation) {
    string s1;
    for (char c : sci_notation) {
        if (isdigit(c)) {
            string digit_words[] = {"zer", "one", "two", "thr", "for", "fiv", "six", "sev", "eig", "nin"};
            int digit = c - '0';
            s1 += digit_words[digit].substr(0, 3);
        } else if (c == 'e') {
            s1 += 'e';
        } else if (c == '+' || c == '-') {
            s1 += c;
        }
    }
    return s1;
}

// Function to get the string S2
string getS2(string& name, int power) {
    string s2;
    for (int i = 0; i < name.length(); i++) {
        if ((i + 1) % 2 == (power % 2)) {
            if (islower(name[i])) {
                s2 += name[i];
            } 
            else {
                return "";
            }
        }
    }
    return s2;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline after reading integer

    for (int t = 0; t < T; t++) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string num, name;

        ss >> num >> name;

        // Check if the name contains only lowercase letters
        bool valid_name = true;
        for (auto c : name) {
            if (!islower(c)) {
                valid_name = false;
                break;
            }
        }

        // Process the number and generate the password
        if (valid_name) 
        {
            double number = stod(num);
            string sci_notation = scientificNotation(number);
            int reduced_number = reduceToSingleDigit(number);
            int reduced_power = reduceToSingleDigit(static_cast<int>(sci_notation.back() - '0'));

            string S1 = getS1(sci_notation);
            string S2 = getS2(name, reduced_power);

            if (!S2.empty()) 
            {
                cout << S1 << "@" << S2 << std::endl;
            } 
            else 
            {
                cout << "Invalid" << std::endl;
            }
        } 
        
        else 
        {
            cout << "Invalid" << std::endl;
        }
    }

    return 0;
}
