import os
import matplotlib.pyplot as plt  # 그래프를 그리기 위한 matplotlib 모듈
from matplotlib.patches import Arc

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

    fig, ax = plt.subplots(figsize=(8, 2.5))  # 그래프 크기 설정

    # 범위
    ax.set_xlim(-0.2, 1.2)  # x축 범위 설정
    ax.set_ylim(-0.3, 0.3)  # y축 범위 설정

    # 기본 선분
    ax.plot([0, 1], [0, 0], color='black', linewidth=3)  # 선의 색상과 두께 설정

    # 눈금
    ticks = [0, 0.25, 0.5, 0.75, 1]
    labels = ["0", "0.25", "0.5", "0.75", "1"]  # x축 눈금 레이블
    ax.set_xticks(ticks)  # x축 눈금 글자 크기 설정
    ax.set_xticklabels(labels, fontsize=12)  # x축 눈금 레이블 글자 크기 설정

    # y축 제거
    ax.set_yticks([])

    # 테두리 제거 (위, 오른쪽, 왼쪽)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.spines['left'].set_visible(False)

    # 아래 축을 y=0 위치로 이동
    ax.spines['bottom'].set_position(('data', 0))
    ax.spines['bottom'].set_linewidth(0)  # spines을 숨기고 plot 선 사용

    # 눈금 스타일
    ax.tick_params(axis='x', width=1, length=10)

    # 각 구간 위의 검은 반원호 + 숫자
    for i in range(4):
        x1 = ticks[i]
        x2 = ticks[i + 1]
        center_x = (x1 + x2) / 2

        # 검은 곡선
        arc = Arc(
            (center_x, 0.0),   # 중심점
            width=0.24,         # 가로 길이
            height=0.10,        # 세로 높이
            angle=0,
            theta1=0,
            theta2=180,
            color='black',
            linewidth=2.0
        )
        ax.add_patch(arc)

        # 숫자
        ax.text(
            center_x, 0.075, rf"$\frac{{{i + 1}}}{{4}}$",  # LaTeX 수식으로 분수 표현
            color='black',
            fontsize=16,
            ha='center',
            va='bottom'
        )


    # 이미지 파일로 저장
    plt.savefig(file_path)

    # 메모리 정리 (그래프 초기화)
    plt.close()


# 함수 실행 (그래프 저장)
save_graph()