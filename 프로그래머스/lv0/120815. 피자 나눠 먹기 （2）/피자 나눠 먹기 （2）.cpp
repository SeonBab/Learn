int solution(int n) {
    int answer{}, i{1};

    while (answer == 0)
    {
        ((6 * i) % n == 0) ? answer = i : ++i;
    }

    return answer;
}
