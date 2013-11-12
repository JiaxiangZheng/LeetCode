/*
 * 
 */

int main() {
    std::vector<int> A;
    int N; scanf("%d", &N); A.resize(N);
    int average = 0;
    for (int i=0; i<N; ++i) {
        scanf("%d", &A[i]);
        average += A[i];
    }
    average /= N;

    std::vector<int> Y(N, 0);
    for (int i=1; i<N; ++i) {
        Y[i] = Y[i-1] + A[i] - i*average;
    }
}
