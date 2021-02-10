#include <iostream>
using namespace std;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

bool can_build_square(int side, int arr[], int index, int size){
    if(side+index>size){
        return false;
    }
    for(int i =index; i<index+side; i++) {
        if (arr[i] < side)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    bool matrix[n][n];
    bool transpose[n][n];
    // 0 is C, 1 is D

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char input;
            cin>>input;
            if(input=='C'){
                matrix[i][j] = 0;
                transpose[j][i] =0;
            }
            else{
                matrix[i][j] = 1;
                transpose[j][i] = 1;
            }
        }
    }

    int up[n];
    int left[n];

    for(int i=0; i<n; i++){
        up[i]= 0;
        left[i] =0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j])
                up[i]++;
            if(transpose[j][i])
                left[j]++;
        }
    }

    int largest_square_up =1;
    int largest_square_left =1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            if(can_build_square(i, up, j, n)) {
                if (largest_square_up < i)
                    largest_square_up = i;
            }
            if(can_build_square(i, left, j, n)){
                if(largest_square_left<i)
                    largest_square_left = i;
            }
        }
    }

    cout<<max(largest_square_up, largest_square_left);

    return 0;
}
