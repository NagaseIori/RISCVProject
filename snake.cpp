#include<bits/stdc++.h>
using namespace std;

int Next[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int dir = 0, head = 0, tail = 0;
const int N = 1 << 10, a = 17, b = 13;
int snakex[1 << 10] = {16}, snakey[1 << 10] = {16}, foodx = 10, foody = 5, score = 0, foodstatus = 1;
unsigned int vis[1 << 10];
int main()
{
    vis[16] = 1u << 16;
    while (1)
    {
        int newhead = (head + 1) % N;
        snakex[newhead] = snakex[head] + Next[dir][0];
        snakey[newhead] = snakey[head] + Next[dir][1];
        head = newhead;
        if (snakex[head] < 0 || snakex[head] >= 32 || snakey[head] < 0 || snakey[head] >= 32)
            break;
        else if (snakex[head] == foodx && snakey[head] == foody)
        {
            unsigned int flag = (vis[snakex[head]] >> snakey[head]) & 1;
            if (flag)
                break;
            vis[snakex[head]] |= 1u << snakey[head];
            foodx = (foodx * a + b) % 32;
            foody = (foody * a + b) % 32;
            ++score;
            foodstatus = 1;
        }
        else
        {
            vis[snakex[tail]] ^= 1u << snakey[tail];
            tail = (tail + 1) % N;
            unsigned int flag = (vis[snakex[head]] >> snakey[head]) & 1;
            if (flag)
                break;
            vis[snakex[head]] |= 1u << snakey[head];
            foodstatus ^= 1;
        }
        for(int i = 0;i < 32;i++)
        {
            cout<<(bitset<32>(vis[i]))<<endl;
        }
        cout<<endl;
    }
    dir = 1919810;
    return 0;
}
