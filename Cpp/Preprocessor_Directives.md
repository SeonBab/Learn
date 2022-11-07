# 전처리기 지시문(Preprocessor Directives)

전처리기 지시문(Preprocessor Directives)은 코드에 #으로 시작해서 줄바꿈으로 끝나는 라인들을 말합니다 이 지시문은 구문과 다르게 ';'로 끝나지 않고 newline 문자가 있으면 끝나는 것으로 봅니다. 전처리 지시문이 한줄을 넘어가게 된다면 \를 입력하여 줄을 구분해주면 됩니다.

전처리기는 다음 지시문으로 분류된다.

+ 파일 처리를 위한 전처리문: #include
+ 형태 정의를 위한 전처리문: #define, #undef
+ 조건 처리를 위한 전처리문: #if, #ifdef, #ifndef, #else, #elif, #endif
+ 에러 처리를 위한 전처리문: #error
+ 디버깅을 위한 전처리문: #line
+ 컴파일 옵션 처리를 위한 전처리문: #pragram
