#include <iostream>
#include <string>
#include <vector>

using namespace std;

int current_idx = 0;
int total_tokens = 0;
vector<string> tokens;
bool error_found = false;

void solve_recursive() {
    if (current_idx >= total_tokens) {
        error_found = true;
        return;
    }

    string type = tokens[current_idx++];

    if (type == "int") {
        cout << "int";
    } else if (type == "pair") {
        cout << "pair<";
        solve_recursive();
        cout << ",";
        solve_recursive();
        cout << ">";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string word;
    while (cin >> word) {
        tokens.push_back(word);
    }
    total_tokens = tokens.size();
    string final_result = "";
    current_idx = 0;
    if (total_tokens != 2 * n - 1) {
        cout << "Error occurred" << endl;
        return 0;
    }

    auto parse_to_string = [&](auto self) -> void {
        if (current_idx >= total_tokens) {
            error_found = true;
            return;
        }
        string t = tokens[current_idx++];
        if (t == "int") {
            final_result += "int";
        } else {
            final_result += "pair<";
            self(self);
            final_result += ",";
            self(self);
            final_result += ">";
        }
    };

    parse_to_string(parse_to_string);

    if (error_found || current_idx != total_tokens) {
        cout << "Error occurred" << endl;
    } else {
        cout << final_result << endl;
    }

    return 0;
}
