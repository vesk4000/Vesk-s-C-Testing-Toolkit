#include <iostream>
#include <string>

using namespace std;

string s;
string ans;
bool even;

void addOne();
void makePalindrome();

int main()
{
    cin >> s;
    ans = s;
    makePalindrome();
    if(ans <= s)
    {
        addOne();
        makePalindrome();
    }

    cout << ans << endl;

    return 0;
}

///makePalindrome()
void makePalindrome()
{
    for(int i = 0;i < ans.size() / 2; ++i)
        ans[ans.size() - i - 1] = ans[i];
}

///addOne()
void addOne()
{
    int i = (ans.size() + 1) / 2 - 1;///if the size is even adding one wouldn't change the result but if it is odd it will add one
    while(i >= 0)
    {
        if(ans[i] == '9')///then we will have to continue adding
        {
            ans[i] = '0';///we set the digit to 0
            i--;///decrease i to continue with the other digits
        }
        else///then we just have to add 1
        {
            ++ans[i];///add one to the digit
            return;///we don't have to continue because we add just one to the number
        }
    }
}
