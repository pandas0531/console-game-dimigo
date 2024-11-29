# 🎮 C언어 프로그래밍 - Console Game (홀짝게임)

> **개발 기간**: 2024.10.18 ~  
> **주요 내용**: Console 환경에서 동작하는 간단한 홀짝 게임입니다.  
> - Windows 및 Linux 환경 모두 지원합니다.  
> - WSL과 Python exploit 기능을 활용한 테스트 가능.  
> - random crack을 활용한 CTF 문제로도 활용 가능
---

## 📝 사용 시 참고사항

1. **Welcome Banner 깨짐 현상**  
   - Welcome 글자가 깨진다면 **화면 크기를 키우고, 글자 크기를 줄여주세요**.  

2. **개발 도구**  
   - `vim`과 `Visual Studio Code`로 개발하였습니다.  
   - **Dev C++**에서도 정상 작동 확인했습니다.  

3. **Linux 지원**  
   - WSL에서 `gcc`로 컴파일한 ELF 파일 첨부.  
   - Linux 환경에서도 실행 가능합니다.  

---

## 💻 실행 방법

### Windows에서 실행
- 프로젝트를 다운로드한 후 `main.exe` 실행.
- 혹은 Linux 환경에서 `ELF`파일 실행.

### Linux에서 실행
1. 압축을 해제한 폴더로 이동.
2. 다음 명령어로 실행:
   ```bash
   ./linux_main
   ```
---

## 🐍 Exploit 기능 사용

### Exploit 기능 사용 (Linux)
1. **Python과 pwntools 설치 방법**
- 아래 명령어를 순서대로 실행하여 설치합니다:

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install python3 python3-pip -y
pip3 install pwntools
```

2. **Exploit 실행 방법**
- 설치 완료시 아래 명령어로 실행합니다

```bash
python3 exploit.py
```
정상적으로 작동하면 exploit.py 스크립트를 통해 프로그램 테스트가 가능합니다.

---

## 📂 파일 구성
```bash
project-folder/
│
├── linux_main          # Linux 실행 파일 (ELF)
├── main.exe            # Windows 실행 파일
├── exploit.py          # Python Exploit 스크립트
├── txt_list/           # 게임에 필요한 텍스트 파일
│   ├── welcome.txt
│   ├── goal.txt
│   ├── correct.txt
│   ├── nope.txt
│   └── flag.txt
├── number_list/        # 점수별 숫자 파일
│   ├── 1.txt
│   ├── 2.txt
│   ├── 4.txt
│   └── ... (2의 n 제곱)
└── README.md           # 설명 파일
```

--- 

## ✨ 주의사항
+ Linux에서 실행 시 Python과 pwntools 설치가 필수입니다.
+ 터미널 창에서 입력이 깨질 경우, 터미널 창 크기를 조정하세요.
+ Python 버전은 3.7 이상을 권장합니다.


```written by 1309 김준원. 2024. 11. 29```