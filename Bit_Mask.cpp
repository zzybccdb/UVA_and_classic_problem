/*
    本题的注意事项，这一题的 N 是一个 unsign 的32位的数字.
    因此在型别的选择上，可以选择 unsigned int 或者是 long long int 才可以满足题目需求。
    sample
        input :
            100 50 60
            100 50 50
            100 0 100
            1 0 100
            15 1 15
        output:
            59
            50
            27
            100
            1
*/
#include<iostream>
using namespace std;
int main(){
    unsigned int N, L, U;
    while(cin>>N>>L>>U){
        unsigned int temp = N;
        unsigned int mask10;
		mask10 = 0;
        // 這裡 N >> 4 指的是獲取第四位上的2進制, 在10进位的思考下可以思考成除以2^4;
        // cout << (N >> 4)<< endl; 
        // 相对应的 N << 4 值得是将数字后面补上4个0，在10进位的思考中就可以理解为乘以2^4;
        // cout << (N << 4) << endl;
        // 第一步我们要考虑的是从最大的位数开始mask，依次递减。
        // 例如 N=1;上面的两个输出就会是 0 和 16;
        for(int i=31; i>=0; i--){
            // 这一步可以理解为，每次给定一个 temp，
            // temp 是来自于 mask10 和 一个在第 i 位为 1 的数做 Bitwise 的 or。
            temp = mask10 | (1u << i);
            // 如果 N 在第 i 位为 0， 那么很自然的我们希望它最大的情况下，mask 的第 i 位要为 1
            // 前提条件是 mask <= U
            // 这里有个小技巧，就是 N >> i & 1， 可以想象为 N 的第 i+1 位是否为 0
            // 因为 bitwise & 只有全为 1 时， 结果才是 1；
            // 在这个状态下，我们可以得到一个让 N  | M 最大的，小于等于 U 的最小的 mask；
            if((((N>>i) & 1) == 0) && (temp <= U)){
                mask10 = temp;
            }
            // 这样就会错过一个条件，M >= L; 例如在 100，50，60的 case 中， m = 27， 而不是 59
            // 为了解决这个问题，我们需要把 L 考虑进来
            // 可以这样思考，因为我们是从最高位往下算，所以当 第 i 位 第一次出现 1 的时候，
            // 如果此刻的mask 是小於 L的，我们不能因为 N 的第 i 位为 1 就舍弃它，要把它留下来，不然 mask 就一定会小于 L
            // 但是这样有一个漏洞，就是在这里避开了 mask 要小于 U 的限制， 因为 只要 L 的这一位有 1，
            // mask 就会变为 mask | 1u << i; 
            // 这也就意味着，只有 mask < L 的时候才能执行，mask >= L 都不能执行
            // 例如：3，10，20 如果不给限制就会得到 24；
            if(((L>>i) & 1) && mask10 < L){
                mask10 = temp;
            }

        }
        cout << mask10 << endl;
    }
}