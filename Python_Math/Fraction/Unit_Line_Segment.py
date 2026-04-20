import os
import matplotlib.pyplot as plt  # 그래프를 그리기 위한 matplotlib 모듈

# 현재 파일이 있는 폴더 경로
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

# output 폴더를 "이 파일 위치 기준"으로 설정
OUTPUT_DIR = os.path.join(BASE_DIR, "output")

def save_graph():
    # 출력 폴더가 없으면 생성
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    # 파일 이름만 추출
    script_name = os.path.basename(__file__)

    # 확장자 제거 + .png 붙이기
    filename = os.path.splitext(script_name)[0] + ".png"

    # 전체 경로 생성 (폴더 + 파일 이름)
    file_path = os.path.join(OUTPUT_DIR, filename)

    # 데이터 정의 (예시 데이터)
    x = [0, 1]   # 길이 1
    y = [0, 0]   # 같은 y → 가로선

    plt.plot(x, y, color='black', linewidth=3)  # 선의 색상과 두께 설정

    plt.xlim(-0.2, 1.2)  # x축 범위 설정
    plt.ylim(-0.3, 0.3)  # y축 범위 설정

    # x축 눈금 (0, 1만)
    plt.xticks([0, 1])
    plt.xticks(fontsize=12)  # x축 눈금 글자 크기 설정

    # y축 제거
    plt.yticks([])

    # 테두리 제거 (위, 오른쪽, 왼쪽)
    ax = plt.gca()
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['left'].set_visible(False)
    

    ax.spines['bottom'].set_position(('data', 0))
    ax.spines['bottom'].set_linewidth(3)  # x축 선의 두께 설정

    ax.tick_params(axis='x', width=1, length=10)  # x축 눈금의 두께와 길이 설정

    # 이미지 파일로 저장
    plt.savefig(file_path)

    # 메모리 정리 (그래프 초기화)
    plt.close()


# 함수 실행 (그래프 저장)
save_graph()