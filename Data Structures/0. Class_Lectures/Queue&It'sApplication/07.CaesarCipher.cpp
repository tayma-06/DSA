#include <bits/stdc++.h>
using namespace std;

char shiftChar(char ch, int shift)
{
    if (islower(ch))
    {
        return char((ch - 'a' + shift + 26) % 26 + 'a');
    }
    else if (isupper(ch))
    {
        return char((ch - 'A' + shift + 26) % 26 + 'A');
    }
    else
    {
        return ch;
    }
}

string caesarCipher(string text, int shift)
{
    queue<char> q;
    for (char c : text)
    {
        q.push(c);
    }
    string encrypted = "";
    while (!q.empty())
    {
        char c = q.front();
        q.pop();
        encrypted += shiftChar(c, shift);
    }
    return encrypted;
}

int main()
{
    string text;
    int shift;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;
    string encrypted = caesarCipher(text, shift);
    cout << "Encrypted Text: " << encrypted << endl;
    string decrypted = caesarCipher(encrypted, -shift);
    cout << "Decrypted Text: " << decrypted << endl;
    return 0;
}
