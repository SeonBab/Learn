int solution(int angle) {
    int answer = (angle % 90 == 0) ? angle / 90 * 2 : angle / 90 * 2 + 1;
    
    return answer;
}