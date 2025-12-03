#include <iostream>
#include <stack>
using namespace std;

struct HanoiState { int n; char src, dest, aux; int state; };

void hanoiStack(int n, char src, char dest, char aux) {
    stack<HanoiState> st;
    st.push({n, src, dest, aux, 0});
    long long moves = 0;
    
    while (!st.empty()) {
        HanoiState top = st.top();
        if (top.n == 1) {
            cout << "Move disk 1 from " << top.src << " to " << top.dest << "\n";
            ++moves;
            st.pop();
        } else if (top.state == 0) {
            st.top().state = 1;
            st.push({top.n-1, top.src, top.aux, top.dest, 0});
        } else if (top.state == 1) {
            st.top().state = 2;
            cout << "Move disk " << top.n << " from " << top.src << " to " << top.dest << "\n";
            ++moves;
        } else {
            st.pop();
            if (!st.empty()) st.push({top.n-1, top.aux, top.dest, top.src, 0});
            else st.push({top.n-1, top.aux, top.dest, top.src, 0});
        }
    }
    cout << "Total moves: " << moves << "\n";
}

int main() {
    hanoiStack(3, 'A', 'C', 'B');
    return 0;
}