#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int amount;
    scanf("%d", &amount);

    vector <int> min_notes(amount + 1, 0);

    for(int i = 1; i <= amount; i++)
    {
        min_notes[i] = 1 + min_notes[i - 1];

        for(int power = 6; power <= i; power *= 6)
            min_notes[i] = min(min_notes[i], 1 + min_notes[i - power]);

        for(int power = 9; power <= i; power *= 9)
            min_notes[i] = min(min_notes[i], 1 + min_notes[i - power]);
    }

    printf("%d\n", min_notes[amount]);
    return 0;
}
