#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    int step = 0;
    void towerOfHanoi(int n, int from_rod,
                    int to_rod, int aux_rod) 
    { 
        if (n == 1) 
        { 
            cout << "move disk 1 from rod " << from_rod << 
                                " to rod " << to_rod<<endl;
            
            step++;
            return; 
        } 
        towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
        cout << "move disk " << n << " from rod " << from_rod <<
                                    " to rod " << to_rod << endl; 
        step++;
        towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
    } 
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        towerOfHanoi(N,from,to,aux);
        return step;
    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}
