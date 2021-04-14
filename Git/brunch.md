terminal에서 폴더를 돌아다니다보면 git의 brunch가 변하는 것을 볼 수 있다. remote 할 때 origin을 어느 브런치로 지정하였는지에 따라 현재(default) brunch 이름이 바뀐다.

```zsh
TIA_main [main] git status
```
```
현재 브랜치 main
브랜치가 'origin/main'에 맞게 업데이트된 상태입니다.

커밋할 사항 없음, 작업 폴더 깨끗함
```

```zsh
TIA_main [main] cd ..
TIA [master] git status
```
```
현재 브랜치 master
브랜치가 'origin/main'에 맞게 업데이트된 상태입니다.

커밋할 사항 없음, 작업 폴더 깨끗함
```


현재 브런치와 Github Repository의 브런치가 일치하지 않는다면 ```git push```가 불가능하다. 
이 때는 아래와 같이 브런치를 변경해주어야 한다.

```zsh
TIA [master] git checkout main
TIA [main]
```
```
'master' 브랜치가 리모트의 'master' 브랜치를 ('origin'에서) 따라가도록 설정되었습니다.
새로 만든 'master' 브랜치로 전환합니다
```

```checkout```이라는 표현 때문에 조금 헷갈릴 수 있다. 현재 브런치 ```master```를 checkout -> ```main```으로 떠난다고 생각하면 이해가 쉽다.
