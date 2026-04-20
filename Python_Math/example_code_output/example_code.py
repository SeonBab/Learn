import os
import matplotlib.pyplot as plt  # 그래프를 그리기 위한 matplotlib 모듈

# 출력 폴더 설정
OUTPUT_DIR = "output"


def save_graph(filename):
    """
    그래프를 생성하고 파일로 저장하는 함수
    :param filename: 저장할 파일 이름 (ex: graph.png)
    """

    # 출력 폴더가 없으면 생성
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    # 전체 경로 생성 (폴더 + 파일 이름)
    file_path = os.path.join(OUTPUT_DIR, filename)

    # 데이터 정의 (예시 데이터)
    x = [1, 2, 3, 4]
    y = [10, 20, 15, 30]

    # 그래프 생성
    plt.plot(x, y)

    # 이미지 파일로 저장
    plt.savefig(file_path)

    # 메모리 정리 (그래프 초기화)
    plt.close()


# 함수 실행 (그래프 저장)
save_graph("example_code_output.png")