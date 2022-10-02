#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool dictionaryContains(string word, vector<string> &B){
    
    if(find(B.begin(), B.end(), word) != B.end())
        return true;
    
    return false;
}

bool wordBreak(string S, vector<string> &B){

    int n = S.length();

    vector<bool> w(n + 1, false);

    for(int i = 1; i <= n; i++){

        if(w[i] == false and dictionaryContains(S.substr(0, i), B))
            w[i] = true;
        

        if(w[i] == true){

            if(i == n)
                return true;

            for(int j = i + 1; j <= n; j++){

                if(w[j] == false and dictionaryContains(S.substr(i, j - i), B))
                    w[j] = true;

                if(j == n and w[j] == true)
                    return true;
            }
        }

    }

    return false;

}

int main(void){

    vector<string> B = { "i", "like", "sam", "sung", "samsung", "mobile", "ice","cream", "icecream", "man", "go", "mango"};
    string A = "ilike";

    cout << wordBreak(A, B) << endl;
    A = "ilikesamsung";
    cout << wordBreak(A, B) << endl;

    return 0;
}