import os

# 숫자 정의
digits = {
    '0': [
        " 000  ",
        "0   0 ",
        "0   0 ",
        "0   0 ",
        " 000  "
    ],
    '1': [
        "  1   ",
        " 11   ",
        "  1   ",
        "  1   ",
        "11111 "
    ],
    '2': [
        " 222  ",
        "2   2 ",
        "  2   ",
        " 2    ",
        "22222 "
    ],
    '3': [
        " 333  ",
        "    3 ",
        " 333  ",
        "    3 ",
        " 333  "
    ],
    '4': [
        "4  4  ",
        "4  4  ",
        "44444 ",
        "   4  ",
        "   4  "
    ],
    '5': [
        "55555 ",
        "5     ",
        "5555  ",
        "    5 ",
        "5555  "
    ],
    '6': [
        " 666  ",
        "6     ",
        "6666  ",
        "6   6 ",
        " 666  "
    ],
    '7': [
        "77777 ",
        "    7 ",
        "   7  ",
        "  7   ",
        " 7    "
    ],
    '8': [
        " 888  ",
        "8   8 ",
        " 888  ",
        "8   8 ",
        " 888  "
    ],
    '9': [
        " 9999 ",
        "9   9 ",
        " 9999 ",
        "    9 ",
        " 999  "
    ]
}

# 숫자 조합 함수
def combine_numbers(number):
    lines = [""] * 5
    for digit in str(number):
        for i, line in enumerate(digits[digit]):
            lines[i] += line + "  "
    return "\n".join(lines)

# 숫자를 number_list 폴더 안에 저장
def save_to_folder():
    folder_name = "number_list"
    os.makedirs(folder_name, exist_ok=True)  # 폴더 생성
    for i in range(10001):
        file_path = os.path.join(folder_name, f"{i}.txt")
        with open(file_path, "w", encoding="utf-8") as file:
            file.write(combine_numbers(i))

# 실행
save_to_folder()
