## 리눅스 명령어 | touch vs mkdir
1. touch - 파일 생성
2. mkdir - 디렉토리 생성, 깃이 추적하지 않음
---

### 1. touch
```zsh
touch temp.md # 파일(.확장자) 생성
```

### 2. mkdir

- git이 추적하지 않는다.
```zsh
mkdir temp # 경로(폴더) 생성
```

```zsh
# git 상태를 찍어보면 아래와 같이 출력
git status
```

```
현재 브랜치 main
브랜치가 'origin/main'에 맞게 업데이트된 상태입니다.

커밋할 사항 없음, 작업 폴더 깨끗함
```

